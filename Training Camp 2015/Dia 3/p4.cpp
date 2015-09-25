#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
using namespace std;


long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b,a%b);}

long long in[100005];

int main() {
  ios_base::sync_with_stdio(false);
  long long n,a,k,test;

  cin >> test;
  while(test--) {
    cin >> n;

    fore(i,0,n)
      cin >> in[i];

  
    long long mx = 0;
  
    map<long long, long long> divisors;


    map<long long, long long> nextDivisors;
    for (long long i = 0 ; i < n ; i++) {
      nextDivisors.clear();
      for (map<long long,long long>::iterator p = divisors.begin();p!=divisors.end();p++) {
	k = gcd(p->first, in[i]);
	if(nextDivisors.count(k) == 0) {
	  nextDivisors[k] = p->second;
	}
	else {
	  nextDivisors[k] = min(p->second,nextDivisors[k]);
	}
      }
      if(nextDivisors.count(in[i]) == 0)
	nextDivisors[in[i]] = i;

      swap(nextDivisors, divisors);
      for (map<long long,long long>::iterator p = divisors.begin();p!=divisors.end();p++) {
	mx = max(mx,p->first * (i - p->second + 1LL));
      }
    }

    cout << mx << endl;
  }

}
