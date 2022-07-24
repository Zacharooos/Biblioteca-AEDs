#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "struct.h"
#include "crypto.h"
#include "funcoes_alunos.h"
#include "funcoes_livros.h"
#include "funcoes_recursos.h"

int main(){

    setlocale(LC_ALL, "Portuguese");

    aluno *lista_alunos;
    livro *lista_livros;
    recursos *lista_recursos;

    lista_alunos = (aluno *) malloc(sizeof(aluno));
    lista_livros = (livro *) malloc(sizeof(livro));
    lista_recursos = (recursos *) malloc(sizeof(recursos));    

    int id_data[3];

    FILE *pasta_ler;
    
    // Leitura do id_data
    char cadeia[100];
    pasta_ler = fopen("id_data.txt", "r");

    if (pasta_ler == NULL){
        puts("FatalError! Pasta não encontrada...");
        pasta_ler = fopen("id_data.txt", "w+");
        // Não funciona a escrita!
        fprintf(pasta_ler, '0\n');
        fprintf(pasta_ler, '0\n');
        fprintf(pasta_ler, '0\n');
        fclose(pasta_ler);
        puts("Reinicie o programa!");
        return 0;
    }

    for (int i = 0; i < 3; ++i){
        fgets(cadeia, 11, pasta_ler);
        id_data[i] = atoi(cadeia);
    }
    
    // Inicio leitura alunos
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
        lista_alunos[k].pendencia = atoi(aux);
        
        k++;
        lista_alunos = realloc(lista_alunos, (k + 1) * sizeof(aluno));
    }  
    
    fclose(pasta_ler);

    int tam_alunos = k;
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
        lista_livros[k].pendencia = (bool) atoi(aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].aluno_id = atoi(aux);
        
        k++;
        lista_livros = realloc(lista_livros, (k + 1) * sizeof(livro));
    }
    
    fclose(pasta_ler);

    int tam_livros = k;
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

        aux = strtok(cadeia ,"|");
        lista_recursos[k].id = atoi(aux);

        aux = strtok(NULL ,"|");
        lista_recursos[k].aluno_id = atoi (aux);

        aux = strtok(NULL ,"|");
        lista_recursos[k].tipo = aux[0];

        aux = strtok(NULL ,"|");
        lista_recursos[k].estado = (bool) atoi(aux);

        k++;
        lista_recursos = realloc(lista_recursos, (k + 1) * sizeof(recursos));
    }  

    fclose(pasta_ler);

    int tam_recursos = k;
    // Fim leitura recursos

    //Testes alunos (concluídos!)
    
    /*
    tam_alunos = criar_alunos(&lista_alunos, tam_alunos, id_data);
    tam_alunos = criar_alunos(&lista_alunos, tam_alunos, id_data);
    remover_alunos(lista_alunos, 5, tam_alunos);
    buscar_alunos(lista_alunos, 5, tam_alunos);
    remover_alunos(lista_alunos, 15, tam_alunos);
    mostrar_alunos(lista_alunos, tam_alunos);
    printf("%d\n", id_data[0]);
    */

    
    //testes livros (concluídos!)
    /*
    //tam_livros = criar_livros(&lista_livros, tam_livros, id_data);
    tam_livros = criar_livros(&lista_livros, tam_livros, id_data);
    puts("=!=");
    //remover_livros(lista_livros, 7, tam_livros);
    puts("=!=");
    registro_livros(lista_livros, lista_alunos, 6, 5, tam_livros, tam_alunos);

    buscar_livros(lista_livros, lista_alunos, 6, tam_livros, tam_alunos);
    buscar_alunos(lista_alunos, 5, tam_alunos);
    
    printf("\n D E V O L U Ç A O\n\n");

    deregistro_livros(lista_livros, lista_alunos, 6, 5, tam_livros, tam_alunos);

    buscar_livros(lista_livros, lista_alunos, 6, tam_livros, tam_alunos);
    buscar_alunos(lista_alunos, 5, tam_alunos);

    mostrar_livros(lista_livros, lista_alunos, tam_livros, tam_alunos);
    */

    //mostrar_recursos(lista_recursos, lista_alunos, tam_recursos, tam_alunos);
    //buscar_recursos(lista_recursos, lista_alunos, 1, tam_recursos, tam_alunos);
    //buscar_recursos(lista_recursos, lista_alunos, 2, tam_recursos, tam_alunos);
    //buscar_recursos(lista_recursos, lista_alunos, 4, tam_recursos, tam_alunos);
    
    /*
    tam_recursos = criar_recursos(&lista_recursos, tam_recursos);
    buscar_recursos(lista_recursos, lista_alunos, 5, tam_recursos, tam_alunos);
    remover_recursos(lista_recursos, 5, tam_recursos);
    buscar_recursos(lista_recursos, lista_alunos, 5, tam_recursos, tam_alunos);
    */
    /*
    tam_recursos = remover_recursos(lista_recursos, 4, tam_recursos);
    //remover_recursos(lista_recursos, 2, tam_recursos);
    mostrar_recursos(lista_recursos, lista_alunos, tam_recursos, tam_alunos);
    tam_recursos = remover_recursos(lista_recursos, 1, tam_recursos);
    tam_recursos = remover_recursos(lista_recursos, 3, tam_recursos);
    */

    //Testes recursos (sucesso!)
    /*
    mostrar_recursos(lista_recursos, lista_alunos, tam_recursos, tam_alunos);
    registro_recursos(lista_recursos, lista_alunos, 3, 1, tam_recursos, tam_alunos);
    buscar_recursos(lista_recursos, lista_alunos, 3, tam_recursos, tam_alunos);
    buscar_alunos(lista_alunos, 1, tam_alunos);
    printf("\n DEREGISTRO \n");
    deregistro_recursos(lista_recursos, lista_alunos, 3, 1, tam_recursos, tam_alunos);
    buscar_recursos(lista_recursos, lista_alunos, 3, tam_recursos, tam_alunos);
    buscar_alunos(lista_alunos, 1, tam_alunos);
    */

    mostrar_alunos(lista_alunos, tam_alunos);
    tam_alunos = remover_alunos(lista_alunos, 3, tam_alunos);
    mostrar_alunos(lista_alunos, tam_alunos);

    free(lista_alunos);
    free(lista_livros);
    free(lista_recursos);

    
    return 0;
}