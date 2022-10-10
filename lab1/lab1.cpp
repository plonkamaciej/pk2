
#include <stdio.h>
#include <iostream>

using namespace std;

template <class T>
class MyMatrix
{
public:
    MyMatrix(int rows, int cols)
    {
        setRow(rows);
        setCol(cols);

        data = new T * [rows]; 

        for (int i = 0; i < row; i++) {
            data[i] = new T[cols];
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = (T)i * j;
            }
        }
    }

    void print();
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    T& operator()(int row, int col);
    MyMatrix<T> add(MyMatrix & b);
    MyMatrix<T> sub(MyMatrix & b);
    MyMatrix<T> mul(MyMatrix& b);
private:
    T** data;
    int row, col;
};

template <class T>
void MyMatrix<T>::print()
{
    int i, j;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++) 
        {
            cout << (T)data[i][j] << ' ';
        }
        cout << endl;
    }
}

template<class T>
MyMatrix<T> MyMatrix<T>::add(MyMatrix & b)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++) {
            b.data[i][j] = data[i][j] + b.data[i][j];
        }
    };
    return b;
}

template<class T>
MyMatrix<T> MyMatrix<T>::sub(MyMatrix & b)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++) {
            b.data[i][j] = data[i][j] - b.data[i][j];
        }
    };
    return b;
}

template<class T>
MyMatrix<T> MyMatrix<T>::mul(MyMatrix& b)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++) {
            b.data[i][j] = data[j][i] * b.data[i][j];
        }
    };
    return b;
}

template<class T> T& MyMatrix<T>::operator()(int row, int col)
{
    return data[row][col];
}

int main()
{
    
    MyMatrix <int> m(3, 3);
    MyMatrix <int> b(3, 3);
    m.add(b);
    m.print();
    m.sub(b);
    m.print();
    m.mul(b);
    m.print();

    return 0;
}

