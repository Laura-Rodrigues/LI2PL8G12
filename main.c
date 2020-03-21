#include "Camada_dados.h"
#include "Camada_Interface.h"

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    free(e);
    return 0;
}

