#include <iostream>
#include <string>

using namespace std;

int main() {
  int T, Tn=0;
  cin >> T;
  while (T--) {
    int result=0;
    string str;
    cin >> str;

    for(int i=0;i<str.length();i++) {
      if ( str[i] == '+' ) {
        while( i < str.length() && str[i] == '+' ) i++;
        i--;
        continue;
      }
      else {
        if ( i > 0 ) {
          result++;
        }
        while( i < str.length() && str[i] == '-' ) i++;
        i--;
        result++;
      }
    }

    cout << "Case #" << ++Tn << ": " << result << endl;
  }
  return 0;
}
