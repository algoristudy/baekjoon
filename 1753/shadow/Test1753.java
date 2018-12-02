import java.util.Arrays;
import java.util.Scanner;
public class Test1753 {
	static char[] arr;
	static int L, C;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		L = scan.nextInt();
		C = scan.nextInt();
		arr = new char[C];
		for(int i=0; i<C; i++){
			arr[i] = scan.next().charAt(0);
		}
		Arrays.sort(arr); // ���ĺ� ����
		
		check(0,0,0,0,""); // �������� �ϸ鼭 ����2 ����1�� �϶��� ���		

	}
	
	// cnt�� ���ݱ��� ������ ���Ĺ��� �� ����
	private static void check(int index, int cnt, int mo, int ja, String s) {
		// L���� ���ڰ� �ȴٸ� �� ��������Ƿ� ����2�� ����1�� �̻����� Ȯ���ϰ� ���
		if(cnt==L) {
			if(mo>=1 && ja>=2) System.out.println(s);
			return;
		}
		if(index==C) return;
		
		// �����϶��� mo+1 �� �ܿ��� ja+1
		if(arr[index] =='a' || arr[index] =='e' || arr[index] =='i' || arr[index] =='o' || arr[index] =='u') {
			check(index+1, cnt+1, mo+1, ja, s+arr[index]);			
		}
		else {
			check(index+1, cnt+1, mo, ja+1, s+arr[index]);
		}
		
		check(index+1, cnt, mo, ja, s);
	}

}
