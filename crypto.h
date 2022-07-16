#ifndef CRYPTO_H

#define CRYPTO_H

#endif

// Encriptação Bicifrada-de-Vignére
/* Funciona de forma semelhante a cifra de César, mas com uma lista de chaves que varia dentro de um intervalo circular
 diferente da original, nesta a cifra tem seu sentido invertido sempre que a posição do caracter for ímpar. */

// Utilize chaves entre os valores -20 e 20

void encriptar (char *cadeia, int* chaveiro, int tam){
    for (int i = 0, j = 0; cadeia[i] != '\0'; ++i, ++j){
        // Variável j serve para resetar a lista de chaves
        if (j == tam){
            j = 0;
        }
        
        if (i % 2 == 0){
            cadeia[i] = cadeia[i] + chaveiro[j];
        
        } else {
            cadeia[i] = cadeia[i] - chaveiro[j];

        }
    }
}

void desencriptar (char *cadeia, int* chaveiro, int tam){
    // Variável j serve para resetar a lista de chaves
    for (int i = 0, j = 0; cadeia[i] != '\0'; ++i, ++j){
        if (j == tam){
            j = 0;
        }

        if (i % 2 == 0){
            cadeia[i] = cadeia[i] - chaveiro[j];

        } else {
            cadeia[i] = cadeia[i] + chaveiro[j];

        }
    }
}