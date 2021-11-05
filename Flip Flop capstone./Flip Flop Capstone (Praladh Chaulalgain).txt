// The Flip Flop lab for very large integer 
// using the sign at the beginning 
// using functions and file stream
// Programmer:Praladh Chaulagain
// Date modified: 2019/12/01

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printBanner(string msg1, string msg2, ostream& os = cout);
void printInstructions(int flop, int flip, string msg1, string msg2, ostream& os = cout);
void connectOutStream(string& fileName, ofstream& outStream);
string getValidLargeInteger();
bool isValidLargeInteger(string num);
bool hasSign(string num);
int sumOfDigits(string num);
int lastDigitValue(string num);
void printResults(string num, int flop, int flip, string msg2, string msg1, ostream& os = cout);
void  printDebuggingMessages(string num, ostream& os = cout);
void digitValue(string num, ostream& os);

int main()
{
	system("color E0");
	system("title Flip Flop for Very large number with sign by C.Praladh");

	string fileName, number;
	int total, digit;
	const int
		FLIP = 5,
		FLOP = 3;

	const string
		MSG_1 = "FLIP",
		MSG_2 = "FLOP";

	printBanner(MSG_1, MSG_2);
	printInstructions(FLOP, FLIP, MSG_1, MSG_2);

	ofstream outStream;
	cout << "What is the filename you want to store your output? ";

	connectOutStream(fileName, outStream);
	printBanner(MSG_1, MSG_2, outStream);
	printInstructions(FLOP, FLIP, MSG_1, MSG_2, outStream);

	cout << "\nWhat is your number ? ";
	number = getValidLargeInteger();

	while (cin)  
	{
		cout << "\n\n";
		digitValue(number, outStream);

		printResults(number, FLOP, FLIP, MSG_1, MSG_2);
		printResults(number, FLOP, FLIP, MSG_1, MSG_2, outStream);

		cout << "\n\t  Debugging couts in printResults function:";
		printDebuggingMessages(number);
		printDebuggingMessages(number, outStream);

		cout << " \n\t*******************************************\n\n";

		cout << "\nWhat is your number? ";
		number = getValidLargeInteger();
	}
	outStream.close();
	cin.clear();
	cout << "\t\n You can find the log of this run at the filename in " << fileName;
	cin.get();
	return 0;
}

void printBanner(string msg1, string msg2, ostream& os)
{
	os << "\n"
		<< "\t                         " << msg1 << " " << msg2 << " \n"
		<< "\t     for VERY Large Numbers that would overflow any type of int                 \n"
		<< "\t          accepts signs at the begining of the num                              \n"
		<< "\t                     Sample Solution                                            \n"
		<< "\t                     Using Functions                                            \n"
		<< "\t                     by C . Praladh                                             \n\n";  
}

void printInstructions(int flop, int flip, string msg1, string msg2, ostream& os)  // done
{
	os << "\n"
		<< "This program prints:                                                  \n"
		<< "   \"" << msg2 << "\" if a number is divisible by " << flop << "                 \n"
		<< "   \"" << msg1 << "\" if divisible by " << flop << " and			               \n"
		<< "   \"" << msg1 << " " << msg2 << "\" if divisible by BOTH " << flip << " and " << flop << "  \n"
		<< "    nothing if divisible by NEITHER                                  \n\n";
}
void connectOutStream(string& fileName, ofstream& outStream)  // done
{
	getline(cin >> ws, fileName);
	outStream.open(fileName);

	while (outStream.fail()) {
		cout << "Cannot open the filename" << fileName
			<< "please provide the different filename";
		getline(cin >> ws, fileName);
		outStream.open(fileName);
	}
}

string getValidLargeInteger()  // done
{
	string number;
	getline(cin >> ws, number);

	while (!(isValidLargeInteger(number)))
	{
		cout << "\tPlease provide a legal number.";
		cout << "\n\nWhat is your number? ";
		getline(cin >> ws, number);

	}
	return number;
}

bool isValidLargeInteger(string num)  // done
{
	if (num.size() == 1 && hasSign(num))
		return false;

	for (int i = (hasSign(num) ? 1 : 0); i < num.size(); i++)
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return false;
	}
	return true;
}

bool hasSign(string num)   //  done
{
	// make that 1 line and 1 statement
	return num[0] == '+' || num[0] == '-';

}

int sumOfDigits(string num)   //  done
{
	int sum = 0;

	for (int i = (hasSign(num) ? 1 : 0); i < num.size(); i++)
	{  // have the initialization of the loop varien in the for
		sum += num[i] - '0';  // avoid declaration in the loop body
	}
	return sum;
}

int lastDigitValue(string num)  // done
{
	// make 1 line and 1 statement
	return num[num.size() - 1] - '0';
}

void printResults(string num, int flop, int flip, string msg2, string msg1, ostream& os)  // done
{
	os << "       " << (lastDigitValue(num) == flip || lastDigitValue(num) == 0 ? msg2 : "")
		<< "       " << (sumOfDigits(num) % flop == 0 ? msg1 : "");
}

void printDebuggingMessages(string num, ostream& os)  // done
{
	os << "\n\t  The int value of the last digit in \"num\"\n"
		<< "\t\t  (here call the corresponding function) is " << (lastDigitValue(num)) << endl
		<< "\t  The sum of digits in \"num\"\n"
		<< "\t\t  (here call the corresponding function) is " << sumOfDigits(num) << endl;
}

void digitValue(string num, ostream& os) 
{
	os << "\n\t" << "Your number was " << num;
}