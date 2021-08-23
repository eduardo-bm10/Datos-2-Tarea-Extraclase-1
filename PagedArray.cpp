//
// Created by eduardo on 14/8/21.
//

#include "PagedArray.h"
#include "iostream"
#include "fstream"

using namespace std;
using namespace PagedArray;

void PagedArray::operator[](int getPage) {
    fstream file;
    file.open("list.csv");

    int counter = 0;
    while (!file.eof()) {
        if (counter > getPage) {
            cout << "There's not such page";
        }
        else if (counter == getPage*256) {

        }
    }
}

int PagedArray::insertion_sort(int array[]) {
    for (int i = 1; i < PAGE_SIZE*6; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp <= array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    return array;
}