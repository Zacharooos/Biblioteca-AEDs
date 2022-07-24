#ifndef FUNRE_H

#define FUNRE_H

#endif

// Seção de Funções implícitas de _recursos

//! Função para checar pendência.
void pendencia_recursos(int pendencia){
    if(pendencia == 0){
        puts("Recurso disponível pra empréstimo!");
    } else {
        puts("Recurso atualmente emprestado!");
    }    
}

//! Função buscaBinária modificada, procura recursos por id
int buscaBin_recursos(recursos *v, int id, int tam){
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

// Seção de Funções explícitas de _recursos

//! Função para realizar a busca de um determinado recurso através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_recursos(recursos *lista_recursos, aluno * lista_alunos, int id, int tam_recursos, int tam_alunos){
    int i = buscaBin_recursos(lista_recursos, id, tam_recursos);
    if (i >= 0){
        printf("Recurso id [%d] encontrado!\n", lista_recursos[i].id);
        printf("Tipo: %c\n", lista_recursos[i].tipo);

		pendencia_recursos(lista_recursos[i].estado);
        if(lista_recursos[i].estado == true){
            int i_aluno = buscaBin_alunos(lista_alunos, lista_recursos[i].aluno_id, tam_alunos);
            printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
        }
        puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    } else {
        printf("Erro: Id não cadastrado!\n");
    }
}

//! Função para mostrar todos os recursos
void mostrar_recursos(recursos * lista_recursos, aluno * lista_alunos, int tam_recursos, int tam_alunos){
    int contador = 0;
    int i = 0;
    while (contador < tam_recursos){
        if(lista_recursos[i].id < 0){
            i++;
        } else {
            printf("Recurso id [%d] encontrado!\n", lista_recursos[i].id);
            printf("Tipo: %c\n", lista_recursos[i].tipo);

            pendencia_recursos(lista_recursos[i].estado);
            if(lista_recursos[i].estado == true){
                int i_aluno = buscaBin_alunos(lista_alunos, lista_recursos[i].aluno_id, tam_alunos);
                printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
            }

            puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            i++;
            contador++;
            }
        }
    }


//! Função para a criação de recursos
int criar_recursos(recursos **lista_recursos, int tam){
    *lista_recursos = realloc(*lista_recursos, (tam + 1) * sizeof(recursos));
    int id_data;
    puts("Inserir id para cadastro: ");
    scanf("%d", &id_data);
    while(buscaBin_recursos((*lista_recursos), id_data, tam) > -1){
        puts("Erro! Id inválido! (em uso), tente outro a seguir: ");
        scanf("%d", &id_data);
    }
    puts("foi!");

    (*lista_recursos)[tam].id = id_data;
    printf("Iniciado registro ID: %d\n", (*lista_recursos)[tam].id);

    fflush(stdin);
    
    printf("Inserir categoria do recurso: ");
    scanf("%c", &(*lista_recursos)[tam].tipo);

    fflush(stdin);

    (*lista_recursos)[tam].aluno_id = -2; 

    (*lista_recursos)[tam].estado = 0;

    puts("O cadastro foi um sucesso!");

    return tam+1;
}

//! Função para remover recursos, define id do aluno como -1;
int remover_recursos(recursos *lista_recursos, int id, int tam){
    int i = buscaBin_recursos(lista_recursos, id, tam);
    if (i > -1){
        if(lista_recursos[i].estado == 0){
            puts("Deletando recurso!");
            lista_recursos[i].id = -1;
            return tam-1;
        } else {
            puts("Erro: Não foi possível deletar o recurso!\nMotivo: Pendência");
        }
    } else {
        puts("Erro: Id não cadastrado!");
    }
    return tam;
}

//! Função para cadastrar recurso no alunos
void registro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos){
    int i_recurso = buscaBin_recursos(lista_recursos, id, tam_recursos);
    int i_aluno = buscaBin_alunos(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o recurso existe
    if (i_recurso < 0){
        puts("Erro: recurso não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o recurso está emprestado
    if (lista_recursos[i_recurso].estado == 0){
        lista_recursos[i_recurso].estado = 1;
        lista_recursos[i_recurso].aluno_id = lista_alunos[i_aluno].id;
        lista_alunos[i_aluno].pendencia++;
        puts("Cadastro realizado com sucesso!");

    } else {
        puts("Erro: Impossível emprestar, recurso não disponível!");
    }
}

//! Função para devolução do recurso
void deregistro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos){
    int i_recurso = buscaBin_recursos(lista_recursos, id, tam_recursos);
    int i_aluno = buscaBin_alunos(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o recurso existe
    if (i_recurso < 0){
        puts("Erro: recurso não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o recurso está emprestado
    if (lista_recursos[i_recurso].estado == 1){
        if (lista_recursos[i_recurso].aluno_id == lista_alunos[i_aluno].id){
            lista_recursos[i_recurso].estado = 0;
            lista_recursos[i_recurso].aluno_id = -2;
            lista_alunos[i_aluno].pendencia--;
            puts("Devolução realizada com sucesso!");
        } else {
            puts("recurso não vinculado a este aluno, falha no processo!");
        }
    } else {
        puts("Erro: Impossível devolver, recurso está no estoque!");
    }
}