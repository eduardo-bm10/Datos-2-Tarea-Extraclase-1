//
// Created by eduardo on 14/8/21.
//

#ifndef DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#define DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H

/**
 * PagedArray Class:
 *
 */
class PagedArray {
public:
    int frame[256];
    int referenceString[10] = {1,2,3,4,5,6,7,8,9,10};

    int main(int argc, char** argv);
    int insertion_sort(int array[]);
    void operator[](int index);
    void fifo_replacement(int index);
};


#endif //DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
