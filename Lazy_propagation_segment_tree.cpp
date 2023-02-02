#include<bits/stdc++.h>
using namespace std;
long long int rangeMinimumQueryLazy(long long int segTree[],long long  int lazy[],long long  int qlow,long long int qhigh,long long int low, long long int high,long long int pos)
{
    if(low>high)
        return LONG_LONG_MAX;
    if(lazy[pos]!=0)
    {
        segTree[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(qlow>high||qhigh<low)
        return LONG_LONG_MAX;
    if(qlow<=low&&qhigh>=high)
        return segTree[pos];
    long long int mid=(low+high)/2;
    return min(rangeMinimumQueryLazy(segTree, lazy, qlow, qhigh,low, mid, 2 * pos + 1),rangeMinimumQueryLazy(segTree, lazy,  qlow, qhigh,mid + 1, high, 2 * pos + 2));
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
void updateSegmentTreeRangeLazy(long long int segTree[],long long int lazy[],long long int startRange,long long int endRange, long long int delta,long long int low,long long int high,long long int pos)
{
    if(low>high)
    {
        return;
    }
    if(lazy[pos]!=0)
    {
        segTree[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(startRange>high||endRange<low)
    {
        return;
    }
    if(startRange<=low&&endRange>=high)
    {
       segTree[pos]+=delta;
       if(low!=high)
       {
           lazy[2*pos+1]+=delta;
           lazy[2*pos+2]+=delta;
       }
       return;
    }
    long long int mid=(low+high)/2;
    updateSegmentTreeRangeLazy(segTree,lazy,startRange,endRange,delta,low,mid,2*pos+1);
    updateSegmentTreeRangeLazy(segTree,lazy,startRange,endRange,mid+1,high,mid,2*pos+2);
    segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
}
int main()
{
    long long int n,i,q,x,y,j,z,type;
    cin>>n;
    i=log2(n);
    if(n>pow(2,i))
        i++;
    i=2*pow(2,i)-1;
    long long int input[n],segTree[i],lazy[i];
    for(j=0;j<i;j++)
    {
         segTree[j]=LONG_LONG_MAX;
         lazy[j]=0;
    }
    for(i=0;i<n;i++)
        cin>>input[i];
    constructTree(input,segTree,0,n-1,0);
    cin>>q;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>x>>y>>z;
            updateSegmentTreeRangeLazy(segTree,lazy,x,y,z,0,n-1,0);

        }
        else
        {
            cin>>x>>y;
            cout<<rangeMinimumQueryLazy(segTree,lazy,x,y,0,n-1,0);
        }
    }
    return 0;
}
