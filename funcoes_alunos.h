#ifndef FUNAL_H

#define FUNAL_H

#endif

// Seção de Funções implícitas de _alunos

//! Função para reduzir o espaço de linhas necessário para checar a pendência
void pendencia_alunos(int pendencia){
    if(pendencia == 0){
        puts("Aluno sem pendências!");
    } else {
        puts("Aluno com pendencias!");
    }    
}

//! Função buscaBinária modificada, procura alunos por id
int buscaBin_alunos(aluno *v, int id, int tam){
	int inicio = 0, fim = tam, i_meio, v_meio;
	while(inicio <= fim){
		i_meio = (fim+inicio)/2;
		v_meio = v[i_meio].id;

		if (id == v_meio){
			return i_meio;
		}

		if (id < v_meio){
			fim = i_meio - 1;
		}
	
		if (id > v_meio){
			inicio = i_meio + 1;
		}

	}
	return -1; 
}

// Sessão de funções explícitas de _alunos

//! Função para realizar a busca de um determinado aluno através de seu id, recebe a referência do vetor, o id e o tam.
// Implementar buscabin
void buscar_alunos(aluno *lista_alunos, int id, int tam){
    int i = buscaBin_alunos(lista_alunos, id, tam);
    if (i >= 0){
        printf("Aluno id [%d] encontrado!\n", lista_alunos[i].id);
        printf("Nome: %s\n", lista_alunos[i].nome);
        printf("Matrícula: %s\n", lista_alunos[i].matricula);
        pendencia_alunos(lista_alunos[i].pendencia);

    } else {

        printf("id não cadastrado!\n");
    }
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

    fflush(stdin);
    //checar matricula

    (*lista_alunos)[tam].pendencia = 0;

    puts("O cadastro foi um sucesso!");

    return tam+1;

}

//! Função para remover alunos, define id do aluno como -1;
void remover_alunos(aluno *lista_alunos, int id, int tam){
    int i = buscaBin_alunos(lista_alunos, id, tam);
    if (i >= 0){
        if(lista_alunos[i].pendencia == 0){
            puts("Deletando aluno!");
            lista_alunos[i].id = -1;
        } else {
            puts("Não foi possível deletar o aluno!\nMotivo: Pendência");
        }
    } else {
        puts("Id não cadastrado!");
    }
}
 