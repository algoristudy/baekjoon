import java.util.Scanner;
public class test1065 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*등차수열의 문제인데 1000미만의 입력 수 에 한에서 
		 * 일의자리와 십의자리 그리고 백의자리가 등차수열에 해당하는지 점검
		 * 여기서 1~99는 등차수열에 무조건 해당됨을 깨달아야 했고
		 * 백의자리수 입력시의 규칙은 등차수열이 맞는지 점검하는 a-b == b-c가 중요
		 * 여기서 일의자리와 십의자리 그리고 백의자리의 값을 각각 구해야 한다
		 * */
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
				a = i / 100; // 백의자리
				b = (i /10) % 10; // 십의 자리
				c = i % 10; // 일의 자리
				
				if((a-b) ==(b-c)) {
					input2++;
				}
			}
			System.out.println(input2);
		}
		

	}

}
