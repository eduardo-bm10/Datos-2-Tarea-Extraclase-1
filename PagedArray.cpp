//
// Created by eduardo on 14/8/21.
//

#include "PagedArray.h"
#include "iostream"
#include "fstream"
#include "string"

using namespace std;

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
    int temp[256];
    fstream file1, file2;
    file1.open(argv[0]);
    file2.open(argv[1]);
    while (pageCounter < 6) {
        int* ptr1 = temp;///Allocating 1 KB of memory for page
        numberCounter = 0;
        while (numberCounter < 256) {
            file1 >> number;///Read numbers from File #1.
            *(ptr1 + numberCounter) = number;///Insert number in temporal array.
            numberCounter++;
        }
        insertion_sort(ptr1);///Sort array located in memory block;
        pageCounter++;
        for (int number : temp) {
            file2 << number;///Write ordered numbers in File #2.
        }
        free(ptr1);///Freeing the memory allocated before.
    }
    file1.close();
    file2.close();
    return 0;
}

/**
 * Operator [] overload.
 * It is modified to load a specific page given by index
 * @param index is the number of page to load.
 */
void PagedArray::operator[](string filename, int page) {
    int pages = 0, n = 0, number = 0, i = 0;
    int tmp[256];
    fstream file;
    file.open(filename);
    while (!(file.eof())) {
        if (++n == 256) {
            pages++;
        }
    }
    while (i < 256) {
        file >> number;

    }
    fifo_replacement(page);

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
    for (m = 0; m < 10; m++) {
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
 * @param arrayPointer
 */
void PagedArray::insertion_sort(int* arrayPointer) {
    int temp, c;
    for (int i = 1; i < 256; i++) {
        if (arrayPointer[i-1] > arrayPointer[i]) {
            c = i - 1;
            while (arrayPointer[c] > arrayPointer[c+1] && c >= 0) {
                temp = arrayPointer[c];
                arrayPointer[c] = arrayPointer[c+1];
                arrayPointer[c+1] = temp;
                c--;
            }
        }
    }
}