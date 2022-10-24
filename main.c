#include <stdio.h>
#include <stdlib.h>

#include "jeudedames.h"


void game(char tab[][SIZE_GRID]){
    int pos_init[2];
    int pos_final[2];

    int is_possible_move = 0;
    int is_rafle = 1;

    int player = 1;

    fill_grid(tab);
    show_board(tab);

    while(is_end_game(tab) == 0){
        if (player == 1){
            is_possible_move = 0;
            is_rafle = 1;
            while (is_possible_move == 0 || is_rafle == 1){
                is_rafle = pawn_suggested(tab,'W');
                printf("%d", is_rafle);
                printf("Joueur blanc : Quel pion voulez-vous deplacer ? ");
                scanf("%d %d", &pos_init[0], &pos_init[1]);
                
                printf("Joueur blanc : Ou voulez vous le deplacer ? ");
                scanf("%d %d", &pos_final[0], &pos_final[1]);
                is_possible_move = move_pawn(tab,pos_init, pos_final,'W');
            }
            player = 2;
        }
        else{
           is_possible_move = 0;
           is_rafle = 1;
            while (is_possible_move == 0 || is_rafle == 1){
                is_rafle = pawn_suggested(tab,'B');
                printf("Joueur noir : Quel pion voulez-vous deplacer ? ");
                scanf("%d %d", &pos_init[0], &pos_init[1]);
                  
                printf("Joueur noir : Ou voulez vous le deplacer ? ");
                scanf("%d %d", &pos_final[0], &pos_final[1]);
                is_possible_move = move_pawn(tab,pos_init, pos_final,'B');
            }
            player = 1;
        }
        
        show_board(tab);

    }


}

int main(void){
    char tab[SIZE_GRID][SIZE_GRID];

    game(tab);
    
    return 0;

}