#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    Node* head;
    int rows, cols;

public:
    SparseMatrix(int r, int c) : head(nullptr), rows(r), cols(c) {}

    SparseMatrix() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int r, int c, int value) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Invalid indices!" << std::endl;
            return;
        }

        if (value != 0) {
            Node* newNode = new Node(r, c, value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    int get(int r, int c) const {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Invalid indices!" << std::endl;
            return 0;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->row == r && current->col == c) {
                return current->value;
            }
            current = current->next;
        }
        return 0;
    }

    void print() const {
        Node* current = head;
        std::cout << "Sparse Matrix Representation:" << std::endl;
        while (current != nullptr) {
            std::cout << "Row: " << current->row << ", Col: " << current->col << ", Value: " << current->value << std::endl;
            current = current->next;
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
