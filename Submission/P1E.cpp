#include <iostream>
#include <algorithm>
using namespace std;
long long n,s,d,c,ans;


int main()
{
    ans = -1;
    cin >> n >> s;
    for(int i = 0;i<n;i++)
    {
        cin >> d >> c;
        if(d>s) continue;
        if(d==s && c>0) continue;
        if(c>0) ans = max(ans,100-c);
        else ans = max(ans,(long long)0);
    }
    cout << ans;
    
    return 0;
}
