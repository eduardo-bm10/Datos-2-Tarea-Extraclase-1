//
// Created by eduardo on 14/8/21.
//

#include "PagedArray.h"
#include "iostream"
#include "fstream"

using namespace std;
using namespace PagedArray;

/**
 * Metodo file_loader para cargar el archivo .CSV
 * @param directory es la ruta del archivo
 * @return el array que contiene las primeras seis paginas del archivo.
 */
int PagedArray::file_loader(std::string filename) {
    fstream file;
    file.open(filename);
    int counter = 0;
    int number = 0;
    while (pages > counter && counter < 6) {
        file >> number;
        PagedArray::ptr + counter = number;
        counter++;
    }
    file.close();
    return *ptr;
}

/**
 * Sobrecarga del operador [].
 * Recibe el indice de la pagina que se desea cargar a memoria.
 * @param index
 */
void PagedArray::operator[](int index) {
    for (int i = 0; i < pages; i++) {
        for (int k = 0; k < 6; k++) {
            if (array[index] == ptr+k) {
                cout << "The page is already in memory.";
            }
            else {
                replacement(index);
                break;
            }
        }
    }
}
/**
 * Metodo replacement.
 * Aplica el algoritmo FIFO para reemplazar una pagina, ya cargada en memoria, por la nueva pagina especificada.
 *
 * Investigado de https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/#:~:text=First%20In%20First%20Out%20(FIFO,queue%20is%20selected%20for%20removal.
 */
void PagedArray::replacement(int index) {
    int referenceString[10];
    int frames = 6;
    int pageFaults = 0;
    for (int i = 0; i < pages; i++) {
        for (int j = 0; j < frames; j++) {
            if (referenceString[i] == array[j] && index == i) {
                cout << "HIT";
            }
            else {
                cout << "MISS";
                array[j] = referenceString[index];
                pageFaults++;
            }
        }
    }
}

/**
 *
 * @param array
 */
void PagedArray::insertion_sort(int array[]) {
    for (int i = 1; i < PAGE_SIZE*6; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp <= array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}