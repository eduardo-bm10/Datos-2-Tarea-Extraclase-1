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
    int pageFrames[6];
    int referenceString[10] = {1,2,3,4,5,6,7,8,9,10};

    void start(char** argv);
    void insertion_sort(int* arrayPointer);
    void operator[](int page);
    void fifo_replacement(int index);
};

#endif //DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
