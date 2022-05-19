import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.String;

import static java.lang.Double.parseDouble;

public class DN08 {

    // podatki o letalnici
    private static final int K_POINT = 200;            // K-točka letalnice
    private static final int FLYING_HILL_POINTS = 120; // število točk za doseženo K-točko
    private static final double METER_VALUE = 1.2;     // faktor za dodatne točke za vsak meter pod/nad K-točko

    // podatki o tekmovalcih
    private static String[][] tekmovalci; // podatki o posameznem tekmovalcu; prva dimenzija so tekmovalci, druga različni podatki enega tekmovalca
    private static double[][] daljave;    // daljava prve (0) in druge (1) serije; prva dimenzija so tekmovalci, druga serija
    private static double[][][] ocene;    // ocene prve (0) in druge (1) serije od vseh 5 sodnikov; prva dimenzija so tekmovalci, druga serija, tretja sodniki
    private static double[][] komp_nalet; // kompenzacijske točke za nalet v prvi (0) in drugi (1) seriji; prva dimenzija so tekmovalci, druga serija
    private static double[][] komp_veter; // kompenzacijske točke za veter v prvi (0) in drugi (1) seriji; prva dimenzija so tekmovalci, druga serija
    private static double[][] tocke;      // seštevek doseženih točk v seriji; prva dimenzija so tekmovalci, druga serija: prva (0), druga (1), obe skupaj (2)


    static void branje(String vir) throws FileNotFoundException {
        File dokument = new File(vir);
        Scanner vhod = new Scanner(dokument);
        int stTekmovalcev = Integer.parseInt(vhod.nextLine());

        int tipPodatka = 0;
        int povrsti = 0;
        tekmovalci = new String[stTekmovalcev][stTekmovalcev];

        while (vhod.hasNextLine()) {
            String podatek = vhod.nextLine();
            if (povrsti > stTekmovalcev) break;
            if (!podatek.equals("")) {
                tekmovalci[povrsti - 1][tipPodatka] = podatek;
                tipPodatka++;
            } else {
                povrsti++;
                tipPodatka = 0;
            }
        }
        vhod.close();
    }

