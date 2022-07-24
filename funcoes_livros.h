#ifndef FUNLI_H

#define FUNLI_H

#endif

// Seção de Funções implícitas de _livros

void pendencia_livros(int pendencia){
    if(pendencia == 0){
        puts("Livro disponível pra empréstimo!");
    } else {
        puts("Livro atualmente emprestado!");
    }    
}

//! Função buscaBinária modificada, procura livros por id
int buscaBin_livros(livro *v, int id, int tam){
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

// Seção de funções explícitas de _livros

//! Função para realizar a busca de um determinado livro através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_livros(livro *lista_livros, aluno * lista_alunos, int id, int tam_livros, int tam_alunos){
    int i = buscaBin_livros(lista_livros, id, tam_livros);
    if (i >= 0){
        printf("Livro id [%d] encontrado!\n", lista_livros[i].id);
        printf("Nome: %s\n", lista_livros[i].nome);
        printf("Categoria: %s\n", lista_livros[i].categoria);
		printf("Publicação: %d\n", lista_livros[i].ano);
		pendencia_livros(lista_livros[i].pendencia);

        if(lista_livros[i].pendencia == true){
            int i_aluno = buscaBin_alunos(lista_alunos, lista_livros[i].aluno_id, tam_alunos);
            printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
        }
        

    } else {
        printf("Erro: Id não cadastrado!\n");
    }
}

//! Função para mostrar todos os livros
void mostrar_livros(livro * lista_livros, aluno * lista_alunos, int tam_livros, int tam_alunos){
    int contador = 0;
    int i = 0;
    while(contador < tam_livros){
        if(lista_livros[i].id < 0){
            i++;
        } else {
            printf("Livro id [%d] encontrado!\n", lista_livros[i].id);
            printf("Nome: %s\n", lista_livros[i].nome);
            printf("Categoria: %s\n", lista_livros[i].categoria);
            printf("Publicação: %d\n", lista_livros[i].ano);
            pendencia_livros(lista_livros[i].pendencia);

            if(lista_livros[i].pendencia == true){
                int i_aluno = buscaBin_alunos(lista_alunos, lista_livros[i].aluno_id, tam_alunos);
                printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
            }
            puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            i++;
            contador++;
        }
    }
}

//! Função utilizada para criação de livros
int criar_livros(livro **lista_livros, int tam, int *id_data){
    *lista_livros = realloc(*lista_livros, (tam + 1) * sizeof(livro));
    id_data[1]++;
    (*lista_livros)[tam].id = id_data[1];
    printf("Iniciado registro ID: %d\n", (*lista_livros)[tam].id);
    
    printf("Inserir nome do livro: ");
    scanf("%[^\n]s", (*lista_livros)[tam].nome);

    printf("Inserir categoria do livro: ");
    scanf("%s", (*lista_livros)[tam].categoria);

    printf("Inserir ano de publicação do livro: ");
    scanf("%d", &(*lista_livros)[tam].ano);

    fflush(stdin);

    (*lista_livros)[tam].pendencia = 0;

    (*lista_livros)[tam].aluno_id = -2;

    puts("O cadastro foi um sucesso!");

    return tam+1;
}

//! Função para remover livros, define id do aluno como -1;
int remover_livros(livro *lista_livros, int id, int tam){
    int i = buscaBin_livros(lista_livros, id, tam);
    if (i > -1){
        if(lista_livros[i].pendencia == 0){
            puts("Deletando livro");
            lista_livros[i].id = -1;
            return tam-1;
        } else {
            puts("Erro: Não foi possível deletar o livro!\nMotivo: Pendência");
        }
    } else {
        puts("Erro: Id não cadastrado!");
    }
    return tam;
}

//! Função para cadastrar livro no alunos
void registro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos){
    int i_livro = buscaBin_livros(lista_livros, id, tam_livros);
    int i_aluno = buscaBin_alunos(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o livro existe
    if (i_livro < 0){
        puts("Erro: Livro não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o livro está emprestado
    if (lista_livros[i_livro].pendencia == 0){
        lista_livros[i_livro].pendencia = 1;
        lista_livros[i_livro].aluno_id = lista_alunos[i_aluno].id;
        lista_alunos[i_aluno].pendencia++;
        puts("Cadastro realizado com sucesso!");

    } else {
        puts("Erro: Impossível emprestar, livro não disponível!");
    }
}

//! Função para devolução do livro
void deregistro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos){
    int i_livro = buscaBin_livros(lista_livros, id, tam_livros);
    int i_aluno = buscaBin_alunos(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o livro existe
    if (i_livro < 0){
        puts("Erro: Livro não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o livro está emprestado
    if (lista_livros[i_livro].pendencia == 1){
        if (lista_livros[i_livro].aluno_id == lista_alunos[i_aluno].id){
            lista_livros[i_livro].pendencia = 0;
            lista_livros[i_livro].aluno_id = -2;
            lista_alunos[i_aluno].pendencia--;
            puts("Devolução realizada com sucesso!");
        } else {
            puts("Livro não vinculado a este aluno, falha no processo!");
        }
    } else {
        puts("Erro: Impossível devolver, livro está no estoque!");
    }
}