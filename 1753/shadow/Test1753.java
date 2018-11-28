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
		Arrays.sort(arr); // 알파벳 정렬
		
		check(0,0,0,0,""); // 전수조사 하면서 자음2 모음1개 일때만 출력		

	}
	
	// cnt는 지금까지 선택한 알파뱃의 총 개수
	private static void check(int index, int cnt, int mo, int ja, String s) {
		// L개의 문자가 된다면 다 만들었으므로 자음2개 모음1개 이상인지 확인하고 출력
		if(cnt==L) {
			if(mo>=1 && ja>=2) System.out.println(s);
			return;
		}
		if(index==C) return;
		
		// 모음일때는 mo+1 그 외에는 ja+1
		if(arr[index] =='a' || arr[index] =='e' || arr[index] =='i' || arr[index] =='o' || arr[index] =='u') {
			check(index+1, cnt+1, mo+1, ja, s+arr[index]);			
		}
		else {
			check(index+1, cnt+1, mo, ja+1, s+arr[index]);
		}
		
		check(index+1, cnt, mo, ja, s);
	}

}
