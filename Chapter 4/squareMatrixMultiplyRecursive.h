Matrix squareMatrixMultiplyRecursive(Matrix A, Matrix B) {

}

// below is a very simple class of matrices to demonstrate
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
