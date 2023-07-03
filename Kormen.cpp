#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> arrayin);
std::vector<int> mergerSort(std::vector<int> arrayin);

int main() {
        
    return 0;

}

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

std::vector<int> mergerSort(std::vector<int> arrayin) {

    std::vector<int> result;

    std::vector<int> arrayinone;
    std::vector<int> arrayintwo;

    if (arrayin.size() % 2 == 0) {

        for (int i = 0; i < arrayin.size() / 2; i++) arrayinone.push_back(arrayin[i]);
        if (arrayinone.size() > 1) arrayinone = mergerSort(arrayinone);

        for (int i = arrayin.size() / 2; i < (arrayin.size() / 2) * 2; i++) arrayintwo.push_back(arrayin[i]);
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

    if (i == arrayinone.size()) for (; y < arrayintwo.size(); y++) result.push_back(arrayintwo[y]);

    if (y == arrayintwo.size()) for (; i < arrayinone.size(); i++) result.push_back(arrayinone[i]);

    return result;
    
}