#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input()
{
  int r, c;
  cin >> r >> c;
  vector<vector<int>> arr(r, vector<int>(c));
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr[i][j];
    }
  }
  return arr;
}

int binarySearch(vector<int> row, int target)
{
  int low = 0, high = row.size();
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (row[mid] == target)
      return mid;
    else if (target < row[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}
pair<int, int> search(vector<vector<int>> arr, int target)
{
  int r = arr.size();
  int c = arr[0].size();
  int column = -1, row = -1;
  for (int i = 0; i < r; i++)
  {
    if (arr[i][0] <= target && arr[i][c - 1] >= target)
    {
      column = binarySearch(arr[i], target);
      row = i;
    }
  }
  pair<int, int> ans;
  ans.first = row;
  ans.second = column;
  return ans;
}
int main()
{
  int target;
  vector<vector<int>> arr = input();
  cin >> target;
  pair<int, int> ans = search(arr, target);
  cout << ans.first << " " << ans.second;
  return -1;
}