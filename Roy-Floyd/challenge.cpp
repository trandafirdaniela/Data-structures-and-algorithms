#include <iostream>
#include <fstream>
#define inf 1000000000
using namespace std;

int a[105][105],v[105][105],i,j,n,k;
void afisareDrum(int i,int j){
    cout<<i<<" ";  ///i
    if(v[i][j]!=0){
        afisareDrum(i,v[i][j]); /// intre i si k incepe o noua afisare
        cout<<k<<" "; /// k nod
        afisareDrum(v[i][j],j); /// intre k si j incepe o noua afisare
    }
    cout<<j<<" ";
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
                a[i][j]=inf;
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&i!=k)
                 if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                    v[i][j]=k; ///
                 }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            afisareDrum(i,j);
            cout<<"\n";
        }
    }
    return 0;
}
