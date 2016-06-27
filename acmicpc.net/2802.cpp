#include <iostream>
#include <algorithm>
#define MAX 100007

using namespace std;

int arr[257][257][257];
int sum[257][257][257];
int p[MAX][3];

int main() {
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    int a,b,c;
    cin >> a >> b >> c;
    arr[a+1][b+1][c+1]++;
    p[i][0] = a;
    p[i][1] = b;
    p[i][2] = c;
  }

  for(int i=1;i<=256;i++) {
    for(int j=1;j<=256;j++) {
      for(int k=1;k<=256;k++) {
        sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1] + sum[i-1][j-1][k-1] + arr[i][j][k];
      }
    }
  }

  int ri, rj, rk;
  int rmin, rmax, result;
  rmin=0; rmax=256;

  while(rmin <= rmax) {
    int mid = (rmin + rmax)/2;
    bool flag = false;
    for(int i=mid;!flag&&i<=256;i++) {
      for(int j=mid;!flag&&j<=256;j++) {
        for(int k=mid;!flag&&k<=256;k++) {
          int tmp = sum[i][j][k];
          if( i-mid-1 >= 0 ) tmp-=sum[i-mid-1][j][k];
          if( j-mid-1 >= 0 ) tmp-=sum[i][j-mid-1][k];
          if( k-mid-1 >= 0 ) tmp-=sum[i][j][k-mid-1];
          if( i-mid-1 >= 0 && j-mid-1 >= 0 ) tmp+=sum[i-mid-1][j-mid-1][k];
          if( i-mid-1 >= 0 && k-mid-1 >= 0 ) tmp+=sum[i-mid-1][j][k-mid-1];
          if( k-mid-1 >= 0 && j-mid-1 >= 0 ) tmp+=sum[i][j-mid-1][k-mid-1];
          if( i-mid-1 >= 0 && k-mid-1 >= 0 && j-mid-1 >= 0 ) tmp-=sum[i-mid-1][j-mid-1][k-mid-1];

          if (tmp >= m) {
            ri=i-1, rj=j-1, rk=k-1;
            flag=true;
          }
        }
      }
    }
    if( flag == true ) {
      result = mid;
      rmax = mid-1;
    }
    else {
      rmin = mid+1;
    }
  }
  cout << result << endl;
  for(int i=0;m>0&&i<n;i++) {
    if( ri-result <= p[i][0] && p[i][0] <= ri && rj-result <= p[i][1] && p[i][1] <= rj && rk-result <= p[i][2] && p[i][2] <= rk ) {
      cout << p[i][0] << " " << p[i][1] << " " << p[i][2] << endl;
      m--;
    }
  }

  return 0;
}
