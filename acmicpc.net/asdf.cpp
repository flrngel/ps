#include <iostream>
#include <string>

using namespace std;

int main () {
  string a = "dab";
  string b = "abc";
  bool flag = ( a.find(b) != string::npos );
  cout << (flag?"true":"false") << endl;
  cout << a.size() << a.length() << endl;
  return 0;
}
