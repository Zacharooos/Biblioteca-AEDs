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
    
    FILE *pasta_ler;
    pasta_ler = fopen("livros.txt", "r");

    if (pasta_ler == NULL){
        puts("Pasta não encontrada, criando diretório...");
        pasta_ler = fopen("livros.txt", "w+");
        fclose(pasta_ler);
    }

    int k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        //printf("%s\n", cadeia);

        aux = strtok(cadeia, "|");
        strcpy(lista_livros[k].nome, aux);

        aux = strtok(NULL ,"|");
        strcpy(lista_livros[k].categoria, aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].ano = (int)aux;

        aux = strtok(NULL ,"|");
        lista_livros[k].id = (int)aux;
        
        aux = strtok(NULL ,"|");
        lista_livros[k].pendencia = (bool)aux;
        
        printf("%d\n", k);
        printf("1 Nome.%s\n", lista_livros[0].nome);
        printf("Nome.%s\n", lista_livros[k].nome);
        printf("Categoria.%s\n", lista_livros[k].categoria);
        printf("Id.%d\n\n", lista_livros[k].id);

        k++;
        lista_livros = realloc(lista_livros, (k + 1) * sizeof(livro));
    }

    printf("Inside: Nome.%s\n", lista_livros[2].nome);
    printf("Inside: Categoria.%s\n", lista_livros[2].categoria);
    printf("Inside: Id.%d\n\n", lista_livros[2].id);
    
    fclose(pasta_ler);
    //Fim leitura livros



    free(lista_alunos);
    free(lista_livros);
    free(lista_recursos);
    
    return 0;
}