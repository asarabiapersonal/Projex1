#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> getWords(string fileName);
vector<string> getCommonWords(vector<string> firstFile, vector<string> secondFile);
bool wAlreadyStored(string wToCheck, vector<string> wCollection);
void printVectorString(vector<string> toPrint);


int main()
{
	vector<string> wAllFirst = getWords("file1.txt");
	vector<string> wAllSecond = getWords("file2.txt");

	vector<string> wCombined = getCommonWords(wAllFirst, wAllFirst);
	printVectorString(wCombined);

	system("PAUSE");
	return 0;
}

vector<string> getWords(string fileName){
	string line;
	string token;
	size_t pos = 0;
	string delimiter = " ";
	vector<string> allTokens;
	fstream textFile("fileName");
	if (textFile.is_open()){
		while (getline(textFile, line)){
			while ((pos = line.find(delimiter)) != string::npos){
				token = line.substr(0, pos);
				allTokens.push_back(token);
				line.erase(0, pos + delimiter.length());
			}
		}
	}
	else{
		cout << "\nError Opening file.";
	}
	return allTokens;
}

vector<string> getCommonWords(vector<string> firstFile, vector<string> secondFile){
	string targetWord;
	vector<string> wCollection;
	for (int fNum = 0; fNum < firstFile.size(); fNum++){
		targetWord = firstFile[0];
		for (int sNum = 0; sNum < secondFile.size(); sNum++){
			if (targetWord == secondFile[sNum] && wAlreadyStored(targetWord, wCollection) == false){
				wCollection.push_back(targetWord);
			}
		}
	}
	return wCollection;
}

bool wAlreadyStored(string wToCheck, vector<string> wCollection){
	for (int wNum = 0; wNum < wCollection.size(); wNum++){
		if (wToCheck == wCollection[wNum]){
			return true;
		}
	}
	return false;
}

void printVectorString(vector<string> toPrint){
	for (int w = 0; w < toPrint.size(); w++){
		cout << toPrint[w] << endl;
	}
	return;
}
