//
// Created by eduardo on 22/8/21.
//

#include "Main.h"
#include "PagedArray.h"

/**
 * Funcion principal que desencadena el algoritmo.
 * @return
 */
int Main::main() {
    int arrayPrueba[10];
    PagedArray pagedArray = new PagedArray();
    arrayPrueba = pagedArray.file_loader("lista.csv");
    return 0;
}