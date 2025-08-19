#include <bits/stdc++.h>
using namespace std;

int findSqrt(int n)
{
  for (int i = 0; i * i <= n; i++)
  {
    if ((i * i) <= n && (i + 1) * (i + 1) > n)
    {
      return i;
    }
  }
  return -1;
}

int usingLog(int n)
{
  int low = 0, high = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if ((mid * mid) <= n && (mid + 1) * (mid + 1) > n)
    {
      return mid;
    }
    else if (mid * mid > n)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  cout << usingLog(n);
  return 0;
}