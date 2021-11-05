// The total array with random numbers Lab
// using function to print out the big array and small array 
// Programmer:Praladh Chaulagain
// Date modified: 2019/11/9

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// function prototype
void printBanner(ostream& os = cout);
void loadArray(int arrays[], int arraySize);
void printArray(const int arrays[], int size, ostream& os = cout, int line = 5);

int main()
{
	system("title Total array with random numbers by Pral Chaulagain");
	system("color E0");

	ofstream outS;
	outS.open("print array and banner .txt");

	const int
		SMALL_SIZE = 12,
		BIG_SIZE = 100;

	int smallarray[SMALL_SIZE], bigarray[BIG_SIZE];

	printBanner();
	printBanner(outS);

	// small array part
	cout << " \n\n    **************    SMALL array    **************  \n\n";

	cout << "I am about to fully load smallArray with random generated numbers ...\n\n";
	loadArray(smallarray, SMALL_SIZE);
	cout << "Finished loadding smallArray ...\n\n";

	cout << "I am about to call printArray (with the default value for the perLine)... \n";
	printArray(smallarray, SMALL_SIZE);
	printArray(smallarray, SMALL_SIZE, outS);
	cout << "\n\n";

	system("pause");

	// big array part
	cout << " \n\n    **************    BIG array    **************  \n\n";
	cout << "I am about to fully load bigArray with random generated numbers ...\n\n";
	loadArray(bigarray, BIG_SIZE);
	cout << "Finished loadding bigArray ...\n\n";

	cout << "I am about to call printArray(with 8 perLine)...\n\n";
	printArray(bigarray, BIG_SIZE, cout, 8);
	printArray(bigarray, BIG_SIZE, outS, 8);

	cout << "\n\n";
	system("pause");
}

void printBanner(ostream& os)
{
	os << "\n"
		<< "\t\t        This is a lab on completely filled arrays           \n"
		<< "\t\t             with randomly generated numbers                \n"
		<< "\t\t      the SAME load function is used to load BOTH arrays    \n"
		<< "\t\t      the SAME print function is used to print BOTH arrays  \n"
		<< "\t\t                  by Praladh chaulagain                     \n";
}

void loadArray(int arrays[], int arraySize)   //style 
{
	int seed = time(0);
	srand(seed);

	for (int i = 0; i < arraySize; i++)
	{
		arrays[i] = rand();
	}
}

void printArray(const int arrays[], int size, ostream& os, int line)
{
	for (int i = 0;i < size;i++)
	{
		os << arrays[i] << "\t" << ((i + 1) % line == 0 ? "\n" : "");
	}
}