#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

string intToEnglish(int);

int main() {
	int n = 12402323;
	cout << intToEnglish(n) << endl;
}

string intToEnglish(int num) {
	if (num == 0) return "zero";
	ostringstream readOut;
	if (num < 0) readOut << "negative ";
	int toRead = abs(num);
	vector<string> largeNums = {"", "thousand", "million", "billion", 
		"trillion", "quadrillion", "quintillion", "sextillion"};
	int leftOver = toRead;
	int magnitude = 0;
	while (leftOver >= 1000) {
		leftOver /= 1000; // divide by a thousand
		magnitude++;
	}
	for (int j = magnitude; j > 0; j--) {
		int reading = toRead/pow(1000,j);
		readOut << intToEnglish(reading % 1000) << " " << largeNums[j] << " ";
	}
	// Initialize string of numbers from zero to nine
	string nums[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	int threeLSB = toRead % 1000;
	int hundredsPlace = threeLSB / 100;
	int remainder = threeLSB % 100;
	if (hundredsPlace != 0) {
		readOut << nums[hundredsPlace] << " hundred";
		if (remainder != 0) {
			readOut << " and ";
		}
	}
	if (remainder >= 20) { // twenty to ninety
		readOut << tens[remainder / 10];
		if (remainder % 10 != 0) {
			readOut << "-";
		}
	}
	if (remainder < 10 || remainder >= 20) { // ones position
		readOut << nums[remainder % 10];
	} else { // ten to nineteen
		readOut << teens[remainder - 10];
	}
	return readOut.str();
}