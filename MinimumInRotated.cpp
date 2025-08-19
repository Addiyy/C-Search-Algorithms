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

int minimum(vector<int> arr)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int minimum = arr[0];
  int mini = arr[0];
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[low] < arr[mid])
    {
      mini = min(mini, arr[low]);
      low = mid + 1;
    }
    else
    {
      mini = min(mini, arr[mid]);
      high = mid - 1;
    }
  }
  return mini;
}
int main()
{
  vector<int> arr = input();
  cout << minimum(arr);
  return 0;
}
