#include "Camada_dados.h"
#include "Camada_Interface.h"
#include "Funcoes_Ficheiro.h"
#include <stdlib.h>

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
//    ler("Projeto_Rastros");
//    gr("Projeto_Rastros",e);
    free(e);
    return 0;
}

