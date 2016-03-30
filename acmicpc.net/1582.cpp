#include <stdio.h>
#include <memory.h>

#define MAX 107
#define _max(a,b) (((a)>(b))?(a):(b))
#define _min(a,b) (((a)>(b))?(b):(a))

int arr[MAX][MAX];
int sum[MAX][MAX][2];
int opt[MAX][MAX][2];
int line[MAX];
int d[2][3007];

int main() {
  int N,M,K;
  scanf("%d %d %d", &N, &M, &K);
  for(int i=1;i<=N;i++) {
    char c;
    for(int j=1;j<=M;j++) {
      scanf(" %c", &c);
      if ( c == 'B' ) {
        arr[i][j] = 0;
      }
      else if ( c == 'W' ) {
        arr[i][j] = 1;
      }
      sum[i][j][0] = sum[i][j-1][0];
      sum[i][j][1] = sum[i][j-1][1];
      sum[i][j][arr[i][j]]++;
    }
  }

  int result=0;
  int toggle = 1;
  for(int i=1;i<=N;i++) {
    memset(opt, 0xff, sizeof(opt));
    memset(line, 0xff, sizeof(line));

    for(int k=1;k<=M;k++) {
      opt[1][k][0] = sum[i][M][0];
      opt[1][k][1] = sum[i][M][1];
    }

    line[0] = 0;
    line[1] = _max(opt[1][1][0], opt[1][1][1]);

    for(int k=2;k<=_min(M,K);k++) {
      int best = 0;
      for(int j=k;j<=M;j++) {
        opt[k][j][0] = opt[k][j-1][0];
        opt[k][j][1] = opt[k][j-1][1];

        if( opt[k-1][j-1][1] != -1 )
          opt[k][j][0] = _max( opt[k][j][0], opt[k-1][j-1][1] - (sum[i][M][1]-sum[i][j-1][1]) + (sum[i][M][0]-sum[i][j-1][0]) );

        if( opt[k-1][j-1][0] != -1 )
          opt[k][j][1] = _max( opt[k][j][1], opt[k-1][j-1][0] - (sum[i][M][0]-sum[i][j-1][0]) + (sum[i][M][1]-sum[i][j-1][1]) );

        best = _max(best, _max(opt[k][j][0], opt[k][j][1]));
      }
      line[k] = best;
    }

    memset(d[toggle],0,sizeof(d[toggle]));

    for(int k=1;k<=K;k++) {
      d[toggle][k] = d[1-toggle][k];
      for(int j=1;j<=M;j++) {
        if( k-j < 0 ) break;
        d[toggle][k] = _max(d[1-toggle][k-j]+line[j], d[toggle][k]);
      }
      result = _max(result, d[toggle][k]);
    }

    toggle = 1-toggle;
  }

  printf("%d\n", N*M-result);
  return 0;
}
