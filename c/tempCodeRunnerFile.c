#include<stdio.h>
/*
  1 최대값
  1.5 st > end면 리턴
  2 이분
  3 개수 측정
  4 넘으면 길이 늘리고 적으면 이분
  nlogn
*/
int main(){
  unsigned int n, aftN, i, max = 0, count, maxL=0, l, change;
  scanf("%d %d", &n, &aftN);
  unsigned int ls[n];
  for (i=0; i<n; i++){
    scanf("%d", &ls[i]);
    if(ls[i] > max) max = ls[i];
  }
  l = max;
  change = max/2 + max%2;
  while (1){
    count = 0;
    for (i=0; i<n; i++)
      count += ls[i]/l;
      
    // printf("%d %d %d %d\n", l, count, change, maxL);
    
    if(count >= aftN){
      if(l > maxL)
        maxL = l;
      l += change;
    } else l -= change;

    if(change>1) change = change/2;
    else if(change == 1){ //!
      while (1){
        count = 0;
        for (i=0; i<n; i++)
          count += ls[i]/l;
          
        // printf("%d %d %d %d\n", l, count, change, maxL);
        
        if(count >= aftN){
          if(l > maxL)
            maxL = l;
          l += change;
        } else{
          l -= change;
          change = 0;
          break;
        }
      }
    }
    else if (change == 0) break;
  }
  printf("%d\n", maxL);
}