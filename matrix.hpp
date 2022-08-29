class Matrix {
    public:
        int ItemAt(int col, int row);
        Matrix Transpose() const;
        Matrix();
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, int* arr);
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix&);
        Matrix operator*(const Matrix&);
        ~Matrix();

    private:
        int *data;
        int rows;
        int cols;
        void _build(int* arr);
};
