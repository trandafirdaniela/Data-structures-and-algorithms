#include <iostream>
#include <fstream>
#include <bitset>
#include <queue>
#include <vector>
#define dim 1005
using namespace std;
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
bitset <dim> fr;
queue <int> q;
vector <int> L[dim];
int C[dim][dim], F[dim][dim],t[dim],n,m,i,x,y,z,p,aux,minim,flux;
bool bfs()
{
    int gasit=0,nod,i,vecin;
    fr.reset();
    fr[1]=1;
    q.push(1);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(int i=0;i<L[nod].size();i++){
                vecin=L[nod][i];
            if(fr[vecin]==0&&C[nod][vecin]>F[nod][vecin]){
                q.push(vecin);
                fr[vecin]=1;
                t[vecin]=nod;
                if(vecin==n){
                    gasit=1;
                }
            }
        }
    }





    return gasit;
}
int main()
{
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y>>z;
        L[x].push_back(y);
        L[y].push_back(x);
        C[x][y]=z;
    }
    while(bfs())
    {
        for(int i=0;i<L[n].size();i++){
          p=L[n][i];
          if(C[p][n]>F[p][n]&&fr[p]==1){
            minim=C[p][n]-F[p][n];
            aux=p;
            while(t[aux]){
                minim=min(minim,C[ t[aux] ][ aux ] - F[ t[aux] ][ aux ]);
                aux=t[aux];
            }
            flux+=minim;
            F[p][n] += minim;
            F[n][p] -=minim;
            aux=p;
            cout<<n<<" ";
            while(t[aux]){
                cout<<aux<<" ";
                F[ t[aux] ][ aux ] += minim;
                F[ aux ][ t[aux] ] -= minim;
                aux=t[aux];
            }
            cout<<1<<" ";
            cout<<"m="<<minim;
            cout<<endl;
          }
        }


    }
    fout<<flux;
}