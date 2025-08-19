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

// TC : O(n*n)
bool possible(vector<int> arr, int day, int bouquets, int flowers)
{
  int count = 0, bq_formed = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= day)
    {
      count++;
    }
    else
    {
      bq_formed = bq_formed + (count / flowers);
      count = 0;
    }
  }
  bq_formed = bq_formed + (count / flowers);
  if (bq_formed == bouquets)
  {
    return true;
  }
  return false;
}
int noOfDays(vector<int> arr, int bouquets, int flowers)
{
  int n = arr.size();
  if ((bouquets * flowers) > n)
    return -1;
  int bq_formed = 0;
  vector<int> ans;
  bool found = false;
  for (int i = 0; i < n; i++)
  {
    if (possible(arr, arr[i], bouquets, flowers) == true)
    {
      ans.push_back(arr[i]);
      found = true;
    }
  }
  sort(ans.begin(), ans.end());
  if (found == true)
    return ans[0];
  return -1;
}

int main()
{
  int bouquets, flowers;
  vector<int> arr = input();
  cin >> bouquets >> flowers;
  cout << noOfDays(arr, bouquets, flowers);
  return 0;
}