#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"


struct Pessoa{
    func_ptr_imprime imprime;
    func_ptr_desaloca_pessoa desaloca;
    func_ptr_tipo_pessoa tipo;
    void* dado;
};

