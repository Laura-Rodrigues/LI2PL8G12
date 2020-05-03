//
// Created by laura on 23/04/20.
//

#include "Bot.h"
#include "Camada_dados.h"
#include "Camada_Interface.h"

int main (int argc, char *argv[]) {
    if (argc == 3) {
        char* tabi = argv[1];
        char* tabf = argv[2];
        ESTADO *e = inicializar_estado();
        e = ler(tabi, e);
        bot(e);
        gr(tabf, e);
        return 0;
    }
}
