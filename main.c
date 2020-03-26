#include "Camada_dados.h"
#include "Camada_Interface.h"
#include "Funcoes_Ficheiro.h"
#include <stdlib.h>

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
//    ler("Projeto_Rastos");
//    gr("Projeto_Rastos",e);
    free(e);
    return 0;
}

