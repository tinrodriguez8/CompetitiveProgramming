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
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define all(v) v.begin(),v.end()

#define T 100005
#define M 100005

using namespace std;


char c[25];
int m;
pair<int,int> a[T];
double cd[25][25];
double dist = T;

double go(int k,int n,double d) {
	
	
	if(n==1)
		fore(j,m*2)
			if(!(k & 1 << j)) {
				k |= 1<<j;
				for(int i = j+1;i<2*m;i++)
					if(!(k & 1<<i)) {
						dist = min(dist,d+cd[i][j]);
						return d +cd[i][j];
					}
			}
	if(d>=dist)
		return T;
	
	int p1,p2; double tmp=T;
	for(p1=0;p1<2*m;p1++)
		if(!(k & 1<<p1))
			break;
	for(p2=p1+1;p2<2*m;p2++)	{
		if(!(k & (1<<p2)))
			tmp = min(tmp,go(k | 1<<p1 | 1 <<p2,n-1,cd[p1][p2] + d));
	}
	
	return tmp;
}

int main()
{
	int caso=0;
	
	while(scanf("%d",&m) && m!=0) {
	
		dist = T;
		fore(i,m*2)
			scanf("%s %d %d",c,&a[i].first,&a[i].second);
			
		fore(i,2*m)
			fore(j,2*m)
				cd[i][j] = hypot(abs(a[i].first-a[j].first),abs(a[i].second-a[j].second));
				
		double tmp = go(0,m,0);
		printf("Case %d: %.2lf\n",++caso,tmp);	
	}
}	


