//Реализуйте класс double_vector - массив вещественных чисел переменного размера

#include <vector>
#include <iostream>
using namespace std;

class double_vector {

  public:
  int m,n;

  public:
  double_vector(){   //конструктор без аргументов
  	double_vector * arr = new double_vector [1];
    *(double_vector + 0) = 0;
	} 

	double_vector(int length){   //конструктор с одним аргументом
	 double_vector * arr = new double_vector [unsigned int length];
   for (int i = 0; i < length; i++){
   *(double_vector + i) = 0;
   }
	}

  ~double_vector(){   //деструктор
   delete [] arr;
  }

  double_vector(const double_vector& A){   //конструктор копирования
    
  }

  const double_vector &operator = (const double_vector &A){   //оператор присвоения
		m = A.m;
		n = A.n;
		return *this;
	}

  double_vector operator[](unsigned int n){   //оператор индексации
    return arr [n];
  }

 unsigned int size(){   //получение размера вектора
  return arr.size;
 }

 unsigned int capacity(){   //получение вместимости вектора
  return arr.capacity;
 }

 public:
void push_back (double x){   //добавление в конец
  arr.resize(length + 1);
  *(arr + length) = x;
 }

 double pop_back(){   //извлечение из конца
  int k = *(arr + length - 1);
  arr.erase (arr.begin() + length - 1))
  arr.resize(length - 1);
  return k;
 }

 
 double_vector(double* arr ,int length){   //конструктор, создающий вектор по double-массиву и его размеру
   double_vector vec = new double_vector [length];
   for (int i = 0; i < length; i++){
     *(vec + i) = *(arr + i);
   }
 }

 void resize (int x){   //изменение вместимости массива
  vec.resize (length + x);
 }

 void push_front (double x){   //добавление в начало
  arr.resize(length + 1);
  for (int i = length - 1; i > 0; i--){
    *(arr + i) = *(arr + i - 1);
  }
  *(arr + 0) = x;
 }

 void pop_front(){   //удаление из начала
  arr.erase (arr.begin());
  for (int i = 1; i < length; i++){
    *(arr + i - 1) = *(arr + i);
  }
  arr.resize(length - 1);
 }

 void insert(double x, int pos){   //добавление на заданную позицию
   arr.resize(length + 1);
   for (int i = length - 1; i >= pos; i--){
    *(arr + i) = *(arr + i - 1);
  }
  *(arr + pos - 1) = x;
 }

 void erase(int pos){   //удаление из заданной позиции
   arr.erase (arr.begin() + pos - 1);
   for (int i = pos; i < length; i++){
    *(arr + i - 1) = *(arr + i);
  }
    arr.resize(length - 1);
 }

 void erase_interval (int a, int b){
  arr.erase (arr.begin() + a - 1,arr.begin() + b - 1);   //удаление интервала по индексам концов отрезка
  arr.resize(length - (b - a + 1));
 }


double_vector &operator + (double_vector A, const double_vector &B) {    // +
	return A += B;
}
double_vector &operator - (double_vector A, const double_vector &B) {    // -
	return A -= B;
}
double_vector &operator * (double_vector A, const double_vector &B) {    // *
	return A *= B;
}
double_vector &operator / (double_vector A, const double_vector &B) {    // /
	return A /= B;
}


bool operator == (const double_vector &A, const double_vector &B) {    // ==
	return ((A.m == B.m) && (A.n == B.n));
}
bool operator != (const double_vector &A, const double_vector &B) {    // !=
	return ! (A == B);
}
bool operator > (const double_vector &A, const double_vector &B) {    // >
	return ((((A.m*B.n) - (B.m * A.n)>0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) < 0) && (A.n*B.n < 0)));
}
bool operator < (const double_vector &A, const double_vector &B) {    // <
	return ((((A.m*B.n) - (B.m * A.n)<0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) > 0) && (A.n*B.n < 0)));
}
bool operator >= (const double_vector &A, const double_vector &B) {    // >=
	return !(A < B);
}
bool operator <= (const double_vector &A, const double_vector &B) {    // <=
	return !(A > B);
}

istream &operator >>(istream &in, double_vector &A)    // ввод
{
	in >> A.m;
	return in;
}

ostream &operator <<(ostream &out, const double_vector &A)    // вывод
{
	out << A.m;
	return out;
}

};

 



int main() {

   
    int size,x,pos,a,b;
    cin >> size;

    double_vector * arr = new double_vector [size];
    for (int i = 0; i < size; i++){
      cin >> *(arr + i);
    }

    cin >> x;
    arr.push_back (x);
    for (int i = 0; i < size; i++){
      cout <<  *(arr + i);
    }
    arr.pop_back();

    arr.push_front (x);
    for (int i = 0; i < size; i++){
      cout <<  *(arr + i);
    }
    arr.pop_front();

    cin >> pos;
    arr.insert(x,pos);
    for (int i = 0; i < size; i++){
      cout <<  *(arr + i);
    }

    arr.erase(pos);

    cin >> a >> b;
    arr.erase_interval(a,b);
    for (int i = 0; i < size; i++){
      cout <<  *(arr + i);
    }


 return 0;
}
