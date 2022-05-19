
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
public class strlec{
	public static void main(String[] args){
		String vir = "";
		try {
			vir = new String(Files.readAllBytes(Paths.get("vir")));
		} catch (Exception e) {}
		branje(vir);
	}
	static String krog(double r, int d){
		//r = Math.round(r*potenca)/potenca;
		double ploscina = Math.PI*r*r;
		double obseg = 2*Math.PI*r;
		if (r<0){
			System.out.println("Napaka: negativen polmer");
		}else if(d<0){
			System.out.println("Napaka: negativen d");
		}else{
			System.out.print(String.format("Obseg kroga s polmerom r=%." + 2 + "f je %." + d + "f\n",r,obseg));
			System.out.print(String.format("Ploscina kroga s polmerom r=%." + 2 + "f je %." + d + "f\n",r,ploscina));
		}
		float steviloMinut = 0;
		float steviloSekund = 0;
		float steviloUr= 0;

		String izhod = String.format("%.0f:%.0f:%.0f", steviloUr,steviloMinut,steviloSekund);
		return izhod;
	}
	static String pretvor(int sekunde){
		if(sekunde < 0){
			return "";
		}else{
			float steviloMinut = 0;
			float steviloSekund = 0;
			float steviloUr= 0;
			

			/*
				TVOJE PRETVORBE V UR MINUTE SEKUNDE
			*/
			String steviloUrS = "00";
			String steviloMinutS = "00";
			String steviloSekundS = "00";

			if(steviloSekund < 10){
				if(steviloSekund != 0){
					steviloSekundS = String.format("0%.0f",steviloSekund);
				}
			}
			if(steviloMinut < 10){
				if(steviloMinut != 0){
					steviloMinutS = String.format("0%.0f",steviloMinut);
				}
			}
			if(steviloUr < 10){
				if(steviloUr != 0){
					steviloUrS = String.format("0%.0f",steviloUr);
				}
			}

			String izhod = String.format("%s:%s:%s",steviloUrS,steviloMinutS,steviloSekundS);
			return izhod;
		}
		
	}
	static void presledek(int n){
		int stZnakov = n;
		String presledki = "";
		for(int i = 0;i<n;i++){
			System.out.printf("%s",presledki);
			for(int j = 1;j<=stZnakov;j++){
				System.out.printf("%d ",j);
			}
			stZnakov--;
			presledki = " ".repeat(2*(n-stZnakov));
			System.out.println();
		}
	}
	static void dvojiski(){
		// String dvojiski = args[0];
		// int crka;
		// char znak;
		// String izpis = "";
		// if(dvojiski.length()%8==0){
		// 	for (int i = 0;i < dvojiski.length();i+=8){
		// 		int sum = 0;
		// 		for(int j = 0;j<8;j++){
		// 			crka = Integer.parseInt(String.valueOf(dvojiski.charAt(i+j)));
		// 			sum += crka * Math.pow(2,7-j);
		// 		}
		// 		znak = (char)sum;
		// 		izpis = izpis.concat(String.valueOf(znak));
		// 	}
		// }
		// System.out.println(izpis);
	}
	static void sorodna(String niz){
		int bsdNiza = bsdChecksum(niz);
		String iskaniNiz = ustvariNiz("",niz.length());
		int bsdIskanegaNiz = bsdChecksum(iskaniNiz);
		while(bsdNiza!=bsdIskanegaNiz){
			iskaniNiz = povecaj(iskaniNiz);
			bsdIskanegaNiz = bsdChecksum(iskaniNiz);
		}
		System.out.println(iskaniNiz);
	}
	static String ustvariNiz(String nizIN,int n){
		String niz = nizIN;
		for(int i = 0;i<n;i++){
			niz = niz.concat("a");
		}
		return niz;
	}
	static int bsdChecksum(String niz){
		int checksum = 0;
		for (int i = 0;i<niz.length();i++){
			checksum = (checksum>>1)+((checksum & 1 )<<15);
			checksum += niz.charAt(i);
			checksum &= 0xffff;
		}
		return checksum;
	}
	static String povecaj(String niz){
		char[] novNiz = niz.toCharArray();
		int zadnji = novNiz[novNiz.length-1];
		if(zadnji == 122){
			String ret = povecaj(niz.substring(0, novNiz.length-1));
			for(int i = 0;i<ret.length();i++){
				novNiz[i] = ret.charAt(i);
			}
			novNiz[novNiz.length-1] = 'a';
		}else{
			novNiz[novNiz.length-1] = (char)(zadnji+1);
		}
		return String.valueOf(novNiz);
	}
	static int[] range(int a, int b, int c){
		int stEle = (int)Math.ceil((b-a)/(double)c);
		int[] tabela = new int[stEle];
		for (int j = 0;a<b;a+=c,j++){
			tabela[j] = a;
		}
		return tabela;
	}
	static void branje(String vir){
		Scanner vhod = new Scanner(vir);
		int stTekmovalcev = Integer.parseInt(vhod.nextLine());
		String tekmovalci[][] = new String[stTekmovalcev][5];
		int tipPodatka = 0;
		int povrsti = 0;
		while(vhod.hasNext()){
			String podatek = vhod.nextLine();
			if(povrsti > stTekmovalcev)break;
			if(!podatek.equals("")){
				tekmovalci[povrsti-1][tipPodatka] = podatek;
				tipPodatka++;
			}else{
				povrsti++;
				tipPodatka = 0;
			}
		}
		for (int i = 0;i<povrsti;i++){
			for (int j = 0;j<5;j++){
				System.out.print(tekmovalci[i][j] + " | ");
			}
			System.out.println("\n-------------------------------------------------");
		}
		vhod.close();
	}
}

