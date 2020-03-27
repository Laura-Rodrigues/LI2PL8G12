//
// Created by laura on 26/03/20.
//

#ifndef PROJETORASTROS_FUNCOES_FICHEIRO_H
#define PROJETORASTROS_FUNCOES_FICHEIRO_H

#include <bits/types/FILE.h>
#include "Camada_dados.h"

void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e);
int gr(FILE *Projeto_Rastros, ESTADO *e);
int ler(FILE *Projeto_Rastros);
int movs ( ESTADO *e);


#endif //PROJETORASTROS_FUNCOES_FICHEIRO_H
