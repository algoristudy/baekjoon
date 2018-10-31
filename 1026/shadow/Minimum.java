
public class test1026 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A = {1,1,1,6,0};
		int[] B = {2,7,8,3,1};
		int temp = 0;
		
		// A배열 오름차순
		for(int i=0;i<A.length;i++) {
			for(int j=0;j<A.length-(i+1); j++) {
				if(A[i] > A[i+1]) { // 자리교환
					temp = A[i+1];
					A[i+1] = A[i];
					A[i] = A[i+1];
				}
			}
		}
		// B배열 오름차순
		for(int i=0;i<B.length;i++) {
			for(int j=0;j<B.length-(i+1); j++) {
				if(B[i] > B[i+1]) { // 자리교환
					temp = B[i+1];
					B[i+1] = B[i];
					B[i] = B[i+1];
				}
			}
		}
		System.out.println(A[4]*B[4]);
		
	}	    


}
