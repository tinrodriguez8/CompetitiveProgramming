#include <iostream>

using namespace std;
int x1,x2,y1,y2;
bool sePuede=false;
int main()
{
	cin >> x1 >> y1 >> x2 >> y2;
	
	if(x1+1 == x2 && y1 == y2) sePuede=true;
	if(x1+1 == x2 && y1+1 == y2) sePuede=true;
	if(x1-1 == x2 && y1 == y2) sePuede=true;
	if(x1-1 == x2 && y1-1 == y2) sePuede=true;
	if(x1 == x2 && y1+1 == y2) sePuede=true;
	if(x1-1 == x2 && y1+1 == y2) sePuede=true;
	if(x1 == x2 && y1-1 == y2) sePuede=true;
	if(x1+1 == x2 && y1-1 == y2) sePuede=true;

}
