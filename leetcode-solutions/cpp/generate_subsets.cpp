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
	// your code goes here
	// make input and output faster
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
