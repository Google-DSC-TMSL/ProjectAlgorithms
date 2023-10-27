// C++ implementation of the approach 

#include <bits/stdc++.h> 
#include<vector>
using namespace std; 

// Function to return the maximum 
// water that can be stored 
int trap(vector<int>& height,int n) {
        int prefix[n],suffix[n];
        prefix[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],height[i]);    
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=min(suffix[i],prefix[i])-height[i];
        }
        return sum;
    }
// Driver code //0,1,0,2,1,0,1,3,2,1,2,1
int main() 
{ 
	vector<int>height;
	int n,ele;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>ele;
	    height.push_back(ele);
	}

	cout << trap(height, n); 

	return 0; 
}