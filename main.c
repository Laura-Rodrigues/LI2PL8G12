#include "Camada_dados.h"
#include "Camada_Interface.h"
#include "Funcoes_Ficheiro.h"
#include <stdlib.h>

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
//    FILE *fp = fopen("Projeto_Rastos", "w");
//    gr(fp,e);
    free(e);
    return 0;
}

