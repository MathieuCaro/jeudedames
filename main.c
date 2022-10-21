#include <stdio.h>

#include "jeudedames.h"



int main(void){
    char tab[SIZE_GRID][SIZE_GRID];
    int pos_init[] = {0,3};
    int pos_final[] = {0,4};
    fill_grid(tab);
    display_grid(tab);
    move_pawn(tab,pos_init, pos_final);
    display_grid(tab);
    return 0;

}