// The swap function lab
// using files for reading data and using it's value
// programmer:Praladh Chaulagain
//date modified: 2019/11/02

#include <iostream>
#include <fstream>
using namespace std;

//function prototype
void printbanner();
void rearrange(int& num1, int& num2, int& num3);

int num1, num2, num3;

int main()
{
	system("color 7d");
	system("title my swap function and driver");

	printbanner();
	// opening the fle
	ifstream infile;


	infile.open("Data.txt");
	// if fileopen fails
	if (infile.fail())
	{
		system("color 90");
		cout << "\a";
		cout << " Failed to open the input file named \"Data.txt\" \n"
			<< "Make sure the file is located in the same directory as your exe\n"
			<< "and it is spelled correctly including spacing and the filename extension.\n"
			<< "  ****    I am exiting the program.    ***";
		exit(0);
	}


	cout << "\nThe test data set MUST be in a file called \"Data.txt\".";

	while (infile >> num1 >> num2 >> num3)
	{
			cout << "\nBefore the call: x = " << num1 << " y = " << num2 << " z = " << num3 << endl;
		cout << num1 << num2 << num3 << endl;

		rearrange(num1, num2, num3);
		cout << "After the call: x = " << num1 << " y = " << num2 << " z = " << num3 << endl;
		cout << num1 << num2 << num3 << endl;
	}

	infile.close();
	system("pause");

	cout << "\n HARDWIRED testing (using a for loop and a table format) \n";

	cout << "\tx \t y \tz \n";
	cout << "\t=================\n";

	for (int i = 1; i <= 6; i++) {
		switch (i) {
		case 1: num1 = 1, num2 = 2, num3 = 3;			break;
		case 2: num1 = 1, num2 = 3, num3 = 2;			break;
		case 3: num1 = 2, num2 = 1, num3 = 3;			break;
		case 4: num1 = 2, num2 = 3, num3 = 1;			break;
		case 5: num1 = 3, num2 = 1, num3 = 2;			break;
		case 6: num1 = 3, num2 = 2, num3 = 1;           break;
		}

		cout << "Start: " << num1 << "\t" << num2 << "\t" << num3 << endl;
		rearrange(num1, num2, num3);
		cout << "End:   " << num1 << "\t" << num2 << "\t" << num3 << endl << endl;

	}
	system("pause");

}
void printbanner() {

	cout << "\t\t Lab on Driver testing the Rearrange function.             \n"
		<< "\t\t      Rearrange ANY number of sets of three numbers         \n"
		<< "\t\t            from a given input file \"Data Set.txt\"        \n"
		<< "\t\t                    by Praladh Chaulagain                   \n";
}

void mySwap(int& num1, int& num2) {
	int zero;
	zero = num2;
	num2 = num1;
	num1 = zero;
}

void rearrange(int& num1, int& num2, int& num3) {

	if (num1 > num3) {
		mySwap(num1, num3);
	}
	if (num1 > num2) {
		mySwap(num1, num2);
	}
	if (num2 > num3)
		mySwap(num2, num3);

}

