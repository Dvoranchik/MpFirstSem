

#include "stdafx.h"
#include "gtest\gtest.h"
#include "Fun.h"
TEST(Matrix, copy)
{
	Matrix matrix(2, 2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;

	Matrix copy(matrix);

	for (int i = 0; i<2; ++i)
		for (int j = 0; j < 2; ++j)
			EXPECT_EQ(matrix[i][j], copy[i][j]);
}

TEST(Matrix, operator_prisvaivania)
{
	Matrix matrix(2, 2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;

	Matrix matrix2 = matrix;
	for (int i = 0; i<2; ++i)
		for (int j = 0; j < 2; ++j)
			EXPECT_EQ(matrix[i][j], matrix2[i][j]);
}

TEST(Matrix, operator_ravenstvo)
{
	Matrix matrixOne(2, 2);
	matrixOne[0][0] = 1;
	matrixOne[0][1] = 2;
	matrixOne[1][0] = 3;
	matrixOne[1][1] = 4;

	Matrix matrixTwo(2, 2);
	matrixTwo[0][0] = 1;
	matrixTwo[0][1] = 2;
	matrixTwo[1][0] = 3;
	matrixTwo[1][1] = 4;

	EXPECT_TRUE(matrixOne == matrixTwo);
}

TEST(Matrix, operator_summa)
{
	Matrix matrixOne(2, 2);
	matrixOne[0][0] = 1;
	matrixOne[0][1] = 2;
	matrixOne[1][0] = 3;
	matrixOne[1][1] = 4;

	Matrix matrixTwo(matrixOne);
	Matrix summa(2, 2);

	summa = matrixOne + matrixTwo;

	Matrix rezult(2, 2);
	rezult[0][0] = 2;
	rezult[0][1] = 4;
	rezult[1][0] = 6;
	rezult[1][1] = 8;

	EXPECT_TRUE(summa == rezult);
}

TEST(Matrix, mult)
{
	Matrix matrixOne(2, 3);
	matrixOne[0][0] = 2;
	matrixOne[0][1] = 1;
	matrixOne[1][0] = 1;
	matrixOne[1][1] = 1;
	matrixOne[1][2] = 1;
	matrixOne[0][2] = 1;

	Matrix matrixThree(3, 2);
	matrixThree[0][0] = 1;
	matrixThree[0][1] = 1;
	matrixThree[1][0] = 1;
	matrixThree[1][1] = 1;
	matrixThree[2][0] = 1;
	matrixThree[2][1] = 1;

	Matrix summa(2, 2);
	summa = matrixOne * matrixThree;

	Matrix rezult(2, 2);
	rezult[0][0] = 4;
	rezult[0][1] = 4;
	rezult[1][0] = 3;
	rezult[1][1] = 3;
	
	EXPECT_TRUE(summa == rezult);
	
}
TEST(Matrix, file)
{
	Matrix matrix(2, 2);
	EXPECT_NO_THROW(matrix.setMatrix("file.txt"));

	Matrix matrixFile(2, 2);
	matrixFile[0][0] = 1;
	matrixFile[0][1] = 2;
	matrixFile[1][0] = 3;
	matrixFile[1][1] = 4;

	EXPECT_TRUE(matrix == matrixFile);
	EXPECT_THROW(matrix.setMatrix("file1.txt"), std::runtime_error);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}