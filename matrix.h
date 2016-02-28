
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<exception>

using namespace std;

class DIM_EXP : public exception
{
	virtual const char* what() const throw()
	{
		return "Dimension Mismatch Exception";
	}
} DIMENTION_MISMATCH_EXCEPTION;

class Mat_Lab
{
public:
	Mat_Lab(int, int);
	Mat_Lab(int, int, float);
	void Iterative_algo(int, int, int, int, Mat_Lab*);
	void place(int, int, int, int, Mat_Lab&);
	void Squaremat();
	~Mat_Lab();
	int row;
	int col;
	float** array_;
	Mat_Lab* operator*(Mat_Lab&);
	void operator=(Mat_Lab*);
	bool operator==(Mat_Lab&);
	Mat_Lab* operator+(Mat_Lab*);
	Mat_Lab* StrassenAlgo(Mat_Lab*);
	

private:
	void _fil_rand();
	void _crt_array_();
	void _crt_array_(float);
};

Mat_Lab::Mat_Lab(int row, int col)
{
	this->row = row;
	this->col = col;

	_crt_array_();

	_fil_rand();
}

Mat_Lab::Mat_Lab(int row, int col, float crt_val)
{
	this->row = row;
	this->col = col;

	_crt_array_(crt_val);
}

void Mat_Lab::Squaremat()
{
	int r = 0;
	int c = 0;	
	
	if(row	 >= col)
	{
		r = row;
		c = row;
	}
	else
	{
		r = col;
		c = col;
	}
	float** arr = new float*[r];
	for(int i = 0; i< r;++i)
	{
		arr[i] = new float[r];
	}
	for(int  i  = 0; i< r;++i)
		for(int j =0; j <r ; ++j)
		{
			arr[i][j] = 0;
		}

	for(int  i  = 0; i< row; ++i)
		for(int j =0; j <col ; ++j)
		{
			arr[i][j] = array_[i][j];
		}

	delete array_;
	
	array_ = arr;
	return ;
	
}


void Mat_Lab::Iterative_algo(int rs, int re, int cs, int ce, Mat_Lab* o) 
{
	for (int i = 0; rs < re; rs++, i++)
	{
		int _cs = cs;
		for (int j = 0; _cs < ce; _cs++, j++)
		{
			array_[i][j] = o->array_[rs][_cs];
		}
	}
}


void Mat_Lab::place(int rs, int re, int cs, int ce, Mat_Lab& o)
{
	for (int i = 0; rs < re; rs++, i++)
	{
		int _cs = cs;
		for (int j = 0; _cs < ce; _cs++, j++)
		{
			array_[rs][_cs] = o.array_[i][j];
		}
	}
}

void Mat_Lab::_crt_array_() 
{
	array_ = new float*[row];
	for (int i = 0; i < row; i++)
	{
		array_[i] = new float[col];
	}
}

void Mat_Lab::operator=(Mat_Lab* o)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array_[i][j] = o->array_[i][j];
		}
	}
}

bool Mat_Lab::operator==(Mat_Lab& o)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array_[i][j] != o.array_[i][j])
				return false;
		}
	}
	return true;
}

Mat_Lab* Mat_Lab::operator+(Mat_Lab* o)
{
	if (row != o->row || col != o->col)
		throw DIMENTION_MISMATCH_EXCEPTION;

	Mat_Lab* r = new Mat_Lab(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			r->array_[i][j] = array_[i][j] + o->array_[i][j];
		}
	}
	return r;
}

void Mat_Lab::_crt_array_(float crt_val)
{
	array_ = new float*[row];
	for (int i = 0; i < row; i++)
	{
		array_[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			array_[i][j] = crt_val;
		}
	}
}

Mat_Lab* Mat_Lab::operator*(Mat_Lab& o)
{
	if (col != o.row)
		throw DIMENTION_MISMATCH_EXCEPTION;

	Mat_Lab *r = new Mat_Lab(row, o.col);

	for (int i = 0; i < r->row; i++)
	{
		for (int j = 0; j < r->col; j++)
		{
			r->array_[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				r->array_[i][j] += array_[i][k] * o.array_[k][j];
			}
		}
	}

	return r;
}

Mat_Lab* Mat_Lab::StrassenAlgo(Mat_Lab* o)
{


	if (col != o->row)
		throw DIMENTION_MISMATCH_EXCEPTION;
	
	
	this->Squaremat();
	o->Squaremat();

	if (row == 2)
	{
		return (*this * *o);
	}
	else 
	{
		int div_size = row / 2;
		int end = row;
		
		Mat_Lab* r = new Mat_Lab(row, col, 0);
		Mat_Lab A11(div_size, div_size, 0);
		A11.Iterative_algo(0, div_size, 0, div_size, this);
		Mat_Lab A12(div_size, div_size, 0);
		A12.Iterative_algo(0, div_size, div_size, end, this);
		Mat_Lab A21(div_size, div_size, 0);
		A21.Iterative_algo(div_size, end, 0, div_size, this);
		Mat_Lab A22(div_size, div_size, 0);
		A22.Iterative_algo(div_size, end, div_size, end, this);

		Mat_Lab* B11 = new Mat_Lab(div_size, div_size, 0);
		B11->Iterative_algo(0, div_size, 0, div_size, o);
		Mat_Lab* B12 = new Mat_Lab(div_size, div_size, 0);
		B12->Iterative_algo(0, div_size, div_size, end, o);
		Mat_Lab* B21 = new Mat_Lab(div_size, div_size, 0);
		B21->Iterative_algo(div_size, end, 0, div_size, o);
		Mat_Lab* B22 = new Mat_Lab(div_size, div_size, 0);
		B22->Iterative_algo(div_size, end, div_size, end, o);

		r->place(0, div_size, 0, div_size, *(*(A11.StrassenAlgo(B11)) + (A12.StrassenAlgo(B21))));
		r->place(0, div_size, div_size, end, *(*(A11.StrassenAlgo(B12)) + (A12.StrassenAlgo(B22))));
		r->place(div_size, end, 0, div_size, *(*(A21.StrassenAlgo(B11)) + (A22.StrassenAlgo(B21))));
		r->place(div_size, end, div_size, end, *(*(A21.StrassenAlgo(B12)) + (A22.StrassenAlgo(B22))));

		return r;
	}
}

void Mat_Lab::_fil_rand()
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array_[i][j] = rand() % 100;
		}
	}
}




Mat_Lab::~Mat_Lab()
{
	for (int i = 0; i < row; i++)
	{
		delete[] array_[i];
	}
	delete array_;
}
