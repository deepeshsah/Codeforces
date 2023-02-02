#include<bits/stdc++.h>
using namespace std;
long long int rangeminquery(long long int segTree[],long long int qlow,long long int qhigh,long long int low,long long int high,long long int pos)
{
    if(qlow>high||qhigh<low)
        return LONG_LONG_MAX;
    if(qlow<=low&&qhigh>=high)
        return segTree[pos];
    long long int mid=(low+high)/2;
    return min(rangeminquery(segTree,qlow,qhigh,low,mid,2*pos+1),rangeminquery(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}
void constructTree(long long int input[],long long int segTree[], long long int low,long long int high,long long int pos)
{
    if(low==high)
    {
        segTree[pos]=input[low];
        return ;
    }
    long long int mid=(low+high)/2;
    constructTree(input,segTree,low,mid,2*pos+1);
    constructTree(input,segTree,mid+1,high,2*pos+2);
    segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);

}
int main()
{
    long long int n,i,q,x,y,j;
    cin>>n;
    i=log2(n);
    if(n>pow(2,i))
        i++;
    i=2*pow(2,i)-1;
    long long int input[n],segTree[i];
    for(j=0;j<i;j++)
        segTree[j]=LONG_LONG_MAX;
    for(i=0;i<n;i++)
        cin>>input[i];
    constructTree(input,segTree,0,n-1,0);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<rangeminquery(segTree,x,y,0,n-1,0)<<endl;
    }
    return 0;
}
