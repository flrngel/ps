#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

pair<ll,ll> arr[100007];

int main() {
  ll n,m;
  cin >> n >> m;
  for(ll i=0;i<n;i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr,arr+n);

  ll result=arr[0].second;
  for(ll i=1;i<n;i++) {
    if( arr[i-1].second < arr[i].second ) {
      result += arr[i].second - arr[i-1].second;
    }
  }

  cout << result << endl;
}
