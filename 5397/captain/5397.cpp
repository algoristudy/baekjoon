#include <cstdio>

using namespace std;

struct Log {
  char c;
  int pre;
  int next;
}

int cursor, index; 
char log[1000001];
Log result[1000001];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", log);
    result[0] = {'', 0, }
    cursor = 1;
    index = 1;
    for (int i = 0; log[i] != '\0'; i++) {
      if (log[i] == '<') {
        result[cursor] 
      } else if (log[i] == '>') {

      } else if (log[i] == '-') {

      } else {

      }
    }
  }
}