import java.util.Scanner;
public class Test9663 {
	static int count = 0;
	static int row[] = new int[16];// 1. ü���� �迭 ���� �� 0���� �ʱ�ȭ	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int N;
		
		N = scan.nextInt(); // ���� ���� �Է�			 			
		
		// 2.�������� �ϸ鼭 ���ٿ�  1(��)���� �ݵ�� ä���. �� N�� 4���  4���� ���� �����ϴ� ��츸 count+1
		
		Queens(0,N);
		
		System.out.println(count);		
		
	}
	
	// ĭ���� ���� ���� �밢�� üũ
	private static boolean check(int index) {
		for(int j=0; j<index;j++) {
			// �� üũ
			if(row[j] == row[index])
				return false;
			// �밢�� üũ(
			else if(Math.abs(row[index] - row[j]) == (index-j))
				return false;
		}
		return true;
	}
	
	
	private static void Queens(int index, int N) {
		if(index == N){
			count +=1; // 5. ���� ���� �Ѱ��� ���� ä�����ٸ� , �� N����ŭ�� �� ������ ä������ count+1	
		}
		else {
			for(int i=0; i<N; i++) {
				row[index] = i; // �� ��ġ ��ǥ
				if(check(index)) Queens(index+1, N);
					
			}
		}		
	}

}
