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
int lowerBound(vector<int> arr, int target)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
  }
  return ans;
}

int upperBound(vector<int> arr, int target)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] > target)
    {
      ans = mid;
      high = mid - 1;
    }
    else if (arr[mid] <= target)
    {
      low = mid + 1;
    }
  }
  return ans;
}

int searchPosition(vector<int> arr, int target)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      return mid + 1;
    }
    else if (arr[mid] > target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int findFloor(vector<int> arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1   ;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] <= target)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = input();
  int target;
  cin >> target;
  cout << findFloor(arr, target);
  return 0;
}