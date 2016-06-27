#include <iostream>
#include <string>
#include <algorithm>

#define _max(a,b) (((a)>(b))?(a):(b))
#define _min(a,b) (((a)<(b))?(a):(b))
#define _abs(a) (((a)>(0))?(a):-(a))

using namespace std;

int n;
string sleft, sright;

long long result_diff;
long long result_left, result_right;

void solve(int i, long long left, long long right, int balance) {
  if( balance == -1 && left < right ) return;
  if( balance == 1 && left > right ) return;
  if( balance == 0 && left != right ) return;
  

  if ( i == n ) {
    long long diff = _abs(left - right);
    if ( diff < result_diff ) {
      result_diff = diff;
      result_left = left;
      result_right = right;
    }
    else if ( diff == result_diff && left < result_left ) {
      result_diff = diff;
      result_left = left;
      result_right = right;
    }
    else if ( diff == result_diff && left == result_left && right < result_right ) {
      result_diff = diff;
      result_left = left;
      result_right = right;
    }
    return;
  }

  long long l = ((sleft[i] == '?')?-1:(sleft[i]-'0'));
  long long r = ((sright[i] == '?')?-1:(sright[i]-'0'));
  long long a,b;

  if ( balance == 0 ) {
    if ( l == -1 && r == -1 ) {
      a = b = 0;
    }
    else if ( l > -1 && r > -1 && l != r ) {
      a = l;
      b = r;
      if ( a > b ) {
        solve(i+1, left*10LL+a, right*10LL+b, -1);
      }
      else {
        solve(i+1, left*10LL+a, right*10LL+b, 1);
      }
      return;
    }
    else {
      if ( r != -1 ) a=b=r;
      if ( l != -1 ) a=b=l;
    }
    //cout << "a:" << a <<  " b:" << b << "     l:" << l << " r:" << r << endl;
    solve(i+1, left*10LL+a, right*10LL+b, 0);
    if( a != 9 && r == -1) {
      solve(i+1, left*10LL+a, right*10LL+b+1, 1);
    }
    if( a != 0 && r == -1 ) {
      solve(i+1, left*10LL+a, right*10LL+b-1, -1);
    }
    if( b != 9 &&  l == -1 ) {
      solve(i+1, left*10LL+a+1, right*10LL+b, -1);
    }
    if( b != 0 && l == -1) {
      solve(i+1, left*10LL+a-1, right*10LL+b, 1);
    }
  }
  else if ( balance == -1 ) {
    a=0;
    b=9;
    if( l != -1 ) a=l;
    if( r != -1 ) b=r;

    solve(i+1, left*10LL+a, right*10LL+b, -1);
  }
  else {
    a=9;
    b=0;
    if( l != -1 ) a=l;
    if( r != -1 ) b=r;

    solve(i+1, left*10LL+a, right*10LL+b, 1);
  }
}

int main() {
  int t;
  cin >> t;
  for(int test_case=1;test_case<=t;test_case++) {
    result_diff = 9223372036854775806LL;

    cin >> sleft >> sright;
    n = sleft.length();

    solve(0, 0, 0, 0);
    solve(0, 0, 0, 1);
    solve(0, 0, 0, 2);

    string srl="", srr="";
    int cnt=0;
    cnt=n;
    long long cr = result_left;
    while(cr>=0LL) {
      cr=cr/10LL;
      cnt--;
      if( cr == 0LL ) break;
    }
    while(cnt>0){ srl+="0"; cnt--; }

    cnt=n;
    cr = result_right;
    while(cr>=0LL) {
      cr=cr/10LL;
      cnt--;
      if( cr == 0LL ) break;
    }
    while(cnt>0){ srr+="0"; cnt--; }

    cout << "Case #" << test_case << ": " << srl << result_left << " " << srr << result_right << endl;
  }
  return 0;
}
