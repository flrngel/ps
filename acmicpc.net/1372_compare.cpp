#include <iostream>
#include <string>
#include <unistd.h>

#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

#define MAX 15
#define CASES 4097

using namespace std;

string d[CASES][MAX];
string result;

string dmin(const string& a, const string& b) {
  // optimized for left
  if ( a.size() == 0 )
    return b;

  if ( a.size() < b.size() )
    return a;
  else if ( a.size() == b.size() && a < b )
    return a;

  return b;
}

int main() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> d[1<<i][i];
  }

  string a,b,c;
  int cnt=0;
  int maximum = 1<<n;
  for(int i=1;i<=n-1;i++) {
    unsigned int v = (1<<i)-1;
    while(v < maximum) {
      for(int j=0;j<n;j++) {
        int j_length = d[1<<j][j].size();
        if ( (v & (1<<j)) == (1<<j) ) {
          for(int k=0;k<n;k++) {
            if ( (v & (1<<k)) == 0 ) {
              if ( d[1<<j][j].find(d[1<<k][k]) != string::npos ) {
                d[v^(1<<k)][k] = d[v][j];
                d[v^(1<<k)][j] = d[v][j];
                continue;
              }

              d[v^(1<<k)][k] = dmin(d[v^(1<<k)][k], d[v][j] + d[1<<k][k]);
              //printf("%c%c%c%c%c%c%c%c " , BYTE_TO_BINARY(v));
              //cout << d[v][j] << " "<< j << " " << k << " => ";
              //printf("d[%c%c%c%c%c%c%c%c][%d] " , BYTE_TO_BINARY((v^(1<<k))), k);
              //cout << d[v^(1<<k)][k] << endl;
              //cout << "j_length:" << j_length << endl;

              for(int l=j_length;l>=1;l--) {
                if( d[1<<j][j].substr(j_length-l, j_length) == d[1<<k][k].substr(0, l) ) {
                  d[v^(1<<k)][k] = dmin(d[v^(1<<k)][k], d[v][j] + d[1<<k][k].substr(l));
                }
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

  for(int i=0;i<n;i++) {
    result = dmin(result, d[maximum-1][i]);
  }

  cout << result << endl;
  return 0;
}
