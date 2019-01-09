#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,k,i,ans=0;
cin>>n>>k;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(i=n-1;i>n-k-1;i--)
{
if(a[i]>0)
ans++;
}
for(i=n-k-1;i>=0;i--)
{
if(a[i]==a[n-k]&&a[i]>0)
ans++;
}
cout<<ans;
return 0;
}

/*  link:  https://codeforces.com/contest/158/problem/A  */
