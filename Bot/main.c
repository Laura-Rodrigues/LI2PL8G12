//
// Created by laura on 23/04/20.
//

#include "funcoes_aux.h"
#include "Bot.h"

int main (int argc, char *argv[]){
    ESTADO *e = inicializar_estado();
    ler(argc, e);
    bot(e);
    gr(argv, e);
    return 0;
}