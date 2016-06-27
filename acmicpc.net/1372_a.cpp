#include <iostream>
#include <string>
#include <unistd.h>

#define MAX 15
#define CASES 4097

using namespace std;

string d[CASES];

int main() {
  int n;
  cin >> n;
  int result=0;
  for(int i=0;i<n;i++) {
    cin >> d[1<<i];
    result+=d[1<<i].size();
  }

  string a,b,c;
  int cnt=0;
  int maximum = 1<<n;
  for(int i=2;i<=n;i++) {
    unsigned int v = (1<<i)-1;
    while(v < maximum) {
      for(int j=(v-1)&v; j>0; j=(j-1)&v) {
        a = d[j];
        b = d[v - j];

        c = a + b;
        if ( d[v].size() == 0 ) {
          d[v] = c;
        }

        int boost=0;

        if ( d[v].size() > c.size() || ( d[v].size() == c.size() && d[v] > c ) ) {
          d[v] = c;
        }

        for(int k=a.size();k>=1;k--) {
          if ( d[v].size() >= a.size() + b.size() - k && b.size() >= k && a.substr(a.size()-k,k) == b.substr(0,k) ) {
            c = a + b.substr(k,b.size()-k);
            if ( d[v].size() > c.size() || ( d[v].size() == c.size() && d[v] > c ) ) {
              d[v] = c;
              break;
            }
          }
        }
      }

      int t = (v | (v - 1)) + 1;
      int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
      v = w;
    }
  }

  cout << d[(1<<n)-1] << endl;
  return 0;
}
