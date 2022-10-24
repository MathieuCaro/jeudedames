#include <stdio.h>
#include <stdlib.h>

#include "jeudedames.h"


void game(char tab[][SIZE_GRID]){
    int pos_init[2];
    int pos_final[2];

    int possible_move = 0;

    int player = 1;

    fill_grid(tab);
    show_board(tab);

    while(is_end_game(tab) == 0){
        if (player == 1){
            possible_move = 0;
            while (possible_move == 0){
                printf("Joueur blanc : Quel pion voulez-vous deplacer ? ");
                scanf("%d %d", &pos_init[0], &pos_init[1]);
                diagonal_pawns(tab,pos_init,'W');
                
                printf("Joueur blanc : Ou voulez vous le deplacer ? ");
                scanf("%d %d", &pos_final[0], &pos_final[1]);
                possible_move = move_pawn(tab,pos_init, pos_final,'W');
            }
            player = 2;
        }
        else{
           possible_move = 0;
            while (possible_move == 0){
                printf("Joueur noir : Quel pion voulez-vous deplacer ? ");
                scanf("%d %d", &pos_init[0], &pos_init[1]);
                diagonal_pawns(tab,pos_init,'B');
                
                printf("Joueur noir : Ou voulez vous le deplacer ? ");
                scanf("%d %d", &pos_final[0], &pos_final[1]);
                possible_move = move_pawn(tab,pos_init, pos_final,'B');
            }
            player = 1;
        }
        
        show_board(tab);

    }


}

int main(void){
    char tab[SIZE_GRID][SIZE_GRID];
    /*
    int pos_init[] = {1,6};
    int pos_final[] = {3,4};
    int pos_actual[] = {2,3};
    int pos_final_w [] = {4,5};

    int pos_init_test[] = {3,2};
    int pos_final_test[] = {2,5};

    int pos_test [] = {3,6};
    fill_grid(tab);
    show_board(tab);
    move_pawn(tab,pos_init, pos_final,'W');
    move_pawn(tab,pos_init_test, pos_final_test,'B');
    move_pawn(tab,pos_actual,pos_final_w,'B');
    diagonal_pawns(tab, pos_test, 'W');
    show_board(tab);
    */

    game(tab);
    
    return 0;

}