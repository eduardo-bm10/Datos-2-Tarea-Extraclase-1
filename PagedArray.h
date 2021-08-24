//
// Created by eduardo on 14/8/21.
//

#ifndef DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#define DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#include "string"


class PagedArray {
public:
    int pages = 10;
    const int PAGE_SIZE = 256;
    int array[6];
    int* ptr = &array[6];
    int file_loader(std::string filename);
    void file_writer(std::string filename);
    void insertion_sort(int array[]);
    void operator[](int index);
    void replacement(int index);
};


#endif //DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
