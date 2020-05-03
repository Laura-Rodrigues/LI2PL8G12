#include "Camada_dados.h"
#include "Camada_Interface.h"
#include <stdlib.h>

/**
\brief main do projeto
@return 0
*/
int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    free(e);
    return 0;
}

