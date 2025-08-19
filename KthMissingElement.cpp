#include <bits/stdc++.h>
using namespace std;

// The problem states that we are given an array which contains some elements and some        elements are missing from array as it consists of a natural number series.

// We have to find the Kth missing element from that array of missing elements.

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

// brute Force
int findingKthElement(vector<int> &arr, int k)
{
  int n = arr.size();
  int max = *max_element(arr.begin(), arr.end());
  vector<int> ans;
  for (int i = 1; i < max; i++)
  {
    bool flag = true;
    for (int j = 0; j < arr.size(); j++)
    {
      if (i == arr[j])
        flag = false;
    }
    if (flag == true)
      ans.push_back(i);
  }
  return ans[k - 1];
}

int anotherSolution(vector<int> &arr, int k)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= k)
      k++;
    else
      return k;
  }
  return k;
}

int optimalSolution(vector<int> arr, int k)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<int> new_arr(n);
  if (k < arr[0])
    return k;
  // Getting the array of missing values
  for (int i = 0; i < n; i++)
  {
    new_arr[i] = arr[i] - (i + 1);
  }

  // Performing Binary Search on that
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (new_arr[mid] < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  // Returning the missing element
  return arr[high] + (k - high);
}

int main()
{
  int k;
  vector<int> arr = input();
  cin >> k;
  cout << optimalSolution(arr, k);
  return 0;
}