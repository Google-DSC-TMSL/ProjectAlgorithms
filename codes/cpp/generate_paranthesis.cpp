#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void generate(string &s, int open, int close)
{
	if(open == 0 && close == 0)
	{
		v.push_back(s);
		return;
	}

	if(open > 0)
	{
		s.push_back('(');
		// cout<<"open: "<<s<<endl;
		generate(s,open - 1, close);
		s.pop_back();
	}


	if(close > 0)
	{
		if(open < close)
		{
			s.push_back(')');
			// cout<<"close: "<<s<<endl;
			generate(s, open, close - 1);
			s.pop_back();
		}
	}
}

int main() {
	// your code goes here
	// make input and output faster
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string s="";
	generate(s, n, n);
	for(auto s : v)
	{
		cout<<s<<endl;
	}
	return 0;
}
