#include <iostream>
#include <vector>
#include <fstream>
#define DIM 500005
using namespace std;

int n, m;
int nr[DIM];
vector<int> lista[DIM], sol;
bool fr[DIM];
ifstream fin("sortaret.in");
ofstream fout("sortaret.out");
void dfs(int nod)
{
	fr[nod] = 1;
for(int i=0;i<lista[nod].size();i++)
{
		int vecin = lista[nod][i];
		if (!fr[vecin])
			dfs(vecin);
	}

	sol.push_back(nod);
}
int main()
{
	fin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++)
	{
		fin >> x >> y;
		lista[x].push_back(y);
		nr[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (fr[i] == 0 && nr[i] == 0)
			dfs(i);
	}
	for (int i = sol.size() - 1; i >= 0; i--)
		fout << sol[i] << " ";
	return 0;

}
