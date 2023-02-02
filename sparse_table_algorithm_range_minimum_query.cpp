#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,q,x,y,k;
    cin>>n;
    i=log2(n)+1;
    long long int a[n],sparse[n][i];
    for(i=0;i<n;i++)
    {
     cin>>a[i];
     sparse[i][0]=i;
    }
    for(j=1;j<=log2(n);j++)
    {
        k=pow(2,j-1);
        for(i=0;i<n;i++)
        {
            if(i+pow(2,j)<=n)
            {
                if(a[sparse[i][k-1]]<a[sparse[i+k][k-1]])
                   sparse[i][j]=sparse[i][k-1];
                else
                sparse[i][j]=sparse[i+k][k-1];
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        i=log2(y-x+1);
        j=y-x+1-pow(2,i);
        cout<<min(a[sparse[x][i]],a[sparse[x+j][i]])<<endl;
    }
    return 0;
}
