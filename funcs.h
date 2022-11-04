#pragma once
#include <vector>
using std::vector;

//old
char unshift(char c, int rshift);
std::string decipher(std::string plaintext, int rshift);
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);


// add prototypes here
bool alphabetically_order(std::string a, std::string b);

std::string solve(std::string encrypted_string);
vector<float> english();
//std::vector<char> alphabetical();
std::string every(std::string cipher);
vector<float> count(std::string letter, std::vector<char> order);
int compare(std::vector<float> frq, std::vector<float> corn);
std::string solve(std::string encrypted_string);
