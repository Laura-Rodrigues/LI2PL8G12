//
// Created by laura on 26/03/20.
//

#ifndef PROJETORASTROS_FUNCOES_FICHEIRO_H
#define PROJETORASTROS_FUNCOES_FICHEIRO_H

#include <bits/types/FILE.h>
#include "Camada_dados.h"

void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e);

int movsficheiro (ESTADO *e, FILE *nome);

int gr(char nomeficheiro[], ESTADO *e);

int ler(char nomeficheiro[], ESTADO *e);

int movs ( ESTADO *e);


#endif //PROJETORASTROS_FUNCOES_FICHEIRO_H
