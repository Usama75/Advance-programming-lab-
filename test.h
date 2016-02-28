
#include "Matrix.h"
#include <memory>
#include <iostream>




bool test_create() 
{
	bool temp = true;
	Mat_Lab farig(128, 128);
	
	temp &= (farig.row == 128 && farig.col == 128);

	
	Mat_Lab farig2(128, 128);
	
	
	temp &= (farig2.row == 128 && farig2.col == 128);

	return temp;
}

bool test_crt()
{
	bool temp = true;
	
	Mat_Lab farig(128, 128, 0);
	
	
	for (int i = 0; i < farig.row; i++)
	{
		for (int j = 0; j < farig.col; j++)
		{
			temp &= (farig.array_[i][j] == 0);
		}
	}

	
	Mat_Lab farig2(128, 128, 2);
	
	
	for (int i = 0; i < farig2.row; i++)
	{
		for (int j = 0; j < farig2.col; j++)
		{
			temp &= (farig2.array_[i][j] == 2);
		}
	}
	

	return temp;
}

bool test_Iterative_algo()
{
	bool temp = true;
	
	Mat_Lab farig(128, 128);
	Mat_Lab farig2(128, 128);
	farig.Iterative_algo(128, 128, 128, 128, &farig2);
	
	for (int i = 0, r = 128; r < 128; r++, i++)
	{
		for (int j = 0, c = 128; c < 128; c++, j++)
		{
			temp &= (farig.array_[i][j] == farig2.array_[r][c]);
		}
	}



	return temp;
}

bool test_StrassenAlgo()
{
	bool temp = true;
	
	Mat_Lab farig(128, 128);
	
	Mat_Lab farig2(128, 128);
	

	std::auto_ptr<Mat_Lab> mat1(farig * farig2);
	std::auto_ptr<Mat_Lab> mat2(farig.StrassenAlgo(&farig2));

	

	temp &= (*mat1 == *mat2);

	

	return temp;
}
