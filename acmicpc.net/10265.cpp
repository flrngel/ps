#include <stdio.h>
#include <memory.h>
#define MAX 1007
#define _max(a,b) (((a)>(b))?(a):(b))
#define _min(a,b) (((a)>(b))?(b):(a))

int direction[MAX];
int check[MAX];
int cycle_card[MAX];
int graph_card[MAX];

int groups[MAX][2];
int d[2][MAX];

int uf(int i, int cnt) {
  //printf("%d:%d\n",i, cnt);
  if ( check[i] != -1 ) {
    if( cycle_card[direction[i]] != 0 ) {
      graph_card[direction[i]] = graph_card[direction[i]] + cnt;
    }
    else {
      cycle_card[direction[i]] = cnt - check[i];
      graph_card[direction[i]] = check[i];
    }
    return direction[i];
  }
  check[i] = cnt;
  direction[i] = uf(direction[i], cnt+1);
  return direction[i];
}

int main() {
  int n,m;
  memset(check, 0xff, sizeof(check));
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++) {
    scanf("%d", &direction[i]);
  }

  int group_cnt = 0;
  for(int i=1;i<=n;i++) {
    if( check[i] == -1 ) {
      uf(i, 0);
    }
  }

  for(int i=1;i<=n;i++) {
    if ( cycle_card[i] != 0 ) {
      //printf("%d %d>\n",cycle_card[i], graph_card[i]);
      groups[group_cnt][0] = cycle_card[i];
      groups[group_cnt][1] = graph_card[i];
      group_cnt++;
    }
  }

  //printf("%d\n",group_cnt);

  int result=0;
  int toggle=1;
  memset(d, 0xff, sizeof(d));
  d[0][0] = 0;


  for(int i=0;i<group_cnt;i++) {
    for(int j=0;j<=m;j++) {
      d[toggle][j] = d[1-toggle][j];
      if ( j-groups[i][0] >= 0 && d[1-toggle][j-groups[i][0]] > -1 ) {
        d[toggle][j] = _max( d[toggle][j], d[1-toggle][j-groups[i][0]]+groups[i][1] );
        result = _max( result, _min( m, d[toggle][j]+j) );
      }
    }
    toggle = 1-toggle;
  }

  printf("%d\n", result);
  return 0;
}
