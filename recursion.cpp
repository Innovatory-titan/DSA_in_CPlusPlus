#include <bits/stdc++.h>
using namespace std;

string binaryFormat(int decimal, string formatter){
	if (decimal == 0) return formatter;
	formatter = to_string(decimal % 2) + formatter;
	return binaryFormat(decimal/2, formatter);
}

int main(){
	int decimal = 5673;
	cout << binaryFormat(decimal, "") << endl;
	return 0;
}
