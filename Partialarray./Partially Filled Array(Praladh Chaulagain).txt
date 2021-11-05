// This Program assigns value to the array and print their statistics.
// Partially Filled Arrays finding average ,maximum,and minimum value.
// Progammer:Praladh Chaulagain
// Late Modified: 20th nov, 2019.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int loadArray(double array[], int number, double max, string errorMsg = "THE NUMBER");
void printArray(const double array[], int num, int line = 5, ostream& os = cout);
double validMaxNum(double max, string inputMsg = "THE NUMBER");
void printBanner(int physicalSize, ostream& os = cout);
double  totalMaxValue(const double array[], int size);
double totalMinValue(const double array[], int size);
double calcAverage(const double array[], int size);
void printStats(const double array[], int size, ostream& os = cout);
double getPos(string inputMsg = "THE NUMBER");
int  getIntLessThan(int screensize, string inputMsg = "THE NUMBER");
double getNum();
int getPosInt(string inputMsg = "THE NUMBER");

int main()
{
	system("title Partially Filled Arrays by Praladh Chaulagain");
	system(" color 0A");
	cout << fixed << showpoint << setprecision(2);

	const int
		PHYSICAL_SIZE = 30;
	int	logicalSize, line = 0, screensize;
	double scores[PHYSICAL_SIZE], max;


	ofstream file;
	file.open("Grade Book.txt");


	printBanner(PHYSICAL_SIZE);

	cout << "What is the maximun number of columns that can FIT in your screen ? ";
	screensize = getPosInt("NUM OF COLUMNS");

	while (true)
	{
		cout << "\n\n What is the maximum possible student score for this class? ";
		max = getPos("MAX STUDENT SCORE");

		cout << "\n\nEnter the students' scores. Enter a negative value to stop.\n"
			<< "\tPhysical size of the array is " << PHYSICAL_SIZE << "\n\n";

		logicalSize = loadArray(scores, PHYSICAL_SIZE, max, "student score");
		cout << "\n\nDone loading scores.\n"
			<< "\tLogical size is : " << logicalSize << endl;

		cout << "\n\nI am about to print the scores and statistics.\n";

		if (logicalSize == 0) {
			cout << "\t The array is empty!";
		}
		else
		{
			cout << "\nHere are the scores that you have stored in your array.\n"
				"\t Note that the maximum value in the array should not exceed " << max;
			cout << "\n\nHow many elements do you want to print per line" << " [1-" << screensize << "]? ";
			line = getIntLessThan(screensize);
			printArray(scores, logicalSize, line);

			cout << "\n\nHere are the statistics:\n";

			printStats(scores, logicalSize);
		}
		cout << "\n\n\t   ************************\n\n";

		printBanner(PHYSICAL_SIZE, file);
		printArray(scores, logicalSize, line, file);
		printStats(scores, logicalSize, file);

		file.close();
	}
}

int  getIntLessThan(int screensize, string inputMsg) {
	double line;
	line = getNum();
	while (line > screensize || line < 0 || line != int(line)) {
		system("color 7d");
		if (line > screensize)
			cout << "\a\tELEMENTS PER LINE must be a LESS than " << screensize << " number.Try again :";
		else
			cout << "\tPlease enter a" << (line != int(line) ? " whole" : "") << (line < 0 ? " positive" : "") << " number.Try again : ";
		line = getNum();
	}
	system("color 0A");
	return int(line);
}

int loadArray(double array[], int physicalsize, double max, string errorMsg)
{
	int i = 0;
	double	valid = 0;
	for (i = 0; i < physicalsize; i++)
	{
		cout << "Enter score for student  #" << i + 1 << ": ";
		valid = validMaxNum(max, errorMsg);
		array[i] = valid;
		cout << ((i + 1 == physicalsize) ? "Array FULL! Cannot accept any more input." : "");
		if (array[i] < 0)
			break;
	}
	return i;
}

void printArray(const double array[], int num, int line, ostream& os)
{

	for (int i = 0; i < num; i++)
	{
		os << "\t" << array[i] << "\t" << ((i + 1) % line == 0 ? "\n" : "");
	}
}

double getNum()  // done
{
	double number;
	cin >> number;
	cin.ignore(100, '\n');
	while (cin.fail()) {

		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\a Invalid Input.Please enter a number.Try again : ";
		cin >> number;
		cin.ignore(100, '\n');
	}
	return number;
}

double getPos(string inputMsg)
{
	double score = getNum();

	while ((score <= 0)) {
		cout << "\a \t Invalid " << inputMsg << ".Please enter a number more than 0. Try again :";
		score = getNum();
	}
	return score;
}

double validMaxNum(double max, string inputMsg)
{
	double number = getNum();

	while (number > max)
	{
		cout << "  \a Invalid Student Score. Please enter" << inputMsg << "less than " << max << " . Try again: ";
		cin >> number;
		cin.ignore(100, '\n');
	}
	return number;
}

void printBanner(int physicalSize, ostream& os)  // file
{
	os << "\n"
		<< "\t\t           This program loads an array of doubles with students\' score                            \n"
		<< "\t\t                 using a negative value as the loop\'s sentinel                                    \n"
		<< "\t\t                         calculate basic statistics                                                \n"
		<< "\t\t            setting physical size to " << physicalSize << " and default per line 5                 \n"
		<< "\t\t                                by C.Praladh                                                     \n\n";
}

double totalMaxValue(const double array[], int size)
{
	double maxValue = array[0];
	for (int i = 0; i < size; i++)
		if (array[i] > maxValue)
			maxValue = array[i];
	return maxValue;
}

double totalMinValue(const double array[], int size)
{
	double totalMinValue = array[0];
	for (int i = 0; i < size; i++)
		if (array[i] < totalMinValue)
			totalMinValue = array[i];
	return totalMinValue;
}

double calcAverage(const double array[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
		total += array[i];
	return total / size;
}

void printStats(const double array[], int size, ostream& os)
{
	os << "\n\t*** The highest score is : " << totalMaxValue(array, size);
	os << "\n\t*** The lowest  score is : " << totalMinValue(array, size);
	os << "\n\t*** The average score is : " << calcAverage(array, size) << endl;
}

int getPosInt(string inputMsg) {
	double validsize;
	validsize = getNum();
	while (validsize <= 0)
	{
		system("color 7d");
		cout << "\a\t" << inputMsg << " must be a POSITIVE number. Try again: ";
		validsize = getNum();
	}
	system("color 0A");
	return int(validsize);
}