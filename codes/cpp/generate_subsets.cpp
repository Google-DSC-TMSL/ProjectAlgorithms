/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/





#include <bits/stdc++.h>
using namespace std;

/* Time Complexity = O(2^N) */

vector<vector<int>> v;

void generate(vector<int> &subset, int i, vector<int> &nums)
{

	if(i == nums.size())
	{
		v.push_back(subset);
		return;
	}

	// ith number consideration
	subset.push_back(nums[i]);
	generate(subset, i+1, nums);
	subset.pop_back();

	// ith number NO consideration
	generate(subset, i+1, nums);

}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n), subset;
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	generate(subset, 0, nums);
	for(auto p : v)
	{
		for(auto q : p)
		{
			cout<<q<<" ";
		}
		cout<<endl;
	}
	return 0;
}
