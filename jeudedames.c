#include <stdio.h>
#include <stdlib.h>

#include "jeudedames.h"

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"
#define YEL   "\x1B[33m"


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
        printf(YEL " %d" RESET, i);
        printf("|");
    }
    printf("\n");
    for (i=0;i<SIZE_GRID;i++){
        printf(YEL " %d" RESET, i);
        printf("|");
        for(j=0;j<SIZE_GRID;j++){
            if (board[i][j] == 'B'){
                printf(RED "B " RESET);
                printf("|");
            }
            if (board[i][j] == 'W'){
                printf(CYN "W " RESET);
                printf("|");
            }
            if (board[i][j] == 'X' || board[i][j] == ' '){
                printf("  |");
            }
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


int is_possible_move(char tab[][SIZE_GRID],int pos_init[], int pos_final[]){
    int nb_move_x = abs(pos_init[0]-pos_final[0]);
    int nb_move_y = abs(pos_init[1]-pos_final[1]);

    int index_x = (pos_init[0]+pos_final[0])/2;
    int index_y = (pos_init[1]+pos_final[1])/2;

    // soit on saute un pion adverse
    if ((abs(pos_final[1]-pos_init[1]) == 2) && (tab[index_y][index_x]!=tab[pos_init[1]][pos_init[0]])){
        return 1;
    }

    // soit on va dans une case juste a coté
    else if(nb_move_x == 1 && nb_move_y == 1){
        return 1;
    }
        
    else
        printf("Rentrez un coup valide ! (Deplacer un pion d'une seule case)\n");
        return 0;
}


int diagonal_pawns(char tab[][SIZE_GRID], int pos_init[], char color, int eatable_pawn[][4], int size_eatable_pawn){
      
    if(pos_init[1]+2 < SIZE_GRID && pos_init[1]+2 >= 0 
        && pos_init[0]+2 < SIZE_GRID && pos_init[0]+2 >= 0
        && tab[pos_init[1]+1][pos_init[0]+1]!=color
        && tab[pos_init[1]+1][pos_init[0]+1] != ' '){

            if(tab[pos_init[1]+2][pos_init[0]+2]==' '){
                eatable_pawn[size_eatable_pawn][0] = pos_init[0]+1;
                eatable_pawn[size_eatable_pawn][1] = pos_init[1]+1;
                eatable_pawn[size_eatable_pawn][2] = pos_init[0]+2;
                eatable_pawn[size_eatable_pawn][3] = pos_init[1]+2;
                size_eatable_pawn++;
            }
        }

    if(pos_init[1]+2 < SIZE_GRID && pos_init[1]+2 >= 0
        && pos_init[0]-2 < SIZE_GRID && pos_init[0]-2 >= 0
        && tab[pos_init[1]+1][pos_init[0]-1]!=color
        && tab[pos_init[1]+1][pos_init[0]-1]!=' '){

            if(tab[pos_init[1]+2][pos_init[0]-2]==' '){
                eatable_pawn[size_eatable_pawn][0] = pos_init[0]-1;
                eatable_pawn[size_eatable_pawn][1] = pos_init[1]+1;
                eatable_pawn[size_eatable_pawn][2] = pos_init[0]-2;
                eatable_pawn[size_eatable_pawn][3] = pos_init[1]+2;
                size_eatable_pawn++;
            }
        }
    
    if(pos_init[1]-2 < SIZE_GRID && pos_init[1]-2 >= 0
        && pos_init[0]+2 < SIZE_GRID && pos_init[0]+2 >= 0
        && tab[pos_init[1]-1][pos_init[0]+1]!=color
        && tab[pos_init[1]-1][pos_init[0]+1]!=' '){

            if(tab[pos_init[1]-2][pos_init[0]+2]==' '){
                eatable_pawn[size_eatable_pawn][0] = pos_init[0]+1;
                eatable_pawn[size_eatable_pawn][1] = pos_init[1]-1;
                eatable_pawn[size_eatable_pawn][2] = pos_init[0]+2;
                eatable_pawn[size_eatable_pawn][3] = pos_init[1]-2;
                size_eatable_pawn++;
            }
        }

    if(pos_init[1]-2 < SIZE_GRID && pos_init[1]-2 >= 0
        && pos_init[0]-2 < SIZE_GRID && pos_init[0]-2 >= 0
        && tab[pos_init[1]-1][pos_init[0]-1]!=color
        && tab[pos_init[1]-1][pos_init[0]-1]!=' '){

            if(tab[pos_init[1]-2][pos_init[0]-2]==' '){
                eatable_pawn[size_eatable_pawn][0] = pos_init[0]-1;
                eatable_pawn[size_eatable_pawn][1] = pos_init[1]-1;
                eatable_pawn[size_eatable_pawn][2] = pos_init[0]-2;
                eatable_pawn[size_eatable_pawn][3] = pos_init[1]-2;
                size_eatable_pawn++;
            }
        }
    
    return size_eatable_pawn;
}


int take_diagonal_pawns(char tab[][SIZE_GRID], int pos_init[], char color, int eatable_pawn[][4]){
    
    int size_eatable_pawn = 0;

    size_eatable_pawn = diagonal_pawns(tab, pos_init, color, eatable_pawn, size_eatable_pawn);

    if (size_eatable_pawn != 0) {
        printf("Le pion %c a la position (%d,%d) peut manger le pion en position : \n", color, pos_init[0], pos_init[1]);
        for(int i = 0; i<size_eatable_pawn; i++){
            printf(" - (%d,%d) deplacer votre pion a la case (%d,%d)\n", eatable_pawn[i][0],eatable_pawn[i][1],eatable_pawn[i][2],eatable_pawn[i][3]);
        }
    }
    return size_eatable_pawn;
}


void take_opponent_pawn(char tab[][SIZE_GRID], int pos_init[], int pos_final[], char color){
    int index_x = (pos_init[0]+pos_final[0])/2;
    int index_y = (pos_init[1]+pos_final[1])/2;
    tab[index_y][index_x] = ' ';    
}


int move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[], char color){
    int initial_case = tab[pos_init[1]][pos_init[0]];
    int final_case = tab[pos_final[1]][pos_final[0]];

    if ((is_void_case(final_case)) && (is_pawn(initial_case)) && (is_black_case(pos_final)) && (is_possible_move(tab, pos_init, pos_final))){
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


int pawn_suggested(char tab[][SIZE_GRID], char color, int eatable_pawn[][4]){

    int index[2];
    int possible_hit = 0;

    for (int x=0; x<SIZE_GRID; x++){
        for(int y=0; y<SIZE_GRID; y++){
            if (tab[y][x]==color){
                index[0] = x;
                index[1] = y;
                possible_hit += take_diagonal_pawns(tab, index, color, eatable_pawn);
            }
        }
    }
    if (possible_hit>0){
        return 1;
    }
    return 0;
}


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
