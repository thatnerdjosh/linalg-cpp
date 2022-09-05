class Matrix {
    public:
        int ItemAt(int row, int col) const;
        Matrix Transpose() const;
        Matrix();
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, int* arr);
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix&) {};
        Matrix operator*(const Matrix&);
        ~Matrix();
        friend std::ostream& operator<<(std::ostream& os, const Matrix&);

    private:
        int *data;
        int rows;
        int cols;
        void _build(int* arr);
};
