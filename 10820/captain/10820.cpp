#include <cstdio>
#include <tuple>
using namespace std;

tuple<unsigned char, unsigned char, unsigned char, unsigned char> result[101];

int main() {
  unsigned char l, u, n, s, i, index = 0;;
  char c[102];
  while (true) {
    fgets(c, 102, stdin);
    if (c[0] == '\n') break;
    l = u = n = s = i = 0;
    while (c[i]) {
      if (c[i] == ' ') s++;
      else if ('A' <= c[i] && c[i] <= 'Z') u++;
      else if ('a' <= c[i] && c[i] <= 'z') l++;
      else if ('0' <= c[i] && c[i] <= '9') n++;
      i++;
    }
    result[index++] = make_tuple(l, u, n, s);
  }
  for (i = 0; i < index; i++) {
    printf("%d %d %d %d\n", get<0>(result[i]), get<1>(result[i]), get<2>(result[i]), get<3>(result[i]));
  }
  return 0;
}