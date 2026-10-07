#include <iostream>
#include <new>

bool InputError() {
    if (std::cin.fail()) {
        std::cerr << "Еrror" << std::endl;
        return false;
    }
    return true;
}

void clean_matrix(int** matrix, size_t allocated_rows) {
    if (matrix == nullptr) return;
    for (size_t i = 0; i < allocated_rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    size_t rows = 0, columns = 0;
    std::cin >> rows >> columns;
    
    if (!InputError() or rows == 0 or columns == 0) {
        return 1;
    }
    
    int** matrix = nullptr;
    try {
        matrix = new int*[rows];
    }
    catch (std::bad_alloc&) {
        std::cerr << "bad_alloc" << std::endl;
        return 2;
    }
    
    for (size_t i = 0; i < rows; i++) {
        try {
            matrix[i] = new int[columns];
        }
        catch (std::bad_alloc&) {
            clean_matrix(matrix, i);
            return 2;
        }
    }
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            int c = 0;
            std::cin >> c;
            if (!InputError()) {
                clean_matrix(matrix, rows);
                return 1;
            }
            matrix[i][j] = c;
        }
    }
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Т матрица:" << std::endl;
    for (size_t j = 0; j < columns; j++) {
        for (size_t i = 0; i < rows; i++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    clean_matrix(matrix, rows);
    return 0;
}


