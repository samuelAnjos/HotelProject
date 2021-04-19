#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

struct funcionario
{
    int codigo;
    char nome[30];
    char cpf[15];
    char cargo[30];
};
    #endif
