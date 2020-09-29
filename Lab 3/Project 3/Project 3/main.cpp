
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

float meanFunction(int, int, int, int);
float stdFunction(int, int, int, int, float);

int main()
{
	int value1;
	int value2;
	int value3;
	int value4; 

	ifstream inputFilename;
	ofstream outputFilename;

	inputFilename.open("inMeanStd.dat");
	outputFilename.open("outMeanStd.dat");

	inputFilename >> value1 >> value2 >> value3 >> value4;

	outputFilename << " The mean of the four integers is: " << fixed << setprecision(4) << endl;
	cout << " The mean of the four integers is: " << meanFunction(value1, value2, value3, value4) << fixed << setprecision(4) << endl;

	outputFilename << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6);
	cout << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6);


	cout << "Enter four integers. Kindly make sure to then hit enter between your integers" << endl;
	cin >> value1 >> value2 >> value3 >> value4;

	outputFilename << "The mean of the integers user entered: " << meanFunction(value1, value2, value3, value4) << endl;
	outputFilename << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4));

	cout << "The program calculated the following values:" << endl;
	cout << "Mean =  " << meanFunction(value1, value2, value3, value4) << endl;

	cout << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4));

	inputFilename.close();
	outputFilename.close();

	return 0;

}

float meanFunction(int value1, int value2, int value3, int value4)
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average)
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2) + pow((value4 - average), 2)) / 4));
}

