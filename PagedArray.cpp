//
// Created by eduardo on 14/8/21.
//

#include "PagedArray.h"
#include "iostream"
#include "fstream"

using namespace std;
using namespace PagedArray;

/**
 * Main function executes the program and loads .CSV file
 * It is executed from command line
 *
 * @param argc is number of parameters given from command line.
 * @param argv is array of parameters given from command line.
 * @return 0
 */
int PagedArray::main(int argc, char **argv) {
    int pageCounter = 0, numberCounter, number = 0;
    fstream file;
    file.open(argv[0]);
    while (pageCounter < 6) {
        numberCounter = 0;
        while (numberCounter < 256) {
            file >> number;
            PagedArray::*ptr = number;
            numberCounter++;
        }
        pageCounter++;
    }
    file.close();
    return 0;
}

/**
 * Metodo file_loader para cargar el archivo .CSV
 * @param directory es la ruta del archivo
 * @return el array que contiene las primeras seis paginas del archivo.
 */
void PagedArray::file_writer(std::string filename, int fixedArray[]) {
    fstream file;
    file.open(filename);
    for (int i = 0; i < 256; i++) {
        file << fixedArray[i];
    }
    file.close();
}
/**
 * Operator [] overload.
 * It is modified to load a specific page given by index
 * @param index is the number of page to load.
 */
void PagedArray::operator[](int index) {
    for (int t = 0; t < pages; t++) {
        for (int f = 0; f < 6; f++) {
            if (referenceString[i] == frames[f]) {
                cout << "Page is already in memory."
            }
            else if (referenceString[t] == index) {
                fifo_replacement(index);
                break;
            }
        }
    }
}
/**
 * Metodo replacement.
 * Aplica el algoritmo FIFO para reemplazar una pagina, ya cargada en memoria, por la nueva pagina especificada.
 *
 * Investigado de https://prepinsta.com/operating-systems/page-replacement-algorithms/fifo/fifo-in-c/
 */
void PagedArray::fifo_replacement(int index) {
    int pageFaults = 0, m, n, s, frames = 6;
    int temp[frames];
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++) {
        s = 0;
        for (n = 0; n < frames; n++) {
            if (referenceString[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if (pageFaults <= frames && s == 0) {
            temp[m] = referenceString[m];
        }
        else if (s == 0) {
            temp[(pageFaults - 1) % frames] = referenceString[m];
        }
    }
    printf("Total number of page faults: %d\t", pageFaults);
}

/**
 *
 * @param array
 */
void PagedArray::insertion_sort(int array[]) {
    int

        }
    }
}