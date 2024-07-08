#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<int> row_indices;
    std::vector<int> col_indices;
    std::vector<int> values;
    int rows, cols;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void insert(int r, int c, int value) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Invalid indices!" << std::endl;
            return;
        }

        if (value != 0) {
            row_indices.push_back(r);
            col_indices.push_back(c);
            values.push_back(value);
        }
    }

    int get(int r, int c) const {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Invalid indices!" << std::endl;
            return 0;
        }

        for (size_t i = 0; i < values.size(); ++i) {
            if (row_indices[i] == r && col_indices[i] == c) {
                return values[i];
            }
        }
        return 0;
    }

    void print() const {
        std::cout << "Sparse Matrix Representation:" << std::endl;
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << "Row: " << row_indices[i] << ", Col: " << col_indices[i] << ", Value: " << values[i] << std::endl;
        }
    }

    void printDense() const {
        std::cout << "Dense Matrix Representation:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);

    sm.insert(0, 2, 3);
    sm.insert(0, 4, 4);
    sm.insert(1, 2, 5);
    sm.insert(1, 3, 7);
    sm.insert(3, 1, 2);
    sm.insert(3, 2, 6);

    std::cout << "Value at (0, 2): " << sm.get(0, 2) << std::endl;
    std::cout << "Value at (0, 4): " << sm.get(0, 4) << std::endl;
    std::cout << "Value at (1, 2): " << sm.get(1, 2) << std::endl;
    std::cout << "Value at (1, 3): " << sm.get(1, 3) << std::endl;
    std::cout << "Value at (3, 1): " << sm.get(3, 1) << std::endl;
    std::cout << "Value at (3, 2): " << sm.get(3, 2) << std::endl;

    sm.print();
    sm.printDense();

    return 0;
}
