//
// Created by eduardo on 14/8/21.
//

#ifndef DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#define DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#include "string"


class PagedArray {
public:
    int pages = 10;
    int referenceString[10] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr = malloc(1024);

    int main(int argc, char** argv);
    int file_loader(std::string filename);
    void file_writer(std::string filename);
    void insertion_sort(int array[]);
    void operator[](int index);
    void fifo_replacement(int index);
};


#endif //DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
