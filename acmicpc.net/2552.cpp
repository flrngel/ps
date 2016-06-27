#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#define pr pair<int,int>
#define MAX 37

using namespace std;

vector<pr> arr;
int d[MAX][MAX];

int main() {
  int n,m;
  cin >> n;

  arr.push(make_pair(0,0));
  for(int i=0;i<n;i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(make_pair(n-tmp,i));
    for(int j=0;j<=n;j++) {
      d[i][j]=1;
    }
  }
  cin >> m;

  sort(arr.begin(), arr.end());

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
    }
  }
  return 0;
}
