import java.util.Scanner;

public class test1009 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int input;
		int A, B;
		int temp;
		Scanner scan = new Scanner(System.in);
		
		input = scan.nextInt();
		
		for(int i=0; i< input; i++) {
			A = scan.nextInt();
			B = scan.nextInt();
			
			temp = A;
			
			for(int j=0; j<B-1; j++) {
				A = temp * A % 10;
			}
			
			if(A == 0) {
				A = 10;
			}
			
			System.out.println(A);
		}

	}

}
