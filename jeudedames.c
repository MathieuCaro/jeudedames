#include <stdio.h>
#include <stdlib.h>

#include "jeudedames.h"

void fill_grid(char tab[][SIZE_GRID]){
    for(int i=0;i<SIZE_GRID;i++){
        for(int j=0; j<SIZE_GRID; j++){
            if ((i+j)%2==0){
                tab[i][j]=' '; // ='X';
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

void show_board(char board[][SIZE_GRID]){
    int i,j;
    printf("  |");
    for (i=0;i<SIZE_GRID;i++){
        printf("%d |", i);
    }
    printf("\n");
    for (i=0;i<SIZE_GRID;i++){
        printf("%d |", i);
        for(j=0;j<SIZE_GRID;j++){
            if (board[i][j] == 'B'){
                printf("B |");
            }
            if (board[i][j] == 'W'){
                printf("W |");
            }
            if (board[i][j] == 'X' || board[i][j] == ' '){
                printf("  |");
            }
        }
        printf("\n");
    }
    printf("\n");
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

int is_black_case(int pos_final[]){
    if ((pos_final[0]+pos_final[1]) %2 == 1){
        return 1;
    }else {
        printf("Rentrez un coup valide ! (Deplacer vers une case noir)\n");
        return 0;
    }
}

int is_pawn(char cas){
    if ((cas == 'B' ) || (cas == 'W'))
        return 1;
    else{
        printf("%c",cas);
        printf("Rentrez un coup valide ! (Deplacer un pion)\n");
        return 0;
    } 
}

char diagonal_pawns(char tab[][SIZE_GRID], int pos_init[], char color){
    printf("Le pion %c a la position (%d,%d) peut manger le pion en position : \n", color, pos_init[0], pos_init[1]);
    if(color == 'B'){
        if(pos_init[1]+2 < SIZE_GRID && pos_init[0]+2 < SIZE_GRID && (tab[pos_init[1]+1][pos_init[0]+1]=='W')){
            if(tab[pos_init[1]+2][pos_init[0]+2]==' '){
                printf(" - (%d,%d) deplacer votre pion a la case (%d,%d)\n",pos_init[0]+1, pos_init[1]+1,pos_init[0]+2, pos_init[1]+2);
            }
        }

        if(pos_init[1]+2 < SIZE_GRID && pos_init[0]-2 < SIZE_GRID && tab[pos_init[1]+1][pos_init[0]-1]=='W'){
            if(tab[pos_init[1]+2][pos_init[0]-2]==' '){
                printf(" - (%d,%d) deplacer votre pion a la case (%d,%d)\n",pos_init[0]-1, pos_init[1]+1,pos_init[0]-2,pos_init[1]+2);
            }
        }

    }else if (color == 'W'){
        if(pos_init[1]-2 < SIZE_GRID && pos_init[0]+2 < SIZE_GRID && tab[pos_init[1]-1][pos_init[0]+1]=='B'){
            if(tab[pos_init[1]-2][pos_init[0]+2]==' '){
                printf(" - (%d,%d) deplacer votre pion a la case (%d,%d)\n",pos_init[0]+1, pos_init[1]-1,pos_init[0]+2,pos_init[1]-2);
            }
        }
        if(pos_init[1]-2 < SIZE_GRID && pos_init[0]-2 < SIZE_GRID && tab[pos_init[1]-1][pos_init[0]-1]=='B'){
            if(tab[pos_init[1]-2][pos_init[0]-2]==' '){
                printf(" - (%d,%d) deplacer votre pion a la case (%d,%d)\n",pos_init[0]-1, pos_init[1]-1,pos_init[0]-2,pos_init[1]-2);
            }
        }
    }
}

void take_opponent_pawn(char tab[][SIZE_GRID], int pos_init[], int pos_final[], char color){ // vérifier les coordonnées !
 
    if(color == 'B'){
        if((pos_init[0]-pos_final[0])==2){
            tab[pos_init[1]+1][pos_init[0]-1] = ' ';            
        }

        else{
            tab[pos_init[1]+1][pos_init[0]+1] = ' ';            
        }

    }else if (color == 'W'){
       if((pos_init[0]-pos_final[0])==2){
            tab[pos_init[1]-1][pos_init[0]-1] = ' ';            
        }

        else{
            tab[pos_init[1]-1][pos_init[0]+1] = ' ';            
        }
    }
}



int move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[], char color){
    int initial_case = tab[pos_init[1]][pos_init[0]];
    int final_case = tab[pos_final[1]][pos_final[0]];

    if ((is_void_case(final_case)) && (is_pawn(initial_case)) && (is_black_case(pos_final))){
        tab[pos_final[1]][pos_final[0]] = initial_case;
        tab[pos_init[1]][pos_init[0]] = ' ';
        if (abs(pos_final[1]-pos_init[1]) == 2)
            take_opponent_pawn(tab, pos_init, pos_final, color); 
        return 1;
    }
    else{
        return 0;
    }
       
}

// TODO Fonction qui suggère le pion à jouer


int is_end_game(char tab[][SIZE_GRID]){
    int black_pawn = 0;
    int white_pawn = 0;

    for (int x=0; x<SIZE_GRID; x++){
        for(int y=0; y<SIZE_GRID; y++){
            if (tab[y][x]=='B'){
                black_pawn = 1;
            }
            else if (tab[y][x]=='W'){
                white_pawn = 1;
            }

            if (black_pawn+white_pawn==2){
                return 0;
            }
    
        }
    }
    if (black_pawn == 0){
        printf("Victoire des pions blancs");
    }
    else{
        printf("Victoire des pions noirs");
    }
}
