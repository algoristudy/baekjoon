#include <cstdio>
using namespace std;

int main() {
  int month, day, sum = 0, week;
  int year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d %d", &month, &day);
  for (int i = 1; i < month; i++) {
    sum += year[i];
  }
  sum += day - 1;
  week = sum % 7;
  if (week == 0) printf("MON\n");
  else if (week == 1) printf("TUE\n");
  else if (week == 2) printf("WED\n");
  else if (week == 3) printf("THU\n");
  else if (week == 4) printf("FRI\n");
  else if (week == 5) printf("SAT\n");
  else if (week == 6) printf("SUN\n");
  return 0;
}