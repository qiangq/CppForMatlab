#include<iostream>
#include "MatSta.h"
using namespace std;

int main()
{
	try{
	// edit your code here
	}

	catch (int ErrNum) //Exception 
	{
		switch (ErrNum)
		{
		case 1:
			printf("Matrix Mismatch\n");
			break;
		case 2:
			printf("Vector Mismatch\n");
			break;
		}
	}
	return 0;
}
