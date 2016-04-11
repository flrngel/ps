#include <iostream>

using namespace std;

int main() {
  int t,T=0;
  cin >> t;
  while ( t-- ) {
    int n;
    int flag = false;
    int result=0, rflag=0, m=0;
    cin >> n;

    cout << "Case #" << ++T << ": ";
    if ( n == 0 ) {
      cout << "INSOMNIA" << endl;
    }
    else {
      while ( 1023 != rflag ) {
        m++;
        int cp=0;
        int tmp = m*n;
        while(1) {
          cp=tmp%10;
          rflag |= 1 << cp;
          tmp/=10;
          if( tmp == 0 ) break;
        }
      }
      result = m*n;

      cout << result << endl;
    }
  }
  return 0;
}
