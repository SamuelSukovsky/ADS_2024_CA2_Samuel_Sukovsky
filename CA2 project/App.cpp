#include "TreeMap.h"
#include "OutputVector.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void stageTwo(string filename);

int main()
{
	int run = 1;
	switch (run)
	{
	case 1:
	{
		string filename = "data.txt";
		stageTwo(filename);
	}
	}
	return 0;
}

void stageTwo(string filename)
{
	ifstream fileStream(filename);
	TreeMap<char, OutputVector<string>> map;
	string line;
	string word;

	while (getline(fileStream, line))
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] < 48 || line[i] > 58 && line[i] < 65 || line[i] > 90 && line[i] < 97 || line[i] > 122)
				line[i] = ' ';
		}
		stringstream sstream(line);
		while (sstream >> word)
		{
			word[0] = tolower(word[0]);
			if (map.containsKey(word[0]))
			{
				OutputVector<string>& wordList = map.get(word[0]);
				if (!wordList.contains(word))
					wordList.push_back(word);
			}
			else
			{
				OutputVector<string> wordList;
				wordList.push_back(word);
				map.put(word[0], wordList);
			}
		}
	}

	bool running = true;
	string answer;
	while (running)
	{
		cout << "Enter:\n1 for a list of letters\n2 for a list of words for select letter\n3 to print the entire map\n0 to exit:" << endl;
		cin >> answer;
		switch (answer[0])
		{
		case '1':
		{
			map.keySet().printInOrder();
			break;
		}
		case '2':
		{
			cout << "Enter a letter:" << endl;
			cin >> answer;
			OutputVector<string> vec;
			vec = map.get(answer[0]);
			cout << answer[0] << ": " << vec << endl;
			break;
		}
		case '3':
		{
			map.printInOrder();
			break;
		}
		case '0':
		{
			cout << "Exiting application." << endl;
			running = false;
			break;
		}
		default:
		{
			cout << "Invalid input." << endl;
			break;
		}
		}
	}
}