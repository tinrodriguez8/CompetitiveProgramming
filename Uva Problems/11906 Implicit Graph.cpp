#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#include <sstream>
#include <cstring>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
fore(int i=m;i<=n;i++)
#define T 105
using namespace std;

int table[T][T];
int test,r,c,m,n,water,caso=1;
bool bound(int x,int y)
{
	return x>=0 && x<r && y>=0 && y<c;
}
vector<set<int> > graph;
vector<int> visited;
vector<int> dxk,dyk;
int odd,even;
pair<int,int> u;

void dfs(int mi,int mj)
{
	visited[mi*c+mj] = 1;
	queue<pair<int,int> > Q;
	int cant = 0;
	set<int> visto;
	fore(d,0,8)
	{
		int nx = mi + dxk[d];
		int ny = mj + dyk[d];
		if(bound(nx,ny) && table[nx][ny]!=1 && visto.count(nx*c+ny)==0) 
		{
			cant++;
			visto.insert(nx*c+ny);
			Q.push(make_pair(nx,ny));
		}
	}
	if(cant%2==0)
		even++;
	else
		odd++;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		if(visited[u.first*c+u.second]!=1)
			dfs(u.first,u.second);
	}
}

int main()
{
	
	cin >> test;
	while(test--)
	{
		cin >> r >> c >> m >> n;
		memset(table,0,sizeof(table));
		visited.clear();
		visited.resize(r*c,-1);
		graph.clear();
		dxk.clear(); dyk.clear();
		graph.resize(c*r);
		dxk.push_back(n);dxk.push_back(m);dxk.push_back(n);dxk.push_back(m);dxk.push_back(-n);dxk.push_back(-m);dxk.push_back(-n);dxk.push_back(-m);
		dyk.push_back(m);dyk.push_back(n);dyk.push_back(-m);dyk.push_back(-n);dyk.push_back(-m);dyk.push_back(-n);dyk.push_back(m);dyk.push_back(n);
		odd = even = 0;
		cin >> water;
		while(water--)
		{
			int i,j;
			cin >> i >> j;
			table[i][j] = 1;
		}
		dfs(0,0);
		
		printf("Case %d: %d %d\n",caso++,even,odd);
		
	}
	
}	
