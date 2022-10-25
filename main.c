#include <stdio.h>
#include <stdlib.h>

#include "jeudedames.h"

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"


void select_pawns(int pos_init[2], int pos_final[2], char color){
    if (color == 'W'){
        printf(CYN "Joueur blanc : Quel pion voulez-vous deplacer ? " RESET);
        scanf("%d %d", &pos_init[0], &pos_init[1]);
                    
        printf(CYN "Joueur blanc : Ou voulez vous le deplacer ? " RESET);
        scanf("%d %d", &pos_final[0], &pos_final[1]);
    }
    else {
        printf(RED "Joueur noir : Quel pion voulez-vous deplacer ? " RESET);
        scanf("%d %d", &pos_init[0], &pos_init[1]);
                    
        printf(RED "Joueur noir : Ou voulez vous le deplacer ? " RESET);
        scanf("%d %d", &pos_final[0], &pos_final[1]);
    }
}

void game(char tab[][SIZE_GRID]){
    int pos_init[2];
    int pos_final[2];

    int is_possible_move = 0; //FALSE
    int is_rafle = 1; // TRUE
    int eatable_pawn[20][4]; // position du pion mangeable puis position voulu pour manger le pion

    char player = 'W';

    fill_grid(tab);
    show_board(tab);

    while(is_end_game(tab) == 0){
        is_possible_move = 0;
        is_rafle = pawn_suggested(tab, player, eatable_pawn);

        if (is_rafle == 0){// Pas de rafle possible
            while (is_possible_move == 0){
                        select_pawns(pos_init, pos_final, player);
                        is_possible_move = move_pawn(tab,pos_init, pos_final, player);
                    }
        }
        else{ // Rafle possible
            while (is_possible_move == 0 || is_rafle == 1){ // Si la rafle est possible
                select_pawns(pos_init, pos_final, player);
                for(int i=0; i<20; i++){
                    if (pos_final[0] == eatable_pawn[i][2] && pos_final[1] == eatable_pawn[i][3]){
                        is_possible_move = move_pawn(tab,pos_init, pos_final, player);
                        break;
                    }       
                }                   
                is_rafle = pawn_suggested(tab, player, eatable_pawn);
            }
        }      

        if (player == 'W')
            player = 'B';
        else 
            player = 'W';
        
        show_board(tab);
    }
}

int main(void){
    char tab[SIZE_GRID][SIZE_GRID];

    game(tab);
    
    return 0;

}