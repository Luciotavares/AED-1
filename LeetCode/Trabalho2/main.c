#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} pilha;

typedef struct {
    Node* first;
    Node* last;
} fila;

/* pilha dos sanduiches */
void push(pilha* p, int valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->info = valor;
    newNode->next = p->top;
    p->top = newNode;
}

/* pilha dos sanduiches */
void pop(pilha* p) {

    Node* poppedNode = p->top;
    p->top = p->top->next;
    free(poppedNode);
}

/* fila alunos */
void pushalunos(fila* pfila, int valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = valor;
    newNode->next = NULL;

    if (pfila->last == NULL)
        pfila->first = newNode;
    else
        pfila->last->next = newNode;

    pfila->last = newNode;
}
void popluno(fila* pfila, int valor) {
    Node *pnodo;

    pnodo = pfila->first;
    valor =  pfila->first->info;
    pfila->first = pfila->first->next;

    free(pnodo);
}
int filavazia(fila* pfila) {
    return pfila->first == NULL;
}

int countStudents(int* alunos, int alunosSize, int* sanduiches, int sanduichesSize) {
    pilha sanduiche;
    sanduiche.top = NULL;

    fila aluno;
    aluno.first = NULL;
    aluno.last = NULL;

    for (int i = 0; i < sanduichesSize; i++) {
        push(&sanduiche, sanduiches[i]);
    }

    for (int i = 0; i < alunosSize; i++) {
        pushalunos(&aluno, alunos[i]);
    }

    int alunosIncapazesDeComer = 0;

    while (!filavazia(&aluno)) {
        int alunoAtual = aluno.first->info;
        int sanduicheAtual = sanduiche.top->info;

        if (alunoAtual == sanduicheAtual) {
            // O aluno pega o sanduíche correspondente
            pop(&sanduiche);
            popluno(&aluno, alunoAtual);
            alunosIncapazesDeComer = 0; // Reinicia a contagem de alunos incapazes de comer
        } else {
            // O aluno não pega o sanduíche correspondente, vai para o final da fila
            popluno(&aluno, alunoAtual);
            pushalunos(&aluno, alunoAtual);
            alunosIncapazesDeComer++;

            // Se todos os alunos na fila não puderem comer, saímos do loop
            if (alunosIncapazesDeComer == alunosSize) {
                break;
            }
        }
    }


    return alunosIncapazesDeComer;
}
int main() {
    int alunos[] = {1,1,1,0,0,1};
    int sanduiches[] = {1,0,0,0,1,1};
    /*esse funçao para pegar o tamanho tive que pesquisar e pegar na internet*/
    int alunosSize = sizeof(alunos) / sizeof(alunos[0]);
    int sanduichesSize = sizeof(sanduiches) / sizeof(sanduiches[0]);
    int alunosIncapazesDeComer = countStudents(alunos, alunosSize, sanduiches, sanduichesSize);
    printf("Número de alunos que não conseguem comer: %d\n", alunosIncapazesDeComer);

    return 0;
}

