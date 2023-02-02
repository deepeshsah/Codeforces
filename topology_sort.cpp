#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,m,i,u,v,j,x,y;
   cin>>n>>m;
   vector<long long int >v1[n+1];
   deque<long long int>q;
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
           //cout<<v1[i][j]<<" ";
          a[v1[i][j]]=true;
       }
      // cout<<endl;
   }
   for(i=1;i<=n;i++)
   {
       if(a[i]==false)
        q.push_back(i);
   }
  // cout<<q.size()<<endl;
   a[n+1]={false};
   for(i=0;i<=n;i++)
   a[i]=false;
   while(!q.empty())
   {
     x=q.front();
     y=0;
     for(i=0;i<v1[x].size();i++)
     {
         if(a[v1[x][i]]==false)
           {
               y++;
               q.push_front(v1[x][i]);
           }
     }
     if(y==0)
     {
        s.push(x);
        a[x]=true;
        q.pop_front();
        //cout<<x<<endl;
     }
   }
   //cout<<s.size()<<endl;
   while(!s.empty())
   {
       y=s.top();
       cout<<y<<" ";
       s.pop();
   }
   return 0;
}

