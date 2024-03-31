

// Liste chainé

// GUTIERREZ Sebastien

#include <stdio.h>
#include <stdlib.h>

typedef struct _cell cell;

struct _cell {
    int donnee;
    cell* suivant;
};

cell* cell_create(int d) {
    cell* cellule = malloc(sizeof(cell));
    cellule->donnee = d;
    cellule->suivant = NULL;
    return cellule;
}

cell* head_insert(int d, cell* liste) {
    cell* newCell = cell_create(d);
    newCell->suivant = liste;
    return newCell;
}

cell* end_insert(int d, cell* liste) {
    cell* pL = liste;
    cell* newCell = cell_create(d);
    if(liste != NULL) {
        while(pL->suivant != NULL) {
            pL = pL->suivant;
        }
        pL->suivant = newCell;
        return liste;
    }
    return newCell;
}

cell* insert_at_pos(int d, int pos, cell* liste) {
    cell* newCell = cell_create(d);
    cell* ptr = liste;
    if(liste == NULL) return newCell;
    if(pos == 0) {
        newCell->suivant = liste;
        return newCell;
    }
    for(int i = 0; i < pos-1; i++) {
        if(ptr->suivant != NULL) ptr = ptr->suivant;
    }
    newCell->suivant = ptr->suivant;
    ptr->suivant = newCell;
    return liste;
}

void affichage(cell* liste) {
    while(liste != NULL) {
        printf("%d\n", liste->donnee);
        liste = liste->suivant;
    }
}

cell* delete_after_pos(int pos, cell* liste) {
    if (liste == NULL || liste->suivant == NULL) return liste;
    cell* temp = liste;
    cell* toDelete = NULL;
    if (pos == 0) {
        toDelete = liste->suivant;
        liste->suivant = toDelete->suivant;
    } else {
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->suivant;
        }
        if (temp == NULL || temp->suivant == NULL || temp->suivant->suivant == NULL) {
            return liste;
        }
        toDelete = temp->suivant;
        temp->suivant = toDelete->suivant;
    }
    free(toDelete);
    return liste;
}

int main() {
    cell* pL = NULL;

    pL = head_insert(3, pL);
    pL = head_insert(2, pL);
    pL = head_insert(1, pL);

    printf("Liste avant insertion :\n");
    affichage(pL);

    printf("\nListe après insertion :\n");
    pL = insert_at_pos(4, 2, pL);
    affichage(pL);

    printf("\nListe après suppression :\n");
    pL = delete_after_pos(1, pL); 
    affichage(pL);

    return 0;
}