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

int searchRotated(vector<int> arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[low] <= arr[mid])
    {
      if (target >= arr[low] && target < arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (target > arr[mid] && target <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  vector<int> arr = input();
  int target;
  cin >> target;
  cout << searchRotated(arr, target);
  return 0;
}