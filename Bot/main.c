//
// Created by laura on 23/04/20.
//

#include "funcoes_aux.h"
#include "Bot.h"

int main (int argc, char *argv[]) {
    if (argc == 3) {
        char* tabi = argv[1];
        char* tabf = argv[2];
        ESTADO *e = inicializar_estado();
        e = ler(tabi, e);
        mostrar_tabuleiro(e);
        movs(e);
        bot(e);
        gr(tabf, e);
        return 0;
    }
}