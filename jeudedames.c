#include <stdio.h>

#define SIZE_GRID 10

void fill_grid(char tab[][SIZE_GRID]){
    for(int i=0;i<SIZE_GRID;i++){
        for(int j=0; j<SIZE_GRID; j++){
            if ((i+j)%2==0){
                tab[i][j]='X';
            }
            else if(((i+j)%2!=0)&&(i<=3)){
                tab[i][j]='B';
            }
            else if(((i+j)%2!=0)&&(i>=3)&&(i<=6)){
                tab[i][j]=' ';
            }

            else if(((i+j)%2!=0)&&(i>=6)){
                tab[i][j]='W';
            }
        }
    }
}



void display_grid(char tab[][SIZE_GRID]){
    int i,j;
    for(i=0; i<SIZE_GRID; i++){
        for(j=0; j<SIZE_GRID; j++){
            printf(" %c",tab[i][j]);
        }
        printf("\n");
        
        
    }
}






int main(void){
    char tab[SIZE_GRID][SIZE_GRID];
    fill_grid(tab);
    display_grid(tab);
    return 0;

}