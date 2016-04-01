/*

Code Eval
CHALLENGE DESCRIPTION:

Credits: Programming Challenges by Steven S. Skiena and Miguel A. Revilla

You will be given the x/y co-ordinates of several locations. You will be laying out 1 cable between two of these locations. In order to minimise the cost, your task is to find the shortest distance between a pair of locations, so that pair can be chosen for the cable installation.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. The input
 file contains several sets of input. Each set of input starts with an
 integer N (0<=N<=10000), which denotes the number of points in this set.
 The next N line contains the coordinates of N two-dimensional points. The
 first of the two numbers denotes the X-coordinate and the latter denotes the
 Y-coordinate. The input is terminated by a set whose N=0. This set should not
 be processed. The value of the coordinates will be less than 40000 and
 non-negative. eg.

5
0 2
6 67
43 71
39 107
189 140
0

OUTPUT SAMPLE:

For each set of input produce a single line of output containing a floating
point number (with four digits after the decimal point) which denotes the
distance between the closest two points. If there is no such two points in the
input whose distance is less than 10000, print the line INFINITY. eg.

36.2215

*/
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

vector<double> delimetedStringToDoubleVector(string, char);
double hypotenuse(double, double);
double getSmallestDoubleFromVector(vector<double>&);
void printDoubleVectorWithDelimeter(vector<double>&, char);

int main(int argc, char *argv[]) {
	string input;
	ifstream stream("C:\\Users\\Taylor\\Documents\\Projects\\CodeEval\\ClosestPair\\sample.txt");
	int line = 0;
	int numberOfPoints = 0;
	vector<double> x;
	vector<double> y;
	vector<double> distances;
	//while(getline(stream, input)){
	while(getline(cin,input)){
		if(input.compare("0") == 0){
			for(int pointA = 0; pointA < x.size(); pointA++){
				for(int pointB = 0; pointB < x.size(); pointB++){
					distances.push_back(hypotenuse(abs(x[pointB] - x[pointA]), abs(y[pointB] - y[pointA])));
				}
			}
			double smallestValue = getSmallestDoubleFromVector(distances);
			if(smallestValue > 9999){
				cout << "INFINITY\n";
			} else {
				cout << fixed << setprecision(4) << smallestValue << "\n";
			}
			x.clear();
			y.clear();
			distances.clear();
			line = 0;
		}else{
			if(line > 0){
				vector<double> point = delimetedStringToDoubleVector(input, ' ');
				x.push_back(point[0]);
				y.push_back(point[1]);
			}
			line++;
		}
	}
	return 0;
}

vector<double> delimetedStringToDoubleVector(string inputString, char delimeter){
	vector<double> outputVector;
	stringstream ss(inputString);
	double x;
	while(ss >> x){
		outputVector.push_back(x);
		if(ss.peek() == delimeter){
			ss.ignore();
		}
	}
	return outputVector;
}

double hypotenuse(double a, double b){
	return sqrt((a*a)+(b*b));
}

double getSmallestDoubleFromVector(vector<double>& inputVector){
	double output = inputVector[1];
	for(int i = 0; i < inputVector.size(); i++){
		if((output > inputVector[i]) && (inputVector[i] != 0)){
			output = inputVector[i];
		}
	}
	return output;
}

void printDoubleVectorWithDelimeter(vector<double>& inputVector, char delimeter){
	for(int i = 0; i < inputVector.size(); i++){
		if(i > 0){
			cout << delimeter;
		}
		cout << inputVector[i];
	}
	cout << "\n";
}
