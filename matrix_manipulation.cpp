#include <iostream>
#include <fstream>
#include <iomanip> // for std::setw function to align matrix columns for formatted output

// Define the maximum size for the matrix as a static constant
const static int MAX_SIZE = 100;

// Function prototypes
// Function to read matrix data from a file into a 2D array
void readMatrixFromFile(std::ifstream &inFile, int matrix[MAX_SIZE][MAX_SIZE], const int size);

// Function to display the matrix in a user-friendly format
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], const int size);

// Function to add two matrices
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size);

// Function to multiply two matrices
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size);

// Function to subtract one matrix from another
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size);

int main() {
    // Define 2D arrays to store two input matrices and one result matrix
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Variable to store the size of the matrices
    int size;

    // Print header information
    std::cout << "Joshua Lee\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";

    // Open the input file for reading
    std::ifstream inFile("matrix_input.txt"); // Open the matrix_input.txt file for reading
    if (!inFile) { // Check if the file was opened successfully or not
        std::cerr << "Error opening file.\n"; // Print error message to standard error stream
        exit(1); // Exit the program
    }

    // Read the size of the matrices from the file
    inFile >> size;

    // Read matrixA and matrixB from the file
    readMatrixFromFile(inFile, matrixA, size);
    readMatrixFromFile(inFile, matrixB, size);
    inFile.close(); // Close the input file

    // Display matrixA
    std::cout << "Matrix A:\n";
    printMatrix(matrixA, size);

    // Display matrixB
    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, size);

    // Add matrixA and matrixB, then display the result
    addMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Sum (A + B):\n";
    printMatrix(result, size);

    // Multiply matrixA and matrixB, then display the result
    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Product (A * B):\n";
    printMatrix(result, size);

    // Subtract matrixB from matrixA, then display the result
    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Difference (A - B):\n";
    printMatrix(result, size);

    return 0; // End the program
}

// Function to read a matrix of given size from a file
void readMatrixFromFile(std::ifstream &inFile, int matrix[MAX_SIZE][MAX_SIZE], const int size) {
    for (int i = 0; i < size; ++i) { // Iterate over rows of the matrix
        for (int j = 0; j < size; ++j) { // Iterate over columns of the matrix
            inFile >> matrix[i][j]; // Read each element of the matrix from the file into the array at the current position
        }
    }
}

// Function to display the matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], const int size) {
    for (int i = 0; i < size; ++i) { // Iterate over rows of the matrix
        for (int j = 0; j < size; ++j) { // Iterate over columns of the matrix
            std::cout << std::setw(4) << matrix[i][j] << " "; // Print each element in a column-aligned manner
        }
        std::cout << "\n"; // Newline after each row
    }
}

// Function to add two matrices
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size) {
    for (int i = 0; i < size; ++i) { // Iterate over rows of the result matrix
        for (int j = 0; j < size; ++j) { // Iterate over columns of the result matrix
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // Sum corresponding elements of matrixA and matrixB and store the result in the result matrix at the same position
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size) {
    for (int i = 0; i < size; ++i) { // Iterate over rows of the result matrix
        for (int j = 0; j < size; ++j) { // Iterate over columns of the result matrix
            result[i][j] = 0; // Initialize the current result element to 0 before performing the multiplication
            // Perform matrix multiplication using the third loop to iterate over the columns of one row in matrixA, and over the rows of one column in matrixB, 
            // and add the products of those corresponding elements to the result element at the current position in the result matrix. Repeat for all elements in the result matrix.
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], const int size) {
    for (int i = 0; i < size; ++i) { // Iterate over rows of the result matrix
        for (int j = 0; j < size; ++j) { // Iterate over columns of the result matrix
            result[i][j] = matrixA[i][j] - matrixB[i][j]; // Subtract corresponding elements of matrixB from matrixA and store the result in the result matrix at the same position
        }
    }
}
