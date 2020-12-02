#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct deques{
    int dado;
    struct deques *ante;
    struct deques *prox;
}DEQUE;

DEQUE* iniciaDeque() {
    DEQUE *d = (DEQUE*) malloc(sizeof(DEQUE));
    d->ante = NULL;
    d->prox = NULL;
    // d->dado = 10;
    return d;
}

bool adicionaInicio(DEQUE *d, int x){
    DEQUE *adDeque = (DEQUE*) malloc(sizeof(DEQUE));
    DEQUE *aux = d->prox;
    adDeque->dado = x;
    adDeque->prox = d->prox;
    adDeque->ante = d;
    d->prox = adDeque;
    if( aux == NULL)
        return d;
    aux->ante = adDeque;    
    return true;
}
bool adicionaFim(DEQUE *d, int x) {
    DEQUE *adDeque2 = (DEQUE*) malloc(sizeof(DEQUE));

    adDeque2->dado = x;
    while(d->prox != NULL){
        d = d->prox;
    }
    adDeque2->prox = NULL;
    adDeque2->ante = d;
    d->prox = adDeque2;
    return true;
}

void exibeDequeED(DEQUE *d){//exibe da esquerda pra direita
    DEQUE* apontar = d->prox;

    while(apontar != NULL){ //ou != d->ante
        cout << "'" ;
        cout << apontar->dado;
        cout << "' ";
        apontar = apontar->prox;
    }
    cout << endl;
}
void exibeDequeDE(DEQUE *d){//exibe da direita pra esquerda
    while(d->prox != NULL){
        d = d->prox;
    }
    DEQUE* apontar = d;
    while(apontar->ante != NULL){ // ou != NULL
        cout << "'" ;
        cout << apontar->dado;
        cout << "' ";
        apontar = apontar->ante;
    }
    cout << endl;
}

bool removeInicio(DEQUE *d) {
    DEQUE *inicio;
    inicio = d->prox;
    d->prox = inicio->prox;
    free(inicio);
    return true;
}

bool removeFim(DEQUE *d) {
    DEQUE *fim;
    DEQUE *anterior;
    fim = d;

    while(fim->prox != NULL){
        anterior = fim;
        fim = fim->prox;
    }
    anterior->prox = NULL;
    free(fim);
    return true;
}

int main() {

    DEQUE *deque = iniciaDeque();
    adicionaInicio(deque, 1);
    adicionaInicio(deque, 2);
    adicionaInicio(deque, 3);
    adicionaFim(deque, 5);
    adicionaFim(deque, 6);
    adicionaFim(deque, 7);
    // // removeInicio(deque); //remover ta funcionando
    // removeInicio(deque);
    // removeFim(deque);
    cout << "Esquerda para a direita (lado normal)" << endl;
    exibeDequeED(deque);
    cout << "direita para a esquerda "<< endl;
    exibeDequeDE(deque);
    return 0;
}