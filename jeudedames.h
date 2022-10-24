#ifndef JEUDEDAMES_HEADER
#define JEUDEDAMES_HEADER

#define SIZE_GRID 10


void fill_grid(char tab[][SIZE_GRID]);
void display_grid(char tab[][SIZE_GRID]);
int move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[],char color);
int is_pawn(char cas);
int is_void_case(char cas);
void show_board(char board[][SIZE_GRID]);
char diagonal_pawns(char tab[][SIZE_GRID], int pos_init[], char color);
int is_end_game(char tab[][SIZE_GRID]);

#endif