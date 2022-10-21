#include <stdio.h>

#include "jeudedames.h"

void fill_grid(char tab[][SIZE_GRID]){
    for(int i=0;i<SIZE_GRID;i++){
        for(int j=0; j<SIZE_GRID; j++){
            if ((i+j)%2==0){
                tab[i][j]='X';
            }
            else if(((i+j)%2!=0)&&(i<=3)){
                tab[i][j]='B';
            }
            else if(((i+j)%2!=0)&&(i>=3)&&(i<=5)){
                tab[i][j]=' ';
            }

            else if(((i+j)%2!=0)&&(i>=5)){
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
    printf("\n");
}

int is_void_case(char cas){
    if (cas ==' '){
        return 1;
    }else {
        printf("Rentrez un coup valide ! (Deplacer vers une case vide)\n");
        return 0;
    }
}

int is_pawn(char cas){
    if ((cas == 'B' ) || (cas == 'W'))
        return 1;
    else{
        printf("Rentrez un coup valide ! (Depalcer un pion)\n");
        return 0;
    } 
}

void move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[]){
    int initial_case = tab[pos_init[1]][pos_init[0]];
    int final_case = tab[pos_final[1]][pos_final[0]];

    if ((is_void_case(final_case)) && (is_pawn(initial_case))){
        tab[pos_final[1]][pos_final[0]] = initial_case;
        tab[pos_init[1]][pos_init[0]] = ' ';
    }
        
}
