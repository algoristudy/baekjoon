// Problem Link: https://www.acmicpc.net/problem/1958
// This problem involves finding the LCS of 3 strings. 
// We just simply modify the recursive relationship and apply the iterative DP approach. 
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <string> 
using namespace std; 
 
int LCS[101][101][101];  
 
int Len(string s1, string s2, string s3){
    int l = (int)s1.size(); 
    int m = (int)s2.size();  
    int n = (int)s3.size();  
    for (int i = l; i >= 0; i--){
        for (int j = m; j >= 0; j--){
            for (int k = n; k >= 0; k--){
                if (i == l || j == m || k == n){
                    LCS[i][j][k] = 0;  
                } else if (s1[i] == s2[j] && s1[i] == s3[k]){
                    LCS[i][j][k] = 1+LCS[i+1][j+1][k+1];  
                } else{
                    LCS[i][j][k] = max(LCS[i+1][j][k],max(LCS[i][j+1][k],LCS[i][j][k+1]));  
                }
            }
        }
    }
    return LCS[0][0][0];  
}
 
int main(){
    string s1,s2,s3; 
    cin >> s1 >> s2 >> s3;  
    int ans = Len(s1,s2,s3); 
    cout << ans << endl;  
    return 0;  
}