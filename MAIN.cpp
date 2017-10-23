# complex-0.0.1

#include <iostream>

using namespace std;

struct complex_t {
	float real;
	float imag;
};

istream & read(istream & stream, complex_t & complex) {
	char a, b, c;
	float x, y;
	

	if (stream >> a && a == '(' && stream >> x && stream >> b && b == ',' && stream >> y && stream >> c && c == ')') {
		complex.real = x;
		complex.imag = y;
	}
	else {
		stream.setstate(std::ios::failbit);
	}

	return stream;
}

ostream & write(ostream & stream, complex_t complex) {
	stream << "(" << complex.real << "," << complex.imag << ")";
	return stream;
}

complex_t add(complex_t lhs, complex_t rhs) {
	complex_t result;
	result.real = lhs.real + rhs.real;
	result.imag = lhs.imag + rhs.imag;
	
	return result;
}

complex_t sub(complex_t lhs, complex_t rhs) {
	complex_t result;
	result.real = lhs.real - rhs.real;
	result.imag = lhs.imag - rhs.imag;

	return result;
 }

complex_t mul(complex_t lhs, complex_t rhs) {
	complex_t result;
	result.real = (lhs.real * rhs.real) - (lhs.imag * rhs.imag) ;
	result.imag = (lhs.real * rhs.imag) + (lhs.imag * rhs.real);
	
	return result;
 }

complex_t div(complex_t lhs, complex_t rhs) {
	complex_t result;
	result.real = (lhs.real * rhs.real + lhs.imag * rhs.imag) / ((rhs.real)*(rhs.real) + (rhs.imag)*(rhs.imag));
	result.imag = (lhs.imag * rhs.real - lhs.real * rhs.imag) / ((rhs.real)*(rhs.real) + (rhs.imag)*(rhs.imag));
	return result;
 }


int main()
{
	complex_t a,b;
	char op;

	if (read(cin, a)) {
		cin >> op;
		if (read(cin, b)) {
			switch (op) {
				case '+':
					write(cout, add(a,b));
					break;
				case '-':
					write(cout, sub(a, b));
					break;
				case '*':
					write(cout, mul(a, b));
					break;
				case '/':
					write(cout, div(a, b));
					break;
				}
			}else  cout <<"An error has occured while reading input data"; 

	}else  cout << "An error has occured while reading input data";
	
	cin.get();
	cin.get();

    return 0;
}
