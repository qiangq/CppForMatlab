#include "MatSta.h"
#include <cmath>
using namespace std;

/* Construct Matrix using row number and column number(both recommended to be larger than 1). All Entries are set to 0*/
Matrix::Matrix(int RowNum,int ColNum)
{
	int RowCnt=0;
	this->RowNum=RowNum;
	this->ColNum=ColNum;
	this->Head=new double *[RowNum];
	for (RowCnt=0;RowCnt<RowNum;RowCnt++)
	{
		this->Head[RowCnt]=new double[ColNum]();
	}
}

/* Construct Matrix using row number and column number(both recommended to be larger than 1). All Entries equal to IniVal*/
Matrix::Matrix(int RowNum,int ColNum,double IniVal)
{
	int RowCnt=0,ColCnt=0;
	this->RowNum=RowNum;
	this->ColNum=ColNum;
	this->Head=new double *[RowNum];
	for (RowCnt=0;RowCnt<RowNum;RowCnt++)
	{
		this->Head[RowCnt]=new double[ColNum]();
		for (ColCnt=0;ColCnt<ColNum;ColCnt++)
		{
			this->Head[RowCnt][ColCnt]=IniVal;
		}
	}
}

/* Matrix Destructor*/
Matrix::~Matrix()
{
	int RowCnt=0;
	for (RowCnt=RowNum-1;RowCnt>=0;RowCnt--)
	{
		delete[] Head[RowCnt];
	}
	delete[] Head;
}

/* Matrix Copy Constructor*/
Matrix::Matrix(Matrix & MatObj)
{
	int RowCnt=0,ColCnt=0;
	this->RowNum=MatObj.RowNum;
	this->ColNum=MatObj.ColNum;
	this->Head=new double *[this->RowNum];
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		this->Head[RowCnt]=new double[this->ColNum]();
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			this->Head[RowCnt][ColCnt]=MatObj.Head[RowCnt][ColCnt];
		}
	}
}

/* Matrix Constructor using Vector, RowNum is set to 1*/
Matrix:: Matrix(Vector &VecObj)
{
	int RowCnt=0,ColCnt=0;
	this->RowNum=1;
	this->ColNum=VecObj.Length;
	this->Head=new double *[this->RowNum];
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		this->Head[RowCnt]=new double[this->ColNum]();
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			this->Head[RowCnt][ColCnt]=VecObj.Head[RowCnt];
		}
	}
}

/* Matrix+double*/
Matrix Matrix::operator +(double AddVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix AddRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			AddRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]+AddVal;
		}
	}
	return AddRes;
}

/* Matrix-double*/
Matrix Matrix::operator -(double SubVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix SubRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			SubRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]-SubVal;
		}
	}
	return SubRes;
}

/* Matrix>double*/
Matrix Matrix::operator >(double CmpVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]>CmpVal;
		}
	}
	return CmpRes;
}

/* Matrix<double*/
Matrix Matrix::operator <(double CmpVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]<CmpVal;
		}
	}
	return CmpRes;
}

/* Matrix>=double*/
Matrix Matrix::operator >=(double CmpVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]>=CmpVal;
		}
	}
	return CmpRes;
}

/* Matrix<=double*/
Matrix Matrix::operator <=(double CmpVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]<=CmpVal;
		}
	}
	return CmpRes;
}

/* Matrix==double*/
Matrix Matrix::operator ==(double CmpVal)
{
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]==CmpVal;
		}
	}
	return CmpRes;
}

/* Matrix+Matrix*/
Matrix Matrix::operator +(Matrix AddMatObj)
{
	if ((this->RowNum!=AddMatObj.RowNum)||(this->ColNum!=AddMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix AddRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			AddRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]+AddMatObj.Head[RowCnt][ColCnt];
		}
	}
	return AddRes;
}

/* Matrix-Matrix*/
Matrix Matrix::operator -(Matrix SubMatObj)
{
	if ((this->RowNum!=SubMatObj.RowNum)||(this->ColNum!=SubMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix SubRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (RowCnt=0;RowCnt<this->ColNum;RowCnt++)
		{
			SubRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]-SubMatObj.Head[RowCnt][ColCnt];
		}
	}
	return SubRes;
}

/* Matrix>Matrix*/
Matrix Matrix::operator >(Matrix CmpMatObj)
{
	if ((this->RowNum!=CmpMatObj.RowNum)||(this->ColNum!=CmpMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]>CmpMatObj.Head[RowCnt][ColCnt];
		}
	}
	return CmpRes;
}

/* Matrix<Matrix*/
Matrix Matrix::operator <(Matrix CmpMatObj)
{
	if ((this->RowNum!=CmpMatObj.RowNum)||(this->ColNum!=CmpMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]<CmpMatObj.Head[RowCnt][ColCnt];
		}
	}
	return CmpRes;
}

