#include <cstdio>

using namespace std;

const int arr_size = 123456 * 2 + 1;

bool isPrime[arr_size] = {false, false, };
int primeCnt[arr_size] = {0, 0, };

int main() {
  int n, cnt;
  for (int i = 2; i < arr_size; i++) isPrime[i] = true;
  for (int i = 2; i < arr_size; i++) {
    if (isPrime[i]) {
      for (int j = i + i; j < arr_size; j += i) {
        if (isPrime[j]) isPrime[j] = false;
      }
    }
    primeCnt[i] = isPrime[i] ? primeCnt[i - 1] + 1 : primeCnt[i - 1];
  }
  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    printf("%d\n", primeCnt[2 * n] - primeCnt[n]);
  }
  return 0;
}
