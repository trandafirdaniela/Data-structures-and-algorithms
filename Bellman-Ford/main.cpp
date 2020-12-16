#include <bits/stdc++.h>
#define dim 50005
#define inf 2000000000

using namespace std;
ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");
int nr_noduri,nr_muchii,nod;
vector <pair <int,int>> listaAdiacenta[dim];
int fr[dim],dist[dim],iq[dim];
queue <int> coada;

int main()
{
    int x,y,c;
    fin>>nr_noduri>>nr_muchii;
    for (int i=1; i<=nr_muchii; i++)
    {
        fin>>x>>y>>c;
        listaAdiacenta[x].push_back({y,c});
    }

    for (int i=2; i<=nr_noduri; i++)
        dist[i] = inf;
    dist[1] = 0;
    coada.push(1);
    iq[1]=1;

    while (!coada.empty())
    {
        nod = coada.front();
        coada.pop();
        iq[nod]=0;
        fr[nod]++;
        if (fr[nod] > nr_noduri)
        {
            fout<<"Ciclu negativ!";
            return 0;
        }
        for (auto it:listaAdiacenta[nod])
            if (dist[it.first] > dist[nod] + it.second)
            {
                dist[it.first] = dist[nod] + it.second;
                if(iq[it.first]==0)
                {
                    coada.push (it.first);
                    iq[it.first]=1;
                }
            }
    }

    for (int i=2; i<=nr_noduri; i++)
        fout<<dist[i]<<' ';


    return 0;
}
