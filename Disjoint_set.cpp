#include<bits/stdc++.h>
using namespace std;
long long int parent[1000000],i,no_of_vertex;
long long int find(long long int k)
    {
       if(parent[k]==k)
        return k;
       return find(parent[k]);
    }
    void union1(long long int a,long long int b)
    {
        long long int x=find(a);
        long long int y=find(b);
        parent[x]=y;
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
    long long int no_of_query;
    cin>>no_of_vertex>>no_of_query;
    for(i=1;i<=no_of_vertex;i++)
    {
        parent[i]=i;
    }
    while(no_of_query--)
    {
        long long int x,y;
        cin>>x>>y;
        union1(x,y);
        print();

    }
    // print();
    return 0;
}
