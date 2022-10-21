#ifndef JEUDEDAMES_HEADER
#define JEUDEDAMES_HEADER

#define SIZE_GRID 10


void fill_grid(char tab[][SIZE_GRID]);
void display_grid(char tab[][SIZE_GRID]);
void move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[]);
int is_pawn(char cas);
int is_void_case(char cas);

#endif