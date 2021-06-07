#include "Header.h"

ostream& operator<<(ostream& out, Matrix const& x)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out << "| " << x.matricies[i][j];
		}
		out << " |" << endl;
	}

	return out;
}
Matrix::Matrix()
{
	//float matricies[SIZE][SIZE] = { 0 };
	dimension = 3;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matricies[i][j] = 0;
}

Matrix::Matrix(int dimension)
{
	dynamicMatrix = new float*[dimension];

	for (int i = 0; i < dimension; i++)
	{
		dynamicMatrix[i] = new float[dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			dynamicMatrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(float a1, float a2, float a3,
	float b1, float b2, float b3,
	float c1, float c2, float c3)
{
	matricies[0][0] = a1;
	matricies[0][1] = a2;
	matricies[0][2] = a3;
	matricies[1][0] = b1;
	matricies[1][1] = b2;
	matricies[1][2] = b3;
	matricies[2][0] = c1;
	matricies[2][1] = c2;
	matricies[2][2] = c3;
}

Matrix::Matrix(Matrix const& x)//copy constructor
{
	//float matricies[SIZE][SIZE] = {0};


	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matricies[i][j] = x.matricies[i][j];
}

Matrix::~Matrix()
{
	if (dynamicMatrix != NULL)
	{
		//delete subarrays 
		for (int i = 0; i < dimension; i++)
		{
			delete[] dynamicMatrix[i];
		}

		//delete the pointer array
		delete[] dynamicMatrix;
	}
}

Matrix& Matrix::operator=(Matrix const& x)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matricies[i][j] = x.matricies[i][j];

	return *this;
}


Matrix Matrix::operator+(Matrix const& x) const
{
	Matrix C;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			C.matricies[i][j] = matricies[i][j] + x.matricies[i][j];

	return C;
}

Matrix Matrix::operator-(Matrix const& x) const
{
	Matrix C;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			C.matricies[i][j] = matricies[i][j] - x.matricies[i][j];

	return C;
}

Matrix Matrix::operator*(Matrix const& x) const
{
	Matrix C;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
				C.matricies[i][j] += this->matricies[i][k] * x.matricies[k][j];
		}
	}

	return C;
}

Matrix Matrix::operator^(int n) const
{
	Matrix C(1, 1, 1, 1, 1, 1, 1, 1, 1);

	for (int i = 0; i < n; i++)
		C = C * (*this);

	return C;
}

Matrix Matrix::operator~() const
{
	Matrix C;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			C.matricies[i][j] = matricies[j][i];

	return C;
}

Matrix Matrix::operator++()
{
	Matrix I, C;

	for (int i = 0; i < SIZE; i++)
		I.matricies[i][i] = 1;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			C.matricies[i][j] = I.matricies[i][j] + matricies[i][j];
			matricies[i][j] = matricies[i][j] + I.matricies[i][j];
		}

	return C;
}

Matrix Matrix::operator++(int x)
{
	Matrix I, C;

	for (int i = 0; i < SIZE; i++)
		I.matricies[i][i] = 1;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			C.matricies[i][j] = matricies[i][j];
			matricies[i][j] = matricies[i][j] + I.matricies[i][j];
		}

	return C;
}


Matrix Matrix::operator--()
{
	Matrix I, C;

	for (int i = 0; i < SIZE; i++)
		I.matricies[i][i] = 1;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			C.matricies[i][j] = I.matricies[i][j] + matricies[i][j];
			matricies[i][j] = matricies[i][j] - I.matricies[i][j];
		}

	return C;
}

Matrix Matrix::operator--(int x)
{
	Matrix I, C;

	for (int i = 0; i < SIZE; i++)
		I.matricies[i][i] = 1;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			C.matricies[i][j] = matricies[i][j];
			matricies[i][j] = matricies[i][j] - I.matricies[i][j];
		}

	return C;
}