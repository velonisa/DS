#include <iostream>
using namespace std;
int main()
{
    int count, a[2], time[24],iStart, max;
    for(int i=0;i<24;i++)
    {
        time[i]=0;
    }
    cin >> count;
    for(int j=0;j<count;j++)
    {
        for(int i=0;i<2;i++)
        {
            cin >> a[i];
        }
        for(iStart=a[0];iStart<a[1];iStart++)
        {
            time[iStart]++;
        }
    }
    max = time[0];
    for (int k=1;k<24;k++)
    {
        if(time[k]>max)
            max=time[k];
    }
    cout << max << endl;
    return 0;
}