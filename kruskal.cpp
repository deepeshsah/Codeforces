#include<bits/stdc++.h>
using namespace std;
long long int parent[1000000],i,no_of_vertex;
long long int find(long long int k)
    {
       if(parent[k]==k)
        return k;
       return find(parent[k]);
    }
    long long int union1(long long int a,long long int b)
    {
        long long int x=find(a);
        long long int y=find(b);
        parent[x]=y;
        if(x==y)
            return 0;
        else
            return 1;
    }
    void print()
    {
        for(i=1;i<=no_of_vertex;i++)
        {
            cout<<find(parent[i])<<" ";
        }
        cout<<endl;
    }
int main()
{
    vector<pair<long long int ,pair<long long int,long long int > > >v;
    long long int no_of_edges,weight,n,x,y,z;
    cin>>no_of_vertex>>no_of_edges;
    for(i=1;i<=no_of_vertex;i++)
    {
        parent[i]=i;
    }
    v.clear();
    n=no_of_edges;
    while(n--)
    {
      cin>>weight>>x>>y;
      v.push_back(make_pair(weight,make_pair(x,y)));
    }
    sort(v.begin(),v.end());
    n=1;
    i=0;
    while(n<no_of_vertex)
    {
       z=union1(v[i].second.first,v[i].second.second);
       if(z==1)
       {
           cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
           n++;
       }
       i++;
    }
    return 0;
}
