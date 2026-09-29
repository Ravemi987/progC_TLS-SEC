#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Partie 1 */

int Q1(int n) {
    return n << 1;
}

uint32_t Q2(uint32_t a, uint32_t b) {
    uint32_t c = ((a >> 16) & 0xFFFF) | ((b & 0xFFFF) << 16);
    return c;
}

uint32_t Q3(uint32_t a, uint32_t b) {
    return (a ^ b) == (1 << 10);
}

int bitcount(int n) {
    int x = n;
    int count = 0;

    while (x != 0) {
        if (x & 0x1) count++;
        x = x >> 1;
    }

    return count;
}

int Partie1(void) {
    printf("Question 1 : %d\n", Q1(4));
    printf("Question 2 : %x\n", Q2(0x11223344, 0x55667788));
    printf("Question 3 : %x\n", Q3(0x00000000, 0x00000400));
    printf("Question 4 : %d\n", bitcount(0b10110011));
}

/* Partie 2 */

int EcritFichier(FILE *fich_lect, char *nom_fich_ecrit, int nb_lignes) {
    FILE *fich_ecrit = fopen(nom_fich_ecrit, "w");
    if (fich_ecrit == NULL) return -1;

    char *buff = calloc(2048, sizeof(char));

    int i = 0;

    while (i < nb_lignes) {
        fgets(buff, 2048, fich_lect);
        fprintf(fich_ecrit, "%s", buff);
        i++;
    }

    fclose(fich_ecrit);
    free(buff);

    return 0;
}

int CoupeFichier(char *nom_fich_lect, char *nom_fich_ecrit_base, int nb_lignes) {
    FILE *fich_lect = fopen(nom_fich_lect, "r");

    size_t len = strlen(nom_fich_ecrit_base);
    char *buff = malloc((len + 2) * sizeof(char));
    buff[len + 1] = '\0';

    for (int i = 0; i < 3; i++) {
        sprintf(buff, "%s.%d.txt", nom_fich_ecrit_base, i);
        int rc = EcritFichier(fich_lect, buff, nb_lignes);
        if (rc == -1) return -1;
    }

    fclose(fich_lect);
    free(buff);

    return 0;
}

int Saisie(char *nom_fich_lect, char *nom_fich_ecrit_base, int *nb_lignes) {
    printf("Saisir le nom du fichier a lire : ");
    scanf("%s", nom_fich_lect);
    printf("Saisir le nom du fichier a ecrire : ");
    scanf("%s", nom_fich_ecrit_base);
    printf("Saisir le nombre de lignes : ");
    scanf("%d", nb_lignes);

    return 0;
}

int Partie2(int argc, char *argv[]) {
    if (argc != 5) {
        perror("Nombre d'arguments invalide");
        return -1;
    }

    char *in = malloc(256 * sizeof(char));
    char *out = malloc(256 * sizeof(char));
    int nb_lignes;

    sprintf(in, "%s", argv[3]);
    sprintf(out, "%s", argv[4]);
    nb_lignes = atoi(argv[2]);

    int rc = CoupeFichier(in, out, nb_lignes);

    free(in);
    free(out);

    return rc;
}

/* Partie 3 */

typedef struct s_livre {
    char auteur[256];
    char titre[256];
    int annee;
} Livre;

typedef struct s_cell {
    struct s_cell *next_cell;
    struct s_cell *next_auteur;
    struct s_cell *next_annee;
} Cell;

typedef struct s_file {
    struct s_cell *head;
    struct s_cell *tail;
    int size;
} File;

File *init_file(void) {
    File *f = malloc(sizeof(File));
    if (f == NULL) return NULL;

    f->head = NULL;
    f->tail = NULL;
    f->size = 0;

    return f;
}

int main(int argc, char *argv[]) {
    return Partie2(argc, argv);
}
