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

    char cadeia[100];
    // Inicio leitura alunos
    
    FILE *pasta_ler;
    pasta_ler = fopen("alunos.txt", "r");

    if (pasta_ler == NULL){
        puts("Pasta não encontrada, criando diretório...");
        pasta_ler = fopen("alunos.txt", "w+");
        fclose(pasta_ler);
        return 0;
    }

    int k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        aux = strtok(cadeia, "|");
        strcpy(lista_alunos[k].nome, aux);

        aux = strtok(NULL ,"|");
        strcpy(lista_alunos[k].matricula, aux);

        aux = strtok(NULL ,"|");
        lista_alunos[k].id = atoi(aux);

        
        aux = strtok(NULL ,"|");
        lista_alunos[k].pendencia = (bool)aux;
        
        printf("Nome -> %s\n", lista_alunos[k].nome);
        k++;
        lista_alunos = realloc(lista_alunos, (k + 1) * sizeof(aluno));
    }  
    
    fclose(pasta_ler);

    // Fim leitura alunos
    // Inicio leitura livros
    
    pasta_ler = fopen("livros.txt", "r");

    if (pasta_ler == NULL){
        puts("Pasta não encontrada, criando diretório...");
        pasta_ler = fopen("livros.txt", "w+");
        fclose(pasta_ler);
    }

    k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        aux = strtok(cadeia, "|");
        strcpy(lista_livros[k].nome, aux);

        aux = strtok(NULL ,"|");
        strcpy(lista_livros[k].categoria, aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].ano = atoi(aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].id = atoi(aux);
        
        aux = strtok(NULL ,"|");
        lista_livros[k].pendencia = (bool)aux;
        
        k++;
        lista_livros = realloc(lista_livros, (k + 1) * sizeof(livro));
    }
    
    fclose(pasta_ler);

    //Fim leitura livros
    //Inicio leitura recursos

    pasta_ler = fopen("recursos.txt", "r");

    if (pasta_ler == NULL){
        puts("Pasta não encontrada, criando diretório...");
        pasta_ler = fopen("recursos.txt", "w+");
        fclose(pasta_ler);
        return 0;
    }

    k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        printf("%s\n", cadeia);

        aux = strtok(cadeia ,"|");
        lista_recursos[k].id = (int)aux;

        aux = strtok(NULL ,"|");
        lista_recursos[k].aluno_id = (int)aux;

        aux = strtok(NULL ,"|");
        lista_recursos[k].tipo = aux[0];

        aux = strtok(NULL ,"|");
        lista_recursos[k].estado = (bool) atoi(aux);

        k++;
        lista_recursos = realloc(lista_recursos, (k + 1) * sizeof(recursos));
    }  

    fclose(pasta_ler);

    // Fim leitura recursos

    free(lista_alunos);
    free(lista_livros);
    free(lista_recursos);
    
    return 0;
}