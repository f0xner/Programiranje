import java.util.Scanner;

public class JAVA{
	public static void main(String[] args){
		System.out.print("Number?");
		Scanner sc = new Scanner(System.in);
		String cardNumber = sc.nextLine();
		System.out.println(luhnsCheck(cardNumber));
		sc.close();
	}
	private static boolean luhnsCheck(String number){
		StringBuffer sbf = new StringBuffer(number);
		int sum = 0;
		int num;
		int d = 0;

		for (int i = number.length()-2; i >=0; i--) {
			
			num = Integer.parseInt(String.valueOf(number.charAt(i)));
			if(d==0){
				num*=2;
				if(num>9){
					num = num/10 + num%10;
				}
				d=1;
				sbf.replace(i, i+1, String.valueOf(num));
			}else{
				d=0;
			}
		}
		number = sbf.toString();
		for (int i = 0; i < number.length(); i++) {
			sum += Integer.parseInt(String.valueOf(number.charAt(i)));
		}
		return sum%10==0;
	}
}
