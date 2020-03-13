#include <stdio.h>
#include "Mapa.h"
#include "Camada_dados.h"
#include "Camada_Interface.h"

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}

