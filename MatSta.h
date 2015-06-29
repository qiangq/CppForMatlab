class Matrix; // Matrix and Vector Statement 
class Vector;

class Matrix // Matrix Definition
{
public:
	Matrix(int RowNum,int ColNum);
	Matrix(int RowNum,int ColNum,double IniVal);
	Matrix(Matrix &MatObj);
	Matrix(Vector &VecObj);
	~Matrix();
	Matrix operator +(double AddVal);
	Matrix operator -(double SubVal);
	Matrix operator >(double ComVal);
	Matrix operator <(double ComVal);
	Matrix operator >=(double ComVal);
	Matrix operator <=(double ComVal);
	Matrix operator ==(double ComVal);
	Matrix operator +(Matrix AddMatObj);
	Matrix operator -(Matrix SubMatObj);
	Matrix operator >(Matrix ComMatObj);
	Matrix operator <(Matrix ComMatObj);
	Matrix operator >=(Matrix ComMatObj);
	Matrix operator <=(Matrix ComMatObj);
	Matrix operator ==(Matrix ComMatObj);
	double **Head;
	int RowNum;
	int ColNum;
};

class Vector // Vector Definition
{
public:
	Vector(int Length);
	Vector(int Length,double IniVal);
	Vector(Vector &VecObj);
	Vector(Matrix &MatObj);
	~Vector();
	Vector operator +(double AddVal);
	Vector operator -(double SubVal);
	Vector operator >(double ComVal);
	Vector operator <(double ComVal);
	Vector operator >=(double ComVal);
	Vector operator <=(double ComVal);
	Vector operator ==(double ComVal);
	Vector operator +(Vector AddVecObj);
	Vector operator -(Vector SubVecObj);
	Vector operator >(Vector ComVecObj);
	Vector operator <(Vector ComVecObj);
	Vector operator >=(Vector ComVecObj);
	Vector operator <=(Vector ComVecObj);
	Vector operator ==(Vector ComVecObj);
	double *Head;
	int Length;
};

/* initialization functions define*/
#define zeros(x,y) (x==1)?(Vector(x)):((y==1)?(Vector(y)):(Matrix(x,y)))      // Use Matrix or Vector Constructor Directly Recommended
#define ones(x,y) (x==1)?(Vector(x,1)):((y==1)?(Vector(y,1)):(Matrix(x,y,1))) // Use Matrix or Vector Constructor Directly Recommended

/* Matrix and Vector Function Statement*/
Vector sum(Matrix MatObj); /* sum of each column of Matrix*/
double sum(Vector VecObj); /* sum of Vector*/
Vector max(Matrix MatObj); /* max value of each column of Matrix*/
double max(Vector VecObj); /* max value of Vector*/
Vector min(Matrix MatObj); /* min value of each column of Matrix*/
double min(Vector VecObj); /* min value of Vector*/
Matrix abs(Matrix MatObj); /* abs of Matrix*/
Vector abs(Vector VecObj); /* abs of Vector*/
