#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define DIM 100005
#define INF DIM*10

using namespace std;

vector<pair<int, int>> listaAdiacenta[DIM];
set<pair<int, int>> q;
int dist[DIM], x, y, c;
int nr_noduri, nr_muchii, k;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

//un singur drum de la nod 1 pana la fiecare

void generator(int &n,int &m){
    vector< int> comp,ncomp; //elemente componenta conexa si elemente care nu se afla inca in componenta
    n=rand()%30+10; /// cel putin 10 noduri

    /// m este maxim n*(n-1)/2
    m=n-1; /// am  un arbore ... am n-1 muchii
    fout<<n<<" "<<m<<"\n";
    for(int i=2;i<=n;i++){
        ncomp.push_back(i);
    }
    comp.push_back(1);
    while(ncomp.size()){
        int poz=rand()%comp.size(); /// pozitie random din componenta
        int x=comp[poz];
        poz=rand()%ncomp.size();
        int y=ncomp[poz];
        ncomp.erase(ncomp.begin()+poz);
        comp.push_back(y); /// il adaug pe y in componenta
        int cost=rand()%100+1;   /// 1 pana la 100
        listaAdiacenta[x].push_back(make_pair(y,cost));
        fout<<x<<" "<<y<<" "<<cost<<"\n";
    }
}

int main()
{

    generator(nr_noduri,nr_muchii);
    for (int i = 1; i <= nr_noduri; i++)
    {
        dist[i] = INF;
    }

    dist[1] = 0;

    q.insert(make_pair(0, 1));

    while (!q.empty())
    {
        int vertex = q.begin()->second;

        q.erase(q.begin());

        for (size_t i = 0; i < listaAdiacenta[vertex].size(); i++)
        {
            int neighbour = listaAdiacenta[vertex][i].first;
            int cost = listaAdiacenta[vertex][i].second;

            if (dist[neighbour] > dist[vertex] + cost)
            {
                q.erase(make_pair(dist[neighbour], neighbour));
                dist[neighbour] = dist[vertex] + cost;
                q.insert(make_pair(dist[neighbour], neighbour));


            }
        }
    }
    for (int i = 2; i <= nr_noduri; i++)
    { if (dist[i] == INF)
            fout << "0 ";
        else
            fout << dist[i] << " ";
    }
}
