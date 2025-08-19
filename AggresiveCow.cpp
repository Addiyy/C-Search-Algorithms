#include <bits/stdc++.h>
using namespace std;

vector<int> input()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  return arr;
}

bool canWePlace(vector<int> arr, int gap, int cows)
{
  int n = arr.size();
  int lastCow = arr[0];
  cows--;
  for (int i = 1; i < arr.size(); i++)
  {
    if ((arr[i] - lastCow) >= gap)
    {
      lastCow = arr[i];
      cows--;
    }
  }
  if (cows > 0)
    return false;
  else
    return true;
}
int minDistance(vector<int> arr, int cows)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 1; i <= (arr[n - 1] - arr[0]); i++)
  {
    if (canWePlace(arr, i, cows) == true)
      continue;
    else
      return i - 1;
  }
  return -1;
}

int usingBinarySearch(vector<int> arr, int cows)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int low = 1, high = arr[n - 1];
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (canWePlace(arr, mid, cows) == true)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return high;
}

int main()
{
  int k;
  vector<int> arr = input();
  cin >> k;
  cout << usingBinarySearch(arr, k);
  return 0;
}