/* Matrix>=Matrix*/
Matrix Matrix::operator >=(Matrix CmpMatObj)
{
	if ((this->RowNum!=CmpMatObj.RowNum)||(this->ColNum!=CmpMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]>=CmpMatObj.Head[RowCnt][ColCnt];
		}
	}
	return CmpRes;
}

/* Matrix<=Matrix*/
Matrix Matrix::operator <=(Matrix CmpMatObj)
{
	if ((this->RowNum!=CmpMatObj.RowNum)||(this->ColNum!=CmpMatObj.ColNum)) //Size match check
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]<=CmpMatObj.Head[RowCnt][ColCnt];
		}
	}
	return CmpRes;
}

/* Matrix==Matrix*/
Matrix Matrix::operator ==(Matrix CmpMatObj)
{
	if ((this->RowNum!=CmpMatObj.RowNum)||(this->ColNum!=CmpMatObj.ColNum))
	{
		throw 1;
	}
	int RowCnt=0,ColCnt=0;
	Matrix CmpRes(this->RowNum,this->ColNum);
	for (RowCnt=0;RowCnt<this->RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<this->ColNum;ColCnt++)
		{
			CmpRes.Head[RowCnt][ColCnt]=this->Head[RowCnt][ColCnt]==CmpMatObj.Head[RowCnt][ColCnt];
		}
	}
	return CmpRes;
}

/* Vector Constructor using Length. All entries are set to 0. No difference between row vector and column vector*/
Vector::Vector(int Length)
{
	this->Length=Length;
	this->Head=new double[Length]();
}

/* Vector Constructor using Length. All entries are set to IniVal*/
Vector::Vector(int Length,double IniVal)
{
	int LenCnt=0;
	this->Length=Length;
	this->Head=new double[Length];
	for (LenCnt=0;LenCnt<Length;LenCnt++)
	{
		this->Head[LenCnt]=IniVal;
	}
}

/* Vector Copy Constructor*/
Vector::Vector(Vector &VecObj)
{
	int LenCnt=0;
	this->Length=VecObj.Length;
	this->Head=new double[this->Length];
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		this->Head[LenCnt]=VecObj.Head[LenCnt];
	}
}

/*Vector Constructor using Matrix. Get the first row*/
Vector::Vector(Matrix &MatObj)
{
	int LenCnt=0;
	this->Length=MatObj.ColNum;
	this->Head=new double[Length];
	for (LenCnt=0;LenCnt<Length;LenCnt++)
	{
		this->Head[LenCnt]=MatObj.Head[0][LenCnt];
	}
}

/* Vector Destructor*/
Vector::~Vector()
{
	delete[] Head;
}

/* Vector+double*/
Vector Vector::operator +(double AddVal)
{
	int LenCnt=0;
	Vector AddRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		AddRes.Head[LenCnt]=this->Head[LenCnt]+AddVal;
	}
	return AddRes;
}

/* Vector-double*/
Vector Vector::operator -(double SubVal)
{
	int LenCnt=0;
	Vector SubRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		SubRes.Head[LenCnt]=this->Head[LenCnt]-SubVal;
	}
	return SubRes;
}

/* Vector>double*/
Vector Vector::operator >(double CmpVal)
{
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]>CmpVal;
	}
	return CmpRes;
}

/* Vector<double*/
Vector Vector::operator <(double CmpVal)
{
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]<CmpVal;
	}
	return CmpRes;
}

/* Vector>=double*/
Vector Vector::operator >=(double CmpVal)
{
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]>=CmpVal;
	}
	return CmpRes;
}

/* Vector<=double*/
Vector Vector::operator <=(double CmpVal)
{
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]<=CmpVal;
	}
	return CmpRes;
}

/* Vector==double*/
Vector Vector::operator ==(double CmpVal)
{
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]==CmpVal;
	}
	return CmpRes;
}

/* Vector+Vector*/
Vector Vector::operator +(Vector AddVecObj)
{
	if (this->Length!=AddVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector AddRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		AddRes.Head[LenCnt]=this->Head[LenCnt]+AddVecObj.Head[LenCnt];
	}
	return AddRes;
}

/* Vector-Vector*/
Vector Vector::operator -(Vector SubVecObj)
{
	if (this->Length!=SubVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector SubRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		SubRes.Head[LenCnt]=this->Head[LenCnt]-SubVecObj.Head[LenCnt];
	}
	return SubRes;
}

/* Vector>Vector*/
Vector Vector::operator >(Vector CmpVecObj)
{
	if (this->Length!=CmpVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]>CmpVecObj.Head[LenCnt];
	}
	return CmpRes;
}

/* Vector<Vector*/
Vector Vector::operator <(Vector CmpVecObj)
{
	if (this->Length!=CmpVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]<CmpVecObj.Head[LenCnt];
	}
	return CmpRes;
}

