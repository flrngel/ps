#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
  int t;
  string dic[10] = {"SIX", "SEVEN", "FIVE", "FOUR", "TWO", "ZERO", "THREE", "EIGHT", "NINE", "ONE"};
  int res[10] = {6,7,5,4,2,0,3,8,9,1};
  cin >> t;
  for(int test_case=0;test_case<t;test_case++) {
    string str;
    cin >> str;

    int mp[256];
    memset(mp, 0, sizeof(mp));
    
    for(int i=0;i<str.length();i++) {
      mp[str[i]]++;
    }

    string result = "";

    int cnt=0;
    for(int i=0;i<10;) {
      int emp[256];
      memset(emp, 0, sizeof(emp));
      int flag=1;
      for(int j=0;j<dic[i].length();j++) {
        if( mp[dic[i][j]] - emp[dic[i][j]] - 1 >= 0 ) {
          emp[dic[i][j]]++;
        }
        else {
          flag=0;
          break;
        }
      }
      if ( flag == 1 ) {
        for(int j=0;j<dic[i].length();j++) {
          mp[dic[i][j]]--;
          cnt++;
        }
        result += res[i]+'0';
      }
      else {
        i++;
      }
    }
    sort(result.begin(), result.end());
    printf("Case #%d: %s\n", test_case+1, result.c_str());
  }
  return 0;
}
