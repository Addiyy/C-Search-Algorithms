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

int findSum(vector<int> &arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}
int daysRequired(vector<int> &arr, int size, int capacity)
{
  int days = 1;
  int cap_trans = 0;
  for (int i = 0; i < size; i++)
  {
    if (cap_trans + arr[i] > capacity)
    {
      days++;
      cap_trans = arr[i];
    }
    else
    {
      cap_trans += arr[i];
    }
  }
  return days;
}
int findingCapacity(vector<int> arr, int days_given)
{
  int n = arr.size();
  int sum = findSum(arr, n);
  int maxi = *max_element(arr.begin(), arr.end());
  for (int i = maxi; i <= sum; i++)
  {
    int days = daysRequired(arr, n, i);
    if (days <= days_given)
    {
      return i;
    }
  }
  return -1;
}

int findingCapacityOptimised(vector<int> arr, int days_given)
{
  int low = *max_element(arr.begin(), arr.end());
  int high = findSum(arr, arr.size());
  int min_cap = high;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (daysRequired(arr, arr.size(), mid) <= days_given)
    {
      high = mid - 1;
      min_cap = min(min_cap, mid);
    }
    else
    {
      low = mid + 1;
    }
  }
  return min_cap;
}
int main()
{
  int days_given;
  vector<int> arr = input();
  cin >> days_given;
  cout << findingCapacityOptimised(arr, days_given);
  return 0;
}