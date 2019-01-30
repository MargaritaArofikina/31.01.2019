

#include <iostream>
using namespace std;




struct array {

  int size;
  int m;
  int n;

 array &operator = (const array &A){   //присвоение =
		m = A.m;
		n = A.n;
		return *this;
 }
  array &operator [] (const array &A, int size){   //размер массива []
  	m = size;
    int * A = new int [2m];
    for (int i = 0; i < m; i ++){
      *(A + m + i) = *(A + i);
    }
		return *this;
 }

};

array &operator + (int A, const int &B) {    // +
	return A += B;
}
array &operator - (int A, const int &B) {    // -
	return A -= B;
}
array &operator * (int A, const int &B) {    // *
	return A *= B;
}
array &operator / (int A, const int &B) {    // /
	return A /= B;
}


bool operator == (const int &A, const int &B) {    // ==
	return ((A.m == B.m) && (A.n == B.n));
}
bool operator != (const int &A, const int &B) {    // !=
	return ! (A == B);
}
bool operator > (const int &A, const int &B) {    // >
	return ((((A.m*B.n) - (B.m * A.n)>0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) < 0) && (A.n*B.n < 0)));
}
bool operator < (const int &A, const int &B) {    // <
	return ((((A.m*B.n) - (B.m * A.n)<0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) > 0) && (A.n*B.n < 0)));
}
bool operator >= (const int &A, const int &B) {    // >=
	return !(A < B);
}
bool operator <= (const int &A, const int &B) {    // <=
	return !(A > B);
}



istream &operator >>(istream &in, int &A)    // ввод >>
{
	in >> A.m >> A.n;
	return in;
}
ostream &operator <<(ostream &out, const int &A)    // вывод <<
{
	out << A.m << "/" << A.n;
	return out;
}

int main (){

int size;
array A = new array [2*size];

for (int i = 0; i < size; i++){
  cin >> *(A + i);
  *(A + size + i) = *(A + i);
}


return 0;
}
