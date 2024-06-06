#ifndef ABO_H
#define ABO_H

typedef struct Node {
    int data;
    struct Node* strang;
    struct Node* drept;
} Node;

Node* initializare();
Node* adauga(Node* radacina, int x);
Node* suprimare(Node* radacina, int x);
Node* cautare(Node* radacina, int x);
void inordine(Node* radacina);
void preordine(Node* radacina);
void postordine(Node* radacina);

#endif /* ABO_H */
