#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Check rotation offset + index and compare it with sorted index
bool check(vector<int> &nums)
{
  // Brute Force
  int n = nums.size();

  vector<int> sortedNums = nums;
  sort(sortedNums.begin(), sortedNums.end());

  for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset)
  {
    bool isMatch = true;

    for (int index = 0; index < n; ++index)
    {
      if (nums[(rotationOffset + index) % n] != sortedNums[index])
      {
        isMatch = false;
        break;
      }
    }
    if (isMatch)
    {
      return true;
    }
  }
  return false;
}

// Optimal
// nums[(i + 1) % n] because it lets us treat the array circular
// we compare the last and first index elements

bool check_Optimal(vector<int> &nums)
{
  int n = nums.size();
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    if (nums[i] > nums[(i + 1) % n])
    {
      cnt++;
    }
  }
  if (cnt > 1)
  {
    return false;
  }
  return true;
}

int main()
{

  return 0;
}
