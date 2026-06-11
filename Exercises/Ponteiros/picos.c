#include <stdio.h>

int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    int matriz[n][m];
    int (*pMat)[n][m] = &matriz;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &(*pMat)[i][j]);
        }
    }

          
  for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
    
    if(i == 0 && j == 0){
   
        if( (*pMat)[i][j] > (*pMat)[i+1][j+1] && (*pMat)[i][j] > (*pMat)[i][j+1] && 
            (*pMat)[i][j] >  (*pMat)[i+1][j])
             {
                printf("(%d, %d)\n)",i,j);

             }
    }
    else if(i == 0 && j == (m-1)){
        if( (*pMat)[i][j] > (*pMat)[i+1][j-1] && (*pMat)[i][j] > (*pMat)[i][j-1] && (*pMat)[i][j] > (*pMat)[i+1][j])
             {
            printf("(%d, %d)\n)",i,j);

             }

    }
    else if(i == (n-1) && j == 0 ){
        if(  (*pMat)[i][j] > (*pMat)[i-1][j] && (*pMat)[i][j] > (*pMat)[i-1][j+1] &&
             (*pMat)[i][j] >  (*pMat)[i][j+1])
             {
            printf("(%d, %d)\n",i,j);

             }
  
    }
    else if(i == (n-1) && j == (m-1)){
        if( 
            (*pMat)[i][j] > (*pMat)[i-1][j] && (*pMat)[i][j] > (*pMat)[i-1][j-1]&&
            (*pMat)[i][j] >  (*pMat)[i][j-1])
    {
            printf("(%d, %d)\n",i,j);

    }
   
    }
    else if((i == 0 && j > 0 && j < (m-1)))
    {
        if( (*pMat)[i][j] > (*pMat)[i][j-1] && (*pMat)[i][j] > (*pMat)[i][j+1] &&
            (*pMat)[i][j] > (*pMat)[i+1][j-1] && (*pMat)[i][j] > (*pMat)[i+1][j] &&
            (*pMat)[i][j] > (*pMat)[i+1][j+1]
          ){
            printf("(%d, %d)\n)",i,j);

        }
    }
     else if((i > 0 && j == 0 && i < (n-1)))
    {
        if( (*pMat)[i][j] > (*pMat)[i][j+1] && (*pMat)[i][j] > (*pMat)[i-1][j+1] &&
            (*pMat)[i][j] > (*pMat)[i+1][j+1] && (*pMat)[i][j] > (*pMat)[i+1][j] &&
            (*pMat)[i][j] > (*pMat)[i-1][j]
          ){
            printf("(%d, %d)\n)",i,j);

        }
    }
       else if((j > 0 && j < (m - 1) && i == (n-1)))
    {
        if( (*pMat)[i][j] > (*pMat)[i][j+1] && (*pMat)[i][j] > (*pMat)[i-1][j] &&
            (*pMat)[i][j] > (*pMat)[i-1][j-1] && (*pMat)[i][j] > (*pMat)[i][j-1] &&
            (*pMat)[i][j] > (*pMat)[i-1][j+1]
          ){
            printf("(%d, %d)\n)",i,j);
        }
    }
      else if((i > 0 && i < (n - 1) && j == (m - 1)))
    {
        if( (*pMat)[i][j] > (*pMat)[i-1][j] && (*pMat)[i][j] > (*pMat)[i-1][j-1] &&
            (*pMat)[i][j] > (*pMat)[i][j-1] && (*pMat)[i][j] > (*pMat)[i+1][j-1] &&
            (*pMat)[i][j] > (*pMat)[i+1][j]
          ){
            printf("(%d, %d)\n)",i,j);
        }
    }
    else if(((i > 0 && i < (n - 1)) && (j > 0 && j <( m - 1)))){
        if(
            (*pMat)[i][j] > (*pMat)[i+1][j] && (*pMat)[i][j] > (*pMat)[i-1][j] &&
            (*pMat)[i][j] > (*pMat)[i][j+1] && (*pMat)[i][j] > (*pMat)[i][j-1] && 
            (*pMat)[i][j] > (*pMat)[i+1][j+1] && (*pMat)[i][j]> (*pMat)[i-1][j-1] &&
            (*pMat)[i][j] > (*pMat)[i-1][j+1] && (*pMat)[i][j] > (*pMat)[i+1][j-1]
        ){
            printf("(%d, %d)\n)",i,j);

        }
    }
}
  }

    return 0;
}