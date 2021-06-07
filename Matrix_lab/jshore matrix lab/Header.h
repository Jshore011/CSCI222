#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define SIZE 3

using namespace std;

class Matrix
{
private:
	int dimension = 0;
	float matricies[SIZE][SIZE];
	float** dynamicMatrix = NULL;

public:
	friend ostream& operator<<(ostream&, Matrix const&);
	Matrix();
	Matrix(int dimension);
	Matrix(float, float, float,
		float, float, float,
		float, float, float);
	Matrix(Matrix const&);
	~Matrix();

	Matrix& operator=(Matrix const&);
	Matrix operator+(Matrix const&) const;
	Matrix operator-(Matrix const&) const;
	Matrix operator^(int const) const;
	Matrix operator*(Matrix const&) const;
	Matrix operator~() const;
	Matrix operator++();  // pre-increment
	Matrix operator++(int); // post-increment
	Matrix operator--();  // pre-increment
	Matrix operator--(int); // post-increment
};
