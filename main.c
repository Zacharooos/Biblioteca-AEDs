#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"
#include "crypto.h"

int main(){

    aluno *lista_alunos;
    livro *lista_livros;
    recursos *lista_recursos;

    lista_alunos = (aluno *) malloc(sizeof(aluno));
    lista_livros = (livro *) malloc(sizeof(livro));
    lista_recursos = (recursos *) malloc(sizeof(recursos));    

    // Inicio leitura livros
    char cadeia[100];
    
    free(lista_alunos);
    free(lista_livros);
    free(lista_recursos);

    return 0;
}