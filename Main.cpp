//
// Created by eduardo on 27/8/21.
//

#include "PagedArray.h"

int main(int argc, char **argv) {
    PagedArray* function = new PagedArray();
    function->start(argv);
    delete function;
    return 0;
}
