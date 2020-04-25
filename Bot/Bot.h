//
// Created by laura on 23/04/20.
//

#ifndef PROJETORASTROS_BOT_H
#define PROJETORASTROS_BOT_H

/**
\brief Grava o tabuleiro
@param e Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns 1
*/
int gr(char nomeficheiro[], ESTADO *e);

/**
\brief Lê o tabuleiro e atualiza o estado
@param e Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns o estado alterado
*/
ESTADO *ler(char nomeficheiro[], ESTADO *e);

#endif //PROJETORASTROS_BOT_H
