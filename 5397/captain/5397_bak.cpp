#include <cstdio>
using namespace std;

char log[1000001];
char result[1000001];
int cursor, end;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", log);
    cursor = 0;
    end = 0;
    for (int i = 0; log[i] != '\0'; i++) {
      if (log[i] == '<') {
        if (cursor > 0) cursor--;
      } else if (log[i] == '>') {
        if (cursor < end) cursor++;
      } else if (log[i] == '-') {
        if (cursor == 0) continue;
        cursor--;
        end--;
        for (int j = cursor; j < end; j++)
          result[j] = result[j + 1];
      } else {
        if (cursor == end) result[cursor] = log[i];
        else {
          for (int j = end; j > cursor; j--) {
            result[j] = result[j - 1];
            result[cursor] = log[i];
          }
        } 
        cursor++;
        end++;
      }
    }
    for (int i = 0; i < end; i++) {
      printf("%c", result[i]);
    }
    printf("\n");
  }
  
  return 0;
}