    static void izpis1() {
        System.out.print("Start List 1st Round:\n");
        System.out.println("BIB NAME                      (NSA)  [DATE OF BIRTH, CLUB]");
        for (int i = 0; i < tekmovalci.length; i++) {
            System.out.printf(" %2s %s %s(%s)  [%s, %s]\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()), tekmovalci[i][4], tekmovalci[i][3], tekmovalci[i][2]);
        }
    }

    static void branjeRezultatov(String vir) throws FileNotFoundException {
        File dokument = new File(vir);
        Scanner vhod = new Scanner(dokument);
        String prvaVrstica = vhod.nextLine(); // BIB--0;SPEED [km/h]--1;DISTANCE--2;GATE--3;točke za nalet--4;[m/s]--5;točke za veter--6
        String vrstica;

        daljave = new double[40][2];
        komp_nalet = new double[40][2];
        komp_veter = new double[40][2];
        int i = 0;
        while (vhod.hasNextLine()) {
            vrstica = vhod.nextLine();


            int skakalec = Integer.parseInt((vrstica.split(";"))[0]);

            if (vrstica.split(";")[1].equals("DSQ")) {

            } else {
                daljave[skakalec - 1][0] = Double.parseDouble(vrstica.split(";")[2]);


                if (vrstica.split(";")[4].equals("")) {
                    komp_veter[skakalec - 1][0] = Double.parseDouble(vrstica.split(";")[6]);
                    komp_nalet[skakalec - 1][0] = 0.0;

                } else {
                    komp_veter[skakalec - 1][0] = Double.parseDouble(vrstica.split(";")[6]);
                    komp_nalet[skakalec - 1][0] = Double.parseDouble(vrstica.split(";")[4]);

                }

            }

        }

        vhod.close();
    }

    static void izpis2() {
        System.out.print("Results first round:\n");
        System.out.println("BIB NAME                      (NSA)  [DATE OF BIRTH, CLUB]                          DISTANCE [m]");
        for (int i = 0; i < daljave.length; i++) {
            String skok = String.valueOf(daljave[i][0]);
            skok = skok.replace(",", ".");
            System.out.printf(" %2s %s %s(%s)  [%s, %s]%s%s\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()), tekmovalci[i][4], tekmovalci[i][3], tekmovalci[i][2], " ".repeat(46 - (tekmovalci[i][2].length() + tekmovalci[i][3].length() + 4)), skok);
        }
    }

    static void branjeRezultatov2(String vir) throws FileNotFoundException {
        File dokument = new File(vir);
        Scanner vhod = new Scanner(dokument);
        String prvaVrstica = vhod.nextLine(); // BIB--0;SPEED [km/h]--1;DISTANCE--2;GATE--3;točke za nalet--4;[m/s]--5;točke za veter--6
        String vrstica;
        int serija = 1;

        while (vhod.hasNextLine()) {
            vrstica = vhod.nextLine();

            int skakalec = Integer.parseInt((vrstica.split(";"))[0]);

            if (vrstica.split(";")[1].equals("DSQ")) {
                daljave[skakalec - 1][serija] = -1.0;
            } else {
                daljave[skakalec - 1][serija] = parseDouble((vrstica.split(";")[2]));
                komp_veter[skakalec - 1][serija] = parseDouble((vrstica.split(";")[5]));
                if (vrstica.split(";")[4].equals("")) {
                    komp_nalet[skakalec - 1][serija] = 0;
                } else {
                    komp_nalet[skakalec - 1][serija] = Double.parseDouble((vrstica.split(";")[4]));
                }
            }
        }
        vhod.close();
    }

    public static void izpis3() {
        System.out.println("Results final round:");
        System.out.println("BIB NAME                      (NSA)  [DATE OF BIRTH, CLUB]                          DISTANCE [m]  (DISTANCE [m])");
        for (int i = 0; i < 40; i++) {
            String str = String.valueOf(daljave[i][1]);
            if (daljave[i][1] < 0.0) {
                String skok = String.valueOf(daljave[i][0]);
                skok = skok.replace(",", ".");
                System.out.printf(" %2s %s %s(%s)  [%s, %s]%s Disqualified  (%s)\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()),
                        tekmovalci[i][4], tekmovalci[i][3], tekmovalci[i][2], " ".repeat(46 - (tekmovalci[i][2].length() + tekmovalci[i][3].length() + 4)), skok);
            } else if (str.equals("0.0")) {
                String skok = String.valueOf(daljave[i][0]);
                skok = skok.replace(",", ".");
                System.out.printf(" %2s %s %s(%s)  [%s, %s]%s Not qualified (%s)\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()),
                        tekmovalci[i][4], tekmovalci[i][3], tekmovalci[i][2], " ".repeat(46 - (tekmovalci[i][2].length() + tekmovalci[i][3].length() + 4)), skok);
            } else {
                String skok = String.valueOf(daljave[i][0]);
                skok = skok.replace(",", ".");
                String skok2 = String.valueOf(daljave[i][1]);
                skok2 = skok2.replace(",", ".");
                System.out.printf(" %2s %s %s(%s)  [%s, %s]%s %s         (%s)\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()),
                        tekmovalci[i][4], tekmovalci[i][3], tekmovalci[i][2], " ".repeat(46 - (tekmovalci[i][2].length() + tekmovalci[i][3].length() + 4)), skok2, skok);
            }
        }
    }

    public static void sodniskeOcene1(String vir) throws FileNotFoundException {
        File dokument = new File(vir);
        Scanner sc = new Scanner(dokument);
        String prvaVrstica = sc.nextLine();
        String vrstica;
        ocene = new double[40][2][5];

        while (sc.hasNextLine()) {
            vrstica = sc.nextLine();

            int stTekmovalca = Integer.parseInt(vrstica.split(";")[0]);
            if (vrstica.split(";")[1].equals("DSQ")) {
                ocene[stTekmovalca - 1][0][0] = 0.0;
            } else {
                for (int i = 0; i < 5; i++) {
                    ocene[stTekmovalca - 1][0][i] = Double.parseDouble(vrstica.split(";")[i + 1]);
                }
            }
        }
    }

    public static void izracun() {
        tocke = new double[40][3];

        for (int i = 0; i < ocene.length; i++) {
            double razdaljaTocke = 120 + ((daljave[i][0] - 200) * 1.2);

            double A = ocene[i][0][0];
            double B = ocene[i][0][1];
            double C = ocene[i][0][2];
            double D = ocene[i][0][3];
            double E = ocene[i][0][4];
            double MIN = 20;
            double MAX = 0;
            for (int j = 0; j < 5; j++) {
                if (ocene[i][0][j] <= MIN) {
                    MIN = ocene[i][0][j];
                    if (ocene[i][0][j] >= MAX) {
                        MAX = ocene[i][0][j];
                    }
                } else if (ocene[i][0][j] >= MAX) {
                    MAX = ocene[i][0][j];
                } else {

                }
            }
            double slogTocke = A + B + C + D + E - MIN - MAX;

            double naletTocke = komp_nalet[i][0];

            double veterTocke = komp_veter[i][0];

            tocke[i][0] = razdaljaTocke + slogTocke + naletTocke + veterTocke;
        }

    }

    public static void izpis4() {
        System.out.println("Points first round:");
        System.out.println("BIB NAME                      (NSA)  POINTS");
        for (int i = 0; i < 40; i++) {
            String tockeZapis = String.valueOf(Math.round(tocke[i][0]*10.0)/10.0);
            //System.out.println((i+1)+ " = " + Math.round(tocke[i][0]*10.0)/10.0);
            tockeZapis = tockeZapis.replace(",", ".");
            System.out.printf(" %2s %s %s(%s)  %.5s\n", tekmovalci[i][0], tekmovalci[i][1], " ".repeat(25 - tekmovalci[i][1].length()),
                    tekmovalci[i][4], tockeZapis);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        switch (Integer.parseInt(args[0])) {
            case 1:
                branje(args[1]);
                izpis1();
                break;
            case 2:
                branje(args[1]);
                branjeRezultatov(args[2]);
                izpis2();
                break;
            case 3:
                branje(args[1]);
                branjeRezultatov(args[2]);
                branjeRezultatov2(args[3]);
                izpis3();
                break;
            case 4:
                branje(args[1]);
                branjeRezultatov(args[2]);
                sodniskeOcene1(args[3]);
                izracun();
                izpis4();
        }

    }

}