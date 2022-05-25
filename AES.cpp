#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, string> m;

string gfunc(string w,int round) {
	string s1 = w.substr(0, 3);
	string s2 = w.substr(4, 7);
	string s_1 = m[s1];
	string s_2 = m[s2];
	string x;
	if (round == 1)
		x = "10000000";
	else
		x = "00110000";
	string k_1 = s_1 + s_2;
	for (int i = 0; i < 8; i++) {
		if (k_1[i] == x[i])
			k_1[i] = '0';
		else
			k_1[i] = '1';
	}
	string w2 = k_1;
	return w2;
}

int main() {
	m["0000"] = "1001";
	m["0001"] = "0100";
	m["0010"] = "1010";
	m["0011"] = "1011";
	m["0100"] = "1101";
	m["0101"] = "0001";
	m["0110"] = "1000";
	m["0111"] = "0101";
	m["1000"] = "0110";
	m["1001"] = "0010";
	m["1010"] = "0000";
	m["1011"] = "0011";
	m["1100"] = "1100";
	m["1101"] = "1110";
	m["1110"] = "1111";
	m["1111"] = "0111";
	string key;
	cout << "Input 16 bit key: " << endl;
	cin >> key;
	string w0 = key.substr(0, 7);
	string w1 = key.substr(8, 15);
	string k_2 = gfunc(w1,1);
	string w2="";
	for (int i = 0; i < 8; i++) {
		if (k_2[i] == w0[i])
			w2+="0";
		else
			w2 += "1";
	}
	string w3="";
	for (int i = 0; i < 8; i++) {
		if (w2[i] == w1[i])
			w3 += "0";
		else
			w3 += "1";
	}
	k_2 = gfunc(w3, 2);
	string w4 = "";
	for (int i = 0; i < 8; i++) {
		if (k_2[i] == w2[i])
			w4 += "0";
		else
			w4 += "1";
	}
	string w5 = "";
	for (int i = 0; i < 8; i++) {
		if (w4[i] == w3[i])
			w5 += "0";
		else
			w5 += "1";
	}
	string key1 = w2 + w3;
	string key2 = w4 + w5;
	cout << "key for round 1: " << key1 << endl;
	cout << "key for round 2: " << key2 << endl;
	return 0;
}