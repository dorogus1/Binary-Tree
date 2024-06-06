#include <stdio.h>
#include "abo.h"

int main() {
    Node* radacina = initializare();
    int optiune, valoare;

    do {
        printf("\nMeniu:\n");
        printf("1. Adauga un nod in arbore\n");
        printf("2. Sterge un nod din arbore\n");
        printf("3. Cauta un nod in arbore\n");
        printf("4. Afiseaza arborele in inordine\n");
        printf("5. Afiseaza arborele in preordine\n");
        printf("6. Afiseaza arborele in postordine\n");
        printf("0. Iesire\n");

        printf("Alege o optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceti valoarea de adaugat: ");
                scanf("%d", &valoare);
                radacina = adauga(radacina, valoare);
                break;
            case 2:
                printf("Introduceti valoarea de sters: ");
                scanf("%d", &valoare);
                radacina = suprimare(radacina, valoare);
                break;
            case 3:
                printf("Introduceti valoarea de cautat: ");
                scanf("%d", &valoare);
                if (cautare(radacina, valoare) != NULL) {
                    printf("Valoarea %d a fost gasita in arbore.\n", valoare);
                } else {
                    printf("Valoarea %d nu a fost gasita in arbore.\n", valoare);
                }
                break;
            case 4:
                printf("Arborele in inordine: ");
                inordine(radacina);
                printf("\n");
                break;
            case 5:
                printf("Arborele in preordine: ");
                preordine(radacina);
                printf("\n");
                break;
            case 6:
                printf("Arborele in postordine: ");
                postordine(radacina);
                printf("\n");
                break;
            case 0:
                printf("Programul se inchide.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 0);

    return 0;
}
