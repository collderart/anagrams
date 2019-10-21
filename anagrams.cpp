#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<stdio.h>
#include <algorithm>
#include <Windows.h>
#include <time.h>
#include<ctime>

using namespace std;

void findAnagrams(const char * filename) {
	
	string buffer1, buffer2; //strings for comparison
	ifstream fileRead(filename);
	ofstream fileWrite;
	int index = 0;
	
	vector <string> wordsArr;
	vector<string> wordsForSave;
	while (getline(fileRead, buffer1))
	{
		if (buffer1.size() > 1)
		{
			wordsArr.push_back(buffer1);
		}
	}
	fileRead.clear();
	fileRead.seekg(0, ios::beg);
	cout << wordsArr.size()<< " words\n";
	sort(wordsArr.begin(), wordsArr.end());//sorting list of words
	fileWrite.open("result.txt", ios::app);
	for (size_t i = 0; i < wordsArr.size(); i++)
	{
		buffer1 = wordsArr[i];//берется слово в буфер по индексу из словаря	
		for (size_t j = 1+i; j < wordsArr.size(); j++)
		{
			buffer2 = wordsArr[j];
			if (wordsArr[i].size() == wordsArr[j].size()) {
				if (wordsArr[i] != wordsArr[j])
				{
					sort(buffer1.begin(), buffer1.end());//буквы сортируются 
					sort(buffer2.begin(), buffer2.end());
					if (buffer1 == buffer2) {
						index++;//счетчик для нумерации анаграмм
						//sIndex = to_string(index);//перевод инт в стринг
						//wordsForSave.push_back(sIndex);
						//wordsForSave.push_back(wordsArr[i]);
						//wordsForSave.push_back(wordsArr[j]);
						//wordsForSave.push_back("\n");
						
						fileWrite << index << endl 
							<< wordsArr[i] << endl
							<< wordsArr[j] << endl << endl;
					}
				}				
			}
		}
	}
	fileWrite.close();
}



int main() {
	clock_t time;

	time = clock();
	findAnagrams("anagrams.txt");
	time = clock() - time;
	cout << endl<<"runtime "<<time/1000.0;

	return 0;
}
