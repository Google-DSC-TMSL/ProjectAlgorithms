#include <bits/stdc++.h>
using namespace std;

/* Time Complexity = (N * 2^N) */

vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	int subset_ct = (1 << n);
	vector<vector<int>> subsets_sets;
	for(int mask=0; mask<subset_ct; mask++)
	{
		vector<int> subset;
		for(int i=0; i<n; i++)
		{
			if(mask & (1 << i))
			{
				subset.push_back(nums[i]);
			}
		}
		subsets_sets.push_back(subset);
	}
	return subsets_sets;
}

int main() {

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++)
	{
		cin >> nums[i];
	}

	auto all_subsets = subsets(nums);

	for(auto subset: all_subsets)
	{
		for(auto ele : subset)
		{
			cout << ele << " ";
		}
		cout << endl;
	}


	return 0;
}

