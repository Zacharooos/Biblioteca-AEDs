#ifndef STRUCT_H

#define STRUCT_H

#endif

//Biblioteca para declaração de Structs

// Pading afetas Load/Save dos dados !

// Sem padding
typedef struct aluno{
    const char nome[52];
    const char matricula[12];
    int id;
    int pendencia;

} aluno;

// Sem padding
typedef struct livro{
    char nome[101];
    char categoria[51];
    int ano;
    int id;
    bool pendencia;

    int aluno_id;
    
} livro;

// Com padding
typedef struct recursos{
    int id;
    int aluno_id;
    
    char tipo;
    bool estado;

} recursos;