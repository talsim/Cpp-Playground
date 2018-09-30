#include <iostream>
#include <string>
#include <fstream>
using namespace std;
size_t countWords(ifstream&);
int findSize(ifstream&);

int main()
{
	string path = "";
	cin >> path;
	ifstream file;
	file.open(path, ifstream::in);
	size_t words = countWords(file);
	cout << "File contains " << words << " words";
	int fileSize = findSize(file);
	cout << ", and size of " << fileSize << " bytes" << endl;
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

int findSize(ifstream &file)
{
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.close();
	return size;
}