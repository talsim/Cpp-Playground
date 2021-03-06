#include <iostream>
#include <string>
#include <fstream>

using namespace std;
size_t countWords(ifstream&);
size_t findSize(ifstream&);

/*
Given path to a file, find the file's size and count the words in it.
Example:
	> main.cpp
	> File contains 183 words, and size of 1634 bytes.
*/
int main()
{
	string path = "";
	cin >> path;
	ifstream file;
	file.open(path, ifstream::in);
	size_t words = countWords(file);
	size_t fileSize = findSize(file);
	cout << "File contains " << words << " words, and size of " << fileSize << " bytes" << endl;
	return 0;
}

size_t countWords(ifstream &in)
{
	int count = 0;
	for (string word; in >> word; count++); 
	in.clear();
	in.seekg(0, ios::beg);
	return count;
}

size_t findSize(ifstream &file)
{
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.close();
	return size;
}