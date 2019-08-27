#include <iostream>
using namespace std;
class Fraction
{
	public:

		void set_den(int value);
		void set_num(int value);
		double evaluate();
		void print_normalised();
		void print_normal();
	private:
		int num;
		int den;
		int compute_gcd();
};


void Fraction::set_den(int value)
{
	den = value;
}

void Fraction::set_num(int value)
{
	num = value;
}

double Fraction::evaluate()
{
	return num/(double)den;
}

int Fraction::compute_gcd()
{

	int min = num > den ? den : num;
	int gcd = 1;
	for(int i = 2; i <= min; i++)
	{
		if(num%i == 0 && den%i == 0)
			gcd = i;
	}

	return gcd;
}

void Fraction::print_normalised()
{
	cout << num/compute_gcd() << "/" <<den/compute_gcd();
}

void Fraction::print_normal()
{
	cout << num << "/" <<den;
}

int main()
{
	int den, num;
	cout << "Please enter the numerator: ";
	cin >> num;
	cout << "Please enter the denominator: ";
	cin >> den;
    Fraction fraction1;
	fraction1.set_num(num);
	fraction1.set_den(den);
	cout << "Your fraction is: ";
	fraction1.print_normal();
	cout << endl;
	cout << "The value of fraction is: " << fraction1.evaluate() << endl;
	cout << "The fraction in lowest form is: " ;
	fraction1.print_normalised();
	cout << endl;
}
