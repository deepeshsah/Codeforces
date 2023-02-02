#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,m,i,u,v,j,x,y,ans=0;
   cin>>n>>m;
   vector<long long int >v1[n+1];
   stack<long long int>s;
   bool a[n+1]={false};
   for(i=0;i<m;i++)
   {
      cin>>u>>v;
      v1[u].push_back(v);
   }
   for(i=1;i<=n;i++)
   {
       for(j=0;j<v1[i].size();j++)
       {
          a[v1[i][j]]=true;
       }
   }
   for(i=1;i<=n;i++)
   {
       if(a[i]==false)
        s.push(i);
   }
   for(i=0;i<=n;i++)
       a[i]=false;
   if(s.empty())
    s.push(1);
   while((!s.empty())&&ans==0)
   {
       y=s.top();
       for(i=0;i<v1[y].size();i++)
       {
           s.push(v1[y][i]);
           if(a[v1[y][i]]==true)
       {
           ans++;
           break;
       }

       }
       a[y]=true;
       s.pop();
       if(ans>0)
        break;
   }
   if(ans>0)
    cout<<"YES";
   else
    cout<<"NO";
   return 0;
}

