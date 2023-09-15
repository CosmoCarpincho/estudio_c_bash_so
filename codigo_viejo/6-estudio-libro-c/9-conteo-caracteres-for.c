#include <stdio.h>

int main (void){

  double nc;

  for(nc = 1;getchar() != EOF; ++nc){
    printf("%.0f\n",nc);
  }

 return 0;
}
