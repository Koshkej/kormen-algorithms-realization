#include <vector>

std::vector<int> insertionSort(std::vector<int>& arrayin) {
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
