#include <iostream>
using namespace std;
int main()
{
    int target,nums,j,k;
    int a[nums];
    int flag=0;
    cin>>target>>nums;
    for (int i=0;i<nums;i++)
        cin>>a[i];
    for (j=0;j<nums;j++)
    {
        if(a[j]>=target)
            continue;
        for(k=j+1;k<nums;k++)
        {
            if(a[j]+a[k]==target)
                {
                    flag=1;
                    break;
                }
        }
        if(flag ==1)
            break;
    }
    if(flag==1)
    {
        cout<<j<<' '<<k;
    }
    else
    {
        cout<<"-1 -1";
    }
    return 0;
}