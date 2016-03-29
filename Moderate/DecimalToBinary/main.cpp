/*
	Name: Decimal To Binary
	Copyright: NA
	Author: Taylor Glenn
	Date: 17/01/16 22:53
	Description: Enter a decimal integer.  Return binary string.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> decimalToBinary(int decimalNumber);

int main(int argc, char *argv[]) {
	string input;
	while(getline(cin,input)){
		int decimalNumber = atoi(input.c_str());
		vector<int> binaryNumber;
		binaryNumber = decimalToBinary(decimalNumber);
		for(int i = 0; i < binaryNumber.size(); i++){
			cout << binaryNumber[i];
		}
		cout << "\n";
	}
	return 0;
}

vector<int> decimalToBinary(int decimalNumber){
	vector<int> binaryNumber;
	vector<int> output;
	binaryNumber.push_back(0);
	for(int i = 0; i < decimalNumber; i++){
		binaryNumber[0]++;
		for(int bit = 0; bit < binaryNumber.size(); bit++){
			if(binaryNumber[bit] == 2){
				if(bit == (binaryNumber.size() - 1)){
					binaryNumber.push_back(0);
				}
				binaryNumber[bit] = 0;
				binaryNumber[bit + 1]++;
			}
		}
	}
	for(int q = (binaryNumber.size() - 1); q >= 0; q--){
		output.push_back(binaryNumber[q]);
	}
	return output;
}
