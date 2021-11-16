# include <iomanip>
# include <iostream>
#include <vector>
#include "gaussian.h"
using std::vector;
using std::cout;
using std::endl;
using matrix = vector<vector<double>>;


//****************************************************************************80
void printMatrix(const matrix& m);
vector<vector<double>> transpose(vector<vector<double> > a);
matrix multiply(matrix A, matrix B);
int main ( )
{

    //Ax = b
    //to find the least squares solution for this problem, we must use the formula
    //A transpose * A * x = A transpose * b
    //which changes to A transpose A / A transpose B = solution x
    //a two-dimensional matrix represented by a multidimensional vector.

    vector<vector<double>> a;
    vector<vector<double>> aT;
    vector<vector<double>> b;
    vector<double> x;

    /* equivalent to
     *     |1 1 |            |2|
     * A = |1 -1| * x  = (b= |1| )
     *     |1 1 |            |3|
     */
//    a = {{1,1},{1,-1},{1,1}};
//    b = {{2},{1},{3}};

    a = {{4,2,3,0},{-2,3,-1,1},{1,3,-4,2},{1,0,1,-1},{3,1,3,-2}};
    b = {{10},{0},{2},{0},{5}};
    //a 1 dimensional b matrix to represent the output of Ax

    cout << "A matrix: "<< endl;
    printMatrix(a);
    cout << endl;
    cout <<"A transpose:" <<endl;

    aT = transpose(a);
    printMatrix(aT);
    cout << endl <<"A transpose * A" <<endl;
    matrix AtA = multiply(aT, a);
    printMatrix(AtA);
    cout << endl;
    cout << "A transpose * b"<<endl;
    matrix Atb = multiply(aT, b);
    printMatrix(Atb);
    auto gaussianFormat(AtA);
    int i =0;
    for(auto row : gaussianFormat) {
        gaussianFormat[i].push_back(Atb[i][0]);
        i++;
    }
    gaussian(gaussianFormat);
}


void printMatrix(const matrix& m){
    int i =0;
    for( const auto& vec : m) {
        cout << "Row: "<<i<<": ";
        for(auto num : vec){
            cout << num <<"    ";
        }
        i++;
        cout <<endl;
    }
}

matrix multiply(matrix A, matrix B)
{
    matrix C ;
    for (unsigned int i = 0u; i < A.size(); i++){
        C.push_back(vector<double>{});
        for (unsigned int j = 0; j < B[0].size(); j++){
            C[i].push_back(0);
            for (unsigned int k = 0; k < A[0].size();k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

vector<vector<double>> transpose(vector<vector<double> > a)
{

    vector<vector<double> > aTranspose (a[0].size(), vector<double>());

    for (unsigned int i = 0; i < a.size(); i++)
    {
        for (unsigned int j = 0; j < a[i].size(); j++)
        {
            aTranspose[j].push_back(a[i][j]);
        }
    }
    return aTranspose;
}
