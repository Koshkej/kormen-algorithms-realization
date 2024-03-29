#include <vector>
#include <map>

std::map<std::string, int> findMaximumCrossingSubarray(const std::vector<int>& arrayin, int indexBegin, int indexMiddle, int indexEnd) {

    std::map<std::string, int> result = { {"begin", 0},{"end", 0},{"sum", 0} };

    int leftSum = INT_MIN;
    for (int i = indexMiddle, incrementedSum = 0; i >= indexBegin; --i) {
        incrementedSum += arrayin[i];
        bool isArrayIncrementBigger = leftSum < incrementedSum;
        if (isArrayIncrementBigger) {
            leftSum = incrementedSum;
            result["begin"] = i;
        }
    }

    int rightSum = INT_MIN;
    for (int j = indexMiddle + 1, incrementedSum = 0; j <= indexEnd; ++j) {
        incrementedSum += arrayin[j];
        bool isArrayIncrementBigger = rightSum < incrementedSum;
        if (isArrayIncrementBigger) {
            rightSum = incrementedSum;
            result["end"] = j;
        }
    }

    result["sum"] = leftSum + rightSum;

    return result;

}

std::map<std::string, int> findMaximumSubarray(const std::vector<int>& arrayin, int indexBegin, int indexEnd) {

    bool isRecursionBottomReached = indexBegin == indexEnd;
    if (isRecursionBottomReached) {
        return { {"begin", indexBegin},{"end", indexEnd},{"sum", arrayin[indexBegin]} };
    }

    const int indexMiddle = (indexBegin + indexEnd) / 2;

    std::map<std::string, int> leftSubarray   = findMaximumSubarray(arrayin, indexBegin, indexMiddle);
    std::map<std::string, int> rightSubarray  = findMaximumSubarray(arrayin, indexMiddle + 1, indexEnd);
    std::map<std::string, int> middleSubarray = findMaximumCrossingSubarray(arrayin, indexBegin, indexMiddle, indexEnd);

    bool isLeftSubarrayMax = leftSubarray["sum"] >= rightSubarray["sum"] && leftSubarray["sum"] >= middleSubarray["sum"];
    if (isLeftSubarrayMax) {
        return leftSubarray;
    } 
    else {
        bool isRightSubarrayMax = rightSubarray["sum"] >= leftSubarray["sum"] && rightSubarray["sum"] >= middleSubarray["sum"];
        if (isRightSubarrayMax) {
            return rightSubarray;
        } 
        else {
            return middleSubarray;
        }
    }

}
