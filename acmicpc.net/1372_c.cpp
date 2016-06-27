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
  for(int i=0;i<n;i++) {
    cin >> d[1<<i];
  }

  string a,b,c;
  int maximum = 1<<n;
  for(int i=2;i<=n;i++) {
    unsigned int v = (1<<i)-1;
    while(v < maximum) {
      for(int j=0;j<n;j++) {
        if ( (v & (1<<j)) ==  (1<<j) ) {

          a = d[v ^ (1<<j)];
          b = d[(1<<j)];

          c = a + b;
          if ( d[v].size() == 0 ) {
            d[v] = c;
          }

          if ( d[v].size() > c.size() || ( d[v].size() == c.size() && d[v] > c ) ) {
            d[v] = c;
          }

          if ( a.find(b) != string::npos && ( d[v].size() > a.size() || ( d[v].size() == a.size() && d[v] > a ) ) ) {
            d[v] = a;
          }

          if ( b.find(a) != string::npos && ( d[v].size() > b.size() || ( d[v].size() == b.size() && d[v] > b ) ) ) {
            d[v] = b;
          }

          for(int k=1;k<=a.size();k++) {
            if ( d[v].size() >= a.size() + b.size() - k && b.size() >= k && a.substr(0,k) == b.substr(b.size()-k,k) ) {
              c = b.substr(0, b.size()-k) + a;
              if ( d[v].size() > c.size() || ( d[v].size() == c.size() && d[v] > c ) ) {
                d[v] = c;
              }
            }

            if ( d[v].size() >= a.size() + b.size() - k && b.size() >= k && a.substr(a.size()-k,k) == b.substr(0,k) ) {
              c = a + b.substr(k,b.size()-k);
              if ( d[v].size() > c.size() || ( d[v].size() == c.size() && d[v] > c ) ) {
                d[v] = c;
              }
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
