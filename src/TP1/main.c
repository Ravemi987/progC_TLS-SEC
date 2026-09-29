#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3
 

void Saisie(int row, int col, int tab[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Saisir la valeur ligne %d, col %d\n", i, j);
            scanf("%d", &(tab[i][j]));
        }
    }
}

void Saisiep(int row, int col, int *tab) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Saisir la valeur ligne %d, col %d\n", i, j);
            scanf("%d", tab + i * col + j);
        }
    }
}

void Affiche(int row, int col, int tab[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d \n", tab[i][j]);
        }
    }
    printf("\n");
}

void Saisie2(int row, int col, int **mat) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Saisir la valeur ligne %d, col %d\n", i, j);
            scanf("%d", &(mat[i][j]));
        }
    }
}

void Saisie2p(int row, int col, int **mat) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Saisir la valeur ligne %d, col %d\n", i, j);
            scanf("%d", *(mat + i) + j);
        }
    }
}

void Affiche2(int row, int col, int **mat) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d \n",  *(*(mat + i) + j));
        }
    }
    printf("\n");
}

void Init(int ***mat, int *row, int *col) {
    printf("Nombre de lignes : ");
    scanf("%d", row);
    printf("Nombre de colonnes : ");
    scanf("%d", col);

    *mat = malloc((*row) * sizeof(int *));

    for (int i = 0; i < *row; i++) {
        *(mat + i) = malloc((*col) * sizeof(int));
    }
}

void mainStatique(void) {
    int tab[ROW][COL];

    Saisie(ROW, COL, tab);
    printf("\n");
    Affiche(ROW, COL, tab);
    Saisiep(ROW, COL, (int *)tab);
    printf("\n");
    Affiche(ROW, COL, tab);
}

void mainDynamique(void) {
    int **mat;
    int row, col;

    Init(&mat, &row, &col);

    Saisie2(row, col, mat);
    printf("\n");
    Affiche2(row, col, mat);
    Saisie2p(row, col, mat);
    printf("\n");
    Affiche2(row, col, mat);

    for (int i = 0; i < row; i++) {
        free(mat[i]);
    }

    free(mat);
    *mat = NULL;
    mat = NULL;
}

int main(void) {
    mainDynamique();
    return 0;
}
