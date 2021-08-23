//
// Created by eduardo on 14/8/21.
//

#ifndef DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
#define DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H


class PagedArray {
public:
    int numberOfPages;
    const int PAGE_SIZE = 256;
    int page_array[PAGE_SIZE];

    int insertion_sort();
    void operator[](int getPage);
};


#endif //DATOS_2_TAREA_EXTRACLASE_1_PAGEDARRAY_H
