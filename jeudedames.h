#ifndef JEUDEDAMES_HEADER
#define JEUDEDAMES_HEADER

#define SIZE_GRID 10

// Initialisation de la grill et affichage
void fill_grid(char tab[][SIZE_GRID]);
void show_board(char board[][SIZE_GRID]);

// Deplacer un pion
int move_pawn(char tab[][SIZE_GRID],int pos_init[], int pos_final[],char color);

// Fonction de vérification
int is_pawn(char cas);
int is_void_case(char cas);
int is_end_game(char tab[][SIZE_GRID]);


void diagonal_pawns(char tab[][SIZE_GRID], int pos_init[], char color, int eatable_pawn[][6], int *size_eatable_pawn);

int pawn_suggested(char tab[][SIZE_GRID], char color, int eatable_pawn[][6]);

#endif