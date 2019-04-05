#include <cstdio>
#include <vector>
using namespace std;

vector<char> a(26, -1);

int main(int argc, char const *argv[])
{
  char c[101], i = 0, j;
  scanf("%s", c);
  while(c[i]) {
    j = c[i] - 'a';
    if (a[j] == -1) a[j] = i;
    i++;
  }
  for (i = 0; i < 26; i++) 
    printf("%d ", a[i]);
  return 0;
}