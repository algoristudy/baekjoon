import java.util.Scanner;
public class Test9663 {
	static int count = 0;
	static int row[] = new int[16];// 1. 체스판 배열 생성 및 0으로 초기화	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int N;
		
		N = scan.nextInt(); // 퀸의 갯수 입력			 			
		
		// 2.전수조사 하면서 한줄에  1(퀸)개를 반드시 채운다. 즉 N이 4라면  4개의 퀸이 존재하는 경우만 count+1
		
		Queens(0,N);
		
		System.out.println(count);		
		
	}
	
	// 칸에서 가로 세로 대각선 체크
	private static boolean check(int index) {
		for(int j=0; j<index;j++) {
			// 열 체크
			if(row[j] == row[index])
				return false;
			// 대각선 체크(
			else if(Math.abs(row[index] - row[j]) == (index-j))
				return false;
		}
		return true;
	}
	
	
	private static void Queens(int index, int N) {
		if(index == N){
			count +=1; // 5. 만약 각줄 한개씩 퀸이 채워진다면 , 즉 N개만큼의 퀸 갯수가 채워지면 count+1	
		}
		else {
			for(int i=0; i<N; i++) {
				row[index] = i; // 퀸 배치 좌표
				if(check(index)) Queens(index+1, N);
					
			}
		}		
	}

}
