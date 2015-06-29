# CppForMatlab
Cpp Class aiming to ease the burden to convert Matlab code into Cpp code.

For those who develop algorithms in Matlab but need to convert the algorithm in Cpp code, the burden of conversion is usually heavy. With the Matrix and Vector class provided here as well as related functions (only a few are available now), the code in Cpp and in Matlab will be very similar, thus easing the workload. For example, if the Matlab code is:

A=zeros(3,3)+1;
B=max(abs(A)>1);
C=sum(B);

With the classes provided, the Cpp code can be:

Matrix A=zeros(3,3)+1;
Vector B=max(abs(A)>1);
double C=sum(B);

Therefore you can easily complete the conversion. Please note if you have high expectation in efficiency, it is recommended that you write your Cpp code (or C code) in a more direct way, such as using two-dimensional arrays for matrix, which can be faster than the above classes.

Till now, only two-dimensional matrix and one-dimensional vector are supported. Currently available functions include:

zeros, ones and initialization with single initial value;

max, min, sum, abs;

basic calculations with matrix or vector in the same size: >, <, >=, <=, ==, +, -;

basic calculations with single number: >, <, >=, <=, ==, +, -;

More functions will be updated in the future.
