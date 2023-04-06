#define KORMEN_H
#ifdef KORMEN_H

#include <vector>

/****** [ Chater 1 ] Sort algorithm        ******/

// ! 1 Insertion sorting algorithm            ! //

std::vector<int> insertionSort(std::vector<int> arrayin) {

    for (int i = 1; i < arrayin.size(); i++) {
        int key = arrayin[i];
        int bnum = i - 1;
        while (bnum >= 0 && key < arrayin[bnum]) {
            arrayin[bnum + 1] = arrayin[bnum];
            bnum -= 1;
        }
        arrayin[bnum + 1] = key;
    }

    return arrayin;

}

// ! 2 Merge sorting algorithm                ! //

std::vector<int> mergerSort(std::vector<int> arrayin) {

    std::vector<int> result;

    std::vector<int> arrayinone;
    std::vector<int> arrayintwo;

    if (arrayin.size() % 2 == 0) {

        for (int i = 0; i < arrayin.size() / 2; i++) arrayinone.push_back(arrayin[i]);
        if (arrayinone.size() > 1) arrayinone = mergerSort(arrayinone);

        for (int i = arrayin.size() / 2; i < arrayin.size(); i++) arrayintwo.push_back(arrayin[i]);
        if (arrayintwo.size() > 1) arrayintwo = mergerSort(arrayintwo);

    }
    else {

        for (int i = 0; i < arrayin.size() - 1; i++) arrayinone.push_back(arrayin[i]);
        if (arrayinone.size() > 1) arrayinone = mergerSort(arrayinone);

        arrayintwo.push_back(arrayin[arrayin.size() - 1]);

    }

    int i = 0, y = 0;

    for (; i < arrayinone.size() && y < arrayintwo.size(); ) {

        if (arrayinone[i] <= arrayintwo[y]) {
            result.push_back(arrayinone[i]);
            i++;
        }
        else {
            result.push_back(arrayintwo[y]);
            y++;
        }

    }

    return result;

}

/****** [ Chater 2 ] Recursive algorithms  ******/

// ! 1 Finding the maximum subarray           ! //

std::vector<int> findMaximumSubarray(std::vector<int> arrayin) {

    int leftside, rightside;
    if (arrayin.size() == 1) return arrayin;
    else leftside = 0, rightside = arrayin.size() - 1;

    std::vector<int> result;



    return result;

}

std::vector<int> findMaximumSubarray(std::vector<int> arrayin) {

}

#endif