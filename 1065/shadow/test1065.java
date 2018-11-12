import java.util.Scanner;
public class test1065 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		
		int input;
		int input2 = 99;
		int a,b,c;
		
		input = scan.nextInt();
		
		if(input < 100) {
			System.out.println(input);
		}
		else {
			for(int i=100; i<=input; i++) {
				a = i / 100;
				b = (i /10) % 10;
				c = i % 10;
				
				if((a-b) ==(b-c)) {
					input2++;
				}
			}
			System.out.println(input2);
		}
		

	}

}