/* Vector>=Vector*/
Vector Vector::operator >=(Vector CmpVecObj)
{
	if (this->Length!=CmpVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]>=CmpVecObj.Head[LenCnt];
	}
	return CmpRes;
}

/* Vector<=Vector*/
Vector Vector::operator <=(Vector CmpVecObj)
{
	if (this->Length!=CmpVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]<=CmpVecObj.Head[LenCnt];
	}
	return CmpRes;
}

/* Vector==Vector*/
Vector Vector::operator ==(Vector CmpVecObj)
{
	if (this->Length!=CmpVecObj.Length) // Length match check
	{
		throw 2;
	}
	int LenCnt=0;
	Vector CmpRes(this->Length);
	for (LenCnt=0;LenCnt<this->Length;LenCnt++)
	{
		CmpRes.Head[LenCnt]=this->Head[LenCnt]==CmpVecObj.Head[LenCnt];
	}
	return CmpRes;
}

/* sum of each column of Matrix*/
Vector sum(Matrix MatObj)
{
	int RowCnt=0,ColCnt=0;
	Vector SumRes=Vector(MatObj.ColNum);
	for (ColCnt=0;ColCnt<MatObj.ColNum;ColCnt++)
	{
		for (RowCnt=0;RowCnt<MatObj.RowNum;RowCnt++)
		{
			SumRes.Head[ColCnt]+=MatObj.Head[RowCnt][ColCnt];
		}
	}
	return SumRes;
}

/* sum of Vector*/
double sum(Vector VecObj)
{
	int LenCnt=0;
	double SumRes=0;
	for (LenCnt=0;LenCnt<VecObj.Length;LenCnt++)
	{
		SumRes+=VecObj.Head[LenCnt];
	}
	return SumRes;
}

/* max value of each column of Matrix*/
Vector max(Matrix  MatObj)
{
	int ColCnt=0,RowCnt=0;
	Vector MaxRes=Vector(MatObj.ColNum);
	for (ColCnt=0;ColCnt<MatObj.ColNum;ColCnt++)
	{
		MaxRes.Head[ColCnt]=MatObj.Head[0][ColCnt];
		for (RowCnt=0;RowCnt<MatObj.RowNum;RowCnt++)
		{
			if (MaxRes.Head[ColCnt]<MatObj.Head[RowCnt][ColCnt])
			{
				MaxRes.Head[ColCnt]=MatObj.Head[RowCnt][ColCnt];
			}
		}
	}
	return MaxRes;
}

/* max value of Vector*/
double max(Vector VecObj)
{
	int LenCnt=0;
	double MaxRes=VecObj.Head[0];
	for (LenCnt=0;LenCnt<VecObj.Length;LenCnt++)
	{
		if (MaxRes<VecObj.Head[LenCnt])
		{
			MaxRes=VecObj.Head[LenCnt];
		}
	}
	return MaxRes;
}

/* min value of each column of Matrix*/
Vector min(Matrix MatObj)
{
	int ColCnt=0,RowCnt=0;
	Vector MinRes=Vector(MatObj.ColNum);
	for (ColCnt=0;ColCnt<MatObj.ColNum;ColCnt++)
	{
		MinRes.Head[ColCnt]=MatObj.Head[0][ColCnt];
		for (RowCnt=0;RowCnt<MatObj.RowNum;RowCnt++)
		{
			if (MinRes.Head[ColCnt]>MatObj.Head[RowCnt][ColCnt])
			{
				MinRes.Head[ColCnt]=MatObj.Head[RowCnt][ColCnt];
			}
		}
	}
	return MinRes;
}

/* min value of Vector*/
double min(Vector VecObj)
{
	int LenCnt=0;
	double MinRes=VecObj.Head[0];
	for (LenCnt=0;LenCnt<VecObj.Length;LenCnt++)
	{
		if (MinRes>VecObj.Head[LenCnt])
		{
			MinRes=VecObj.Head[LenCnt];
		}
	}
	return MinRes;
}

/* abs of Matrix*/
Matrix abs(Matrix MatObj)
{
	int RowCnt=0,ColCnt=0;
	Matrix AbsRes=Matrix(MatObj.RowNum,MatObj.ColNum);
	for (RowCnt=0;RowCnt<MatObj.RowNum;RowCnt++)
	{
		for (ColCnt=0;ColCnt<MatObj.ColNum;ColCnt++)
		{
			AbsRes.Head[RowCnt][ColCnt]=abs(MatObj.Head[RowCnt][ColCnt]);
		}
	}
	return AbsRes;
}

/* abs of Vector*/
Vector abs(Vector VecObj)
{
	int LenCnt=0;
	Vector AbsRes=Vector(VecObj.Length);
	for (LenCnt=0;LenCnt<VecObj.Length;LenCnt++)
	{
		AbsRes.Head[LenCnt]=abs(VecObj.Head[LenCnt]);
	}
	return AbsRes;
}
