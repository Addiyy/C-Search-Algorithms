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

int firstOccurence(vector<int> arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {

      first = mid;
      high = mid - 1;
    }
    else if (target > arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return first;
}
int lastOccurence(vector<int> arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int last = -1;
  while (low <= high)
  {
    int mid = (high + low) / 2;
    if (arr[mid] == target)
    {
      last = mid;
      low = mid + 1;
    }
    else if (target > arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return last;
}

int main()
{
  vector<int> arr = input();
  int target;
  cin >> target;
  int first = firstOccurence(arr, target);
  int last = lastOccurence(arr, target);
  cout << first << " " << last << endl;
  int count;
  if (first == -1)
    count = 0;
  else
    count = last - first + 1;
  cout << count;
  return 0;
}