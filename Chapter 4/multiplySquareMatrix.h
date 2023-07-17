Matrix multiplySquareMatrix(Matrix A, Matrix B) {
    
    Matrix result(B.collums(), A.rows());
    
    for (int i = 0; i < B.collums(); ++i) {
        for (int j = 0; j < A.rows(); ++j) {
            for (int k = 0; k < A.collums(); ++k) {
                result.get(i, j) += A.get(k, j) * B.get(i, k);
            }
        }
    }

    return result;

}

class Matrix {
public:

    Matrix(int collums, int rows) {
        for (int i = 0; i < rows; ++i) {
            body.push_back({});
            for (int j = 0; j < collums; ++j) {
                body[i].push_back(0);
            }
        }
    }

    int& get(int collum, int row) {
        return body[row][collum];
    }

    int collums() {
        return body[0].size();
    }

    int rows() {
        return body.size();
    }

    void init(std::vector<std::vector<int>> init) {
        body = init;
    }

    friend std::ostream& operator << (std::ostream& ostream, const Matrix& matrix) {
        for (int i = 0; i < matrix.body.size(); ++i) {
            for (int j = 0; j < matrix.body[0].size(); ++j) {
                ostream << "[" << matrix.body[i][j] << "] ";
            }
            ostream << "\n";
        }
        return ostream;
    }

private:

    std::vector<std::vector<int>> body;

};
