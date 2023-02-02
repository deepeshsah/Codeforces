#include<bits/stdc++.h>
using namespace std;
long long int parent[1000000];
long long int find(long long int k)
    {
       if(parent[k]==k)
        return k;
       return find(parent[k]);
    }
    long long int  union1(long long int a,long long int b)
    {
        long long int x=find(a);
        long long int y=find(b);
        parent[x]=y;
        if(x==y)
        {
            return 1;
        }
        else
            return 0;

    }
int main()
{
    long long int no_of_edges,n,x,y,z,ans=0,i,no_of_vertex;
    cin>>no_of_vertex>>no_of_edges;
    for(i=1;i<=no_of_vertex;i++)
    {
        parent[i]=i;
    }
    n=no_of_edges;
    while(n--)
    {
      cin>>x>>y;
     z=union1(x,y);
     if(z==1)
        ans++;
    }
    if(ans==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
