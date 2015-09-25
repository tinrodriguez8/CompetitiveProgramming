#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int N,M,aux,cases;
vector<int> vN,vM;
bool wayToSort(int i, int j) { return i > j; }
int main()
{
	while(scanf("%d" "%d",&N,&M)==2)
	{
		vN.clear();
		vM.clear();
		cases++;
		for(int i = 0;i<N;i++)
		{
			scanf("%d",&aux);
			vN.push_back(aux);
		}
		for(int i = 0;i<M;i++)
		{
			scanf("%d",&aux);
			vM.push_back(aux);
		}

		sort(vN.begin(),vN.end(),wayToSort);
		sort(vM.begin(),vM.end(),wayToSort);

		while(!vM.empty() && !vN.empty())
		{	

			
			if(vN.size() !=1 && vN.size() != 0)
			{
				if(vN[0] > vM[0])  
				{
					vM.erase(vM.begin());
				}
				else 
				{
					aux = 0;
					aux += (vN[0] + vN[1]);
					vN.erase(vN.begin());
					vN.erase(vN.begin());
					vN.insert(vN.begin(),aux);
				}
			}
			else
			{
				 if(vN[0] > vM[0])  
				 {
					vM.erase(vM.begin());
				 }
			}
			if(vM.size() !=1 && vM.size() != 0)
			{		
				if(vN[0] < vM[0])  
				{
					vN.erase(vN.begin());
				}		
				else 
				{
					aux = 0;
					aux += vM[0] + vM[1];
					vM.erase(vM.begin());
					vM.erase(vM.begin());
					vM.insert(vM.begin(),aux);
				}
			}
			else
			{
				if(vN[0] < vM[0])  
				{
					vN.erase(vN.begin());
				}
			}
			
			

		}
		if(!vN.empty())
		{
			cout << "Case " << cases << ":" << " Takeover Incorporated" << endl;
		}
		else
		{
			cout << "Case " << cases << ":" << " Buyout Limited" << endl;
		}

	}

	return 0;
}
