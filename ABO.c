#include "abo.h"
#include <stdlib.h>
#include <stdio.h>

Node* initializare() {
    return NULL;
}

Node* adauga(Node* radacina, int x) {
    if (radacina == NULL) {
        Node* nouNod = (Node*)malloc(sizeof(Node));
        if (nouNod == NULL) {
            printf("Eroare la alocarea memoriei!\n");
            exit(EXIT_FAILURE);
        }
        nouNod->data = x;
        nouNod->strang = NULL;
        nouNod->drept = NULL;
        return nouNod;
    }
    if (x < radacina->data) {
        radacina->strang = adauga(radacina->strang, x);
    } else if (x > radacina->data) {
        radacina->drept = adauga(radacina->drept, x);
    }
    return radacina;
}

Node* suprimare(Node* radacina, int x) {
    if (radacina == NULL) {
        return radacina;
    }
    if (x < radacina->data) {
        radacina->strang = suprimare(radacina->strang, x);
    } else if (x > radacina->data) {
        radacina->drept = suprimare(radacina->drept, x);
    } else {
        if (radacina->strang == NULL) {
            Node* temp = radacina->drept;
            free(radacina);
            return temp;
        } else if (radacina->drept == NULL) {
            Node* temp = radacina->strang;
            free(radacina);
            return temp;
        }
        Node* temp = radacina->drept;
        while (temp->strang != NULL) {
            temp = temp->strang;
        }
        radacina->data = temp->data;
        radacina->drept = suprimare(radacina->drept, temp->data);
    }
    return radacina;
}

Node* cautare(Node* radacina, int x) {
    if (radacina == NULL || radacina->data == x) {
        return radacina;
    }
    if (x < radacina->data) {
        return cautare(radacina->strang, x);
    }
    return cautare(radacina->drept, x);
}

void inordine(Node* radacina) {
    if (radacina != NULL) {
        inordine(radacina->strang);
        printf("%d ", radacina->data);
        inordine(radacina->drept);
    }
}

void preordine(Node* radacina) {
    if (radacina != NULL) {
        printf("%d ", radacina->data);
        preordine(radacina->strang);
        preordine(radacina->drept);
    }
}

void postordine(Node* radacina) {
    if (radacina != NULL) {
        postordine(radacina->strang);
        postordine(radacina->drept);
        printf("%d ", radacina->data);
    }
}
