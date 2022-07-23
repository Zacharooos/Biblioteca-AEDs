#ifndef FUNAL_H

#define FUNAL_H

#endif

//Função para reduzir o espaço de linhas necessário para checar a pendência
void pendencia_alunos(int pendencia){
    if(pendencia == 0){
        puts("Aluno sem pendências!");
    } else {
        puts("Aluno com pendencias!");
    }    
}

//! Função para realizar a busca de um determinado aluno através de seu id, recebe a referência do vetor, o id e o tam.
// Implementar buscabin
void buscar_alunos(aluno * lista_alunos, int id, int tam){
    for(int i = 0; i < tam; ++i){
        if(lista_alunos[i].id == id){
            printf("Aluno id [%d] encontrado!\n", lista_alunos[i].id);
            printf("Nome: %s\n", lista_alunos[i].nome);
            printf("Matrícula: %s\n", lista_alunos[i].matricula);
            pendencia_alunos(lista_alunos[i].pendencia);
            return;
        }
    }
    printf("id não cadastrado!\n");
    return;
}

//! Função para mostrar todas as matrículas
void mostrar_alunos(aluno * lista_alunos, int tam){
    for(int i = 0; i < tam; ++i){
        printf("Id: %d\n", lista_alunos[i].id);
        printf("Matrícula: %s\n", lista_alunos[i].matricula);
        printf("Nome: %s\n", lista_alunos[i].nome);
        pendencia_alunos(lista_alunos[i].pendencia);
        puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    }
}

//! Função para criação de novos alunos, cria um aluno apenas.
// Implementar checar matrícula
int criar_alunos(aluno **lista_alunos, int tam){
    *lista_alunos = realloc(*lista_alunos, (tam + 1) * sizeof(aluno));
    (*lista_alunos)[tam].id = tam+1;
    printf("Iniciado registro ID: %d\n", (*lista_alunos)[tam].id);
    
    printf("Inserir nome do aluno: ");
    scanf("%[^\n]s", (*lista_alunos)[tam].nome);

    printf("Inserir matricula do aluno: ");
    scanf("%s", (*lista_alunos)[tam].matricula);

    //checar matricula

    (*lista_alunos)[tam].pendencia = 0;

    puts("O cadastro foi um sucesso!");

    return tam+1;

}

int remover_alunos(){

    return 0;
}
 