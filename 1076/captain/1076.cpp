#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> r;

int main()
{
  string color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
  for (int i = 0; i < 10; i++)
  {
    r[color[i]] = i;
  }
  string s;
  int num[3];
  for (int i = 0; i < 3; i++)
  {
    cin >> s;
    num[i] = r[s];
  }
  int result = num[0] * 10 + num[1];
  printf("%d", result);
  if (result != 0)
  {
    for (int i = 0; i < num[2]; i++)
    {
      printf("0");
    }
  }
  printf("\n");
  return 0;
}