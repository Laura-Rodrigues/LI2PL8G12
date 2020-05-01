cmake_minimum_required(VERSION 3.15)
project(ProjetoRastros C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoRastros main.c Logica_Programa.c Logica_Programa.h Camada_Interface.c Camada_Interface.h Camada_dados.c Camada_dados.h Funcoes_Ficheiro.c Funcoes_Ficheiro.h Listas/listas.c Listas/listas.h Bot/Camada_dados.c Bot/Camada_dados.h Bot/Camada_Interface.c Bot/Camada_Interface.h Bot/Funcoes_Ficheiro.c Bot/Funcoes_Ficheiro.h Bot/listas.c Bot/listas.h Bot/Logica_Programa.c Bot/Logica_Programa.h)
