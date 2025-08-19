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
bool search(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0, high = n - 1;
  bool flag = false;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return true;
    if (nums[low] == nums[mid] && nums[mid] == nums[high])
    {
      low++;
      high--;
    }
    else if (nums[low] <= nums[mid])
    {
      if (target >= nums[low] && target < nums[mid])
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
      if (target > nums[mid] && target <= nums[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return false;
}
int main()
{
  vector<int> arr = input();
  int n;
  cin >> n;
  cout << search(arr, n);
  return 0;
}