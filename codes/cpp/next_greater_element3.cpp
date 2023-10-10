#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int nextGreaterElement(int n) {
       vector<int>vec;
       int temp = n;
        while(n>0){
            int r = n%10;
            vec.push_back(r);
            n /= 10; 
        }
        sort(vec.begin(),vec.end());
        do{
            int num=0;
            long j=0;
            int s = vec.size()-1;
            long i = pow(10,s);
            while(i>0)
           {
            num += i*vec[j++];
            i /= 10;
           }
              if(num>temp)
                 return num;
    
        } while(next_permutation(vec.begin(),vec.end()));
       return -1;
    }

int main()
{
    int n;
    cin>>n;
    cout<<nextGreaterElement(n);
    return 0;
    
}