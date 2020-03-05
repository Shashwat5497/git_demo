#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter the length of array = ";
	cin>>n;
	int p[n],dp[n];
	cout<<"enter the array element = \n";
	for(int i=0;i<n;i++)
	{ 
	  cin>>p[i];
	  dp[i]=1;
    }
	
	cout<<"\n\n Length of longest subsequence is = ";
	int i=1;
    while(i<n)
    {
    	for(int j=0;j<i;j++)
    	{
    		if(p[j]<p[i])
    		dp[i]=max(dp[j]+1,dp[i]);
		}
		i++;
	}
	cout<<"\ndp\n";
		for(int i=0;i<n;i++)
	    {
	    	cout<<dp[i]<<" ";
	    }
	    cout<<endl;
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>max)
		max=dp[i];
	}
	cout<<max<<endl;
	return 0;
}
