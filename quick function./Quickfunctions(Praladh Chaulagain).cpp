// The lab that calls the quick functions
// to find absoulte value, sum product and prime number
// programmer: Praladh Chaulagain
// date modified: 10/21/2019

#include <iostream>
using namespace std;

// prototype functions
void printbanner();   // done
double calcAbs(double num);  // done
double calSumprod(double num1, double num2);   // done
bool  isPrime(int checknum);  // done
int getPrimenum(int checknum);
int calSum(int total);

int main() {
	system("color 7d"); // console color
	system("title quick function lab to find absolute, prime and sum product ");// title

	printbanner();


	// literal declaration
	double num1, num2;
	double checknum;




	while (true) {
		//statements for calling function to get absolute value
		cout << "what number you want me to find the absolute value of? ";
		cin >> num1;
		cin.ignore(100, '\n');

		cout << "The absolute value of " << num1 << " is " << calcAbs(num1) << endl;
		cout << "===========================================\n\n";


		// statements for calling function to get sum products of two numbers

		cout << "what is your first number? ";
		cin >> num1;
		cin.ignore(100, '\n');
		cout << "what is your second number? ";
		cin >> num2;
		cin.ignore(100, '\n');
		cout << "The results of sumprod with arguments " << num1 << " and " << num2 << " is " << calSumprod(num1, num2) << endl;
		cout << "===========================================\n\n";

		// statements for calling function to check given number is prime number
		cout << "Please give me a number and I will tell you if it is prime or not: ";
		cin >> num1;
		cin.ignore(100, '\n');
		cout << "your number " << num1 << (isPrime(num1) ? " is not a" : " is  a ") << " prime number\n" << endl;
		cout << "===========================================\n\n";

		//statements for calling function to call function which terminates on getting prime number
		cout << "please give me the prime number  ";
		cin >> num1;
		cin.ignore(100, '\n');
		cout << "you gave me " << getPrimenum(num1) << " which is a prime number " << endl;
		cout << "===========================================\n\n";

		// statements for calling function to get the sum of positive
		//numbers which terminates on getting negative number and finds sum.
		cout << "Please enter as many POSITIVE numbers as you like. Enter any negative number to end the loop and see the sum.";
		cin >> num1;
		cin.ignore(100, '\n');
		cout << "your total sum of positive number is " << calSum(num1) << endl;
		cout << "===========================================\n\n";
		system("pause");
		return 0;
	}
}

//function for banner
void printbanner()
{
	cout << "\n"
		<< "\t\t\t   quick function lab         \n"
		<< "\t\t\t doing different functions    \n"
		<< "\t\t\t   by: Praladh Chaulagain   \n\n";
}

//function for absolute number
double calcAbs(double num)  // done
{
	return (num < 0 ? -num : num);
}

// function for getting sumproduct 
double calSumprod(double num1, double num2) {

	return (num1 >= 0 && num2 >= 0) || num1 < 0 && num2 < 0 ? (num1 + num2) : (num1 * num2);
}

// function for checking prime or not
bool isPrime(int checknum)
{

	for (int i = 2; i <= checknum / 2; ++i)
	{
		if (checknum % i == 0)
			return true;
	}
	return false;
}

// function for validating loop until it gets prime number
int getPrimenum(int checknum)
{
	while (isPrime(checknum) == true) {
		cout << checknum << " is not a prime number. please give me a prime number : ";
		cin >> checknum;

	}
	return checknum;
}


// function to find sum of all postive number and terminates loop if negative number is provided
int calSum(int num1)
{

	int total = 0;
	while (num1 > -1) {
		total += num1;
		cin >> num1;

	}
	return total;
}
