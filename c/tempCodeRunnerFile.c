#include<stdio.h>
#include<math.h>
typedef long long ll;

ll countDown(ll r, int n);

int main(){
  int n, k, i, size;

  scanf("%d", &n);
  scanf("%d", &k);

  ll start = 0, end = n*n, mid;

  while (end-start > 1){ // 0부터 n^2까지 개수 구하고 k보다 크면 end
    mid = (start + end) / 2;
    size = countDown(mid, n);
    // printf("st %lld, mid %lld, end %lld, size %d\n", start, mid, end, size);
    if(size >= k){
      end = mid;
    } else if(size < k){
      start = mid;
    }
  }
  printf("%lld\n", end);
}

ll countDown(ll r, int n){
  ll count = 0;

  for(int i=1; i<=n; i++) count += n<(r/i)?n:(r/i);

  return count;
}