#include "TreeMap.h"
#include "OutputVector.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string filename = "data.txt";
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
		cout << "\nEnter:\n1 for a list of letters\n2 for a list of words for select letter\n3 to print the entire map\nother to exit:" << endl;
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
				OutputVector<string> vec = map.get(answer[0]);
				cout << answer[0] << ": " << vec << endl;
				break;
			}
			case '3':
			{
				map.printInOrder();
				break;
			}
			default:
			{
				cout << "Exiting application." << endl;
				running = false;
			}
		}
	}

	return 0;
}