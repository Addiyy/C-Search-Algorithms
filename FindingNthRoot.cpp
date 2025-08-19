#include <bits/stdc++.h>
using namespace std;

// returns 1 when equal to num
// returns 0 when less tham num
// return 2 when greater than num
int func(int mid, int num, int power)
{ // To avoid overflow we use this
  long long ans = 1;
  for (int i = 1; i <= power; i++)
  {
    ans = ans * mid;
    if (ans > num)
      return 2;
  }
  return (ans == num) ? 1 : 0;
}
int findingRoot(int num, int power)
{
  int low = 1, high = num;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int result = func(mid, num, power);
    if (result == 1)
      return mid;
    else if (result == 2)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}
int main()
{
  int num, power;
  cin >> num >> power;
  cout << findingRoot(num, power);
  return 0;
}