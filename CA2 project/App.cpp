#include "TreeMap.h"
#include "OutputVector.h"
#include "GameEntry.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int stageTwo(string filename);
int stageFour(string filename);
TreeMap<string, OutputVector<GameEntry*>>* generateKeyMap(int column, OutputVector<GameEntry*>* entriesVec);

int main()
{
	int run = 2;
	int ret = -1;
	switch (run)
	{
		case 1:
		{
			string filename = "data.txt";
			ret = stageTwo(filename);
			break;
		}
		case 2:
		{
			string filename = "games_catalogue.csv";
			ret = stageFour(filename);
		}
	}
	return ret;
}

int stageTwo(string filename)
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

	return 0;
}

int stageFour(string filename)
{
	ifstream fileStream(filename);
	string line;
	string word;
	OutputVector<GameEntry*> entriesVec;
	OutputVector<GameEntry*>* entriesPtr = &entriesVec;

	string columnNames[6];
	TreeMap<string, OutputVector<GameEntry*>>* keyMaps[6] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

	getline(fileStream, line);
	stringstream sstream(line);
	int i = 0;
	while (getline(sstream, word, ','))
	{
		columnNames[i] = word;
		i++;
	}

	while (getline(fileStream, line))
	{
		stringstream sstream(line);
		string data[6];
		i = 0;
		while (getline(sstream, word, ','))
		{
			data[i] = word;
			i++;
		}

		entriesVec.push_back(new GameEntry(data[0], data[1], data[2], stod(data[3]), data[4], stof(data[5])));
	}

	bool running = true;
	string answer;
	while (running)
	{
		cout << "Enter:\n1 to display list of column names and indexes\n2 to display all keys for selected column and the number of their instances\n3 to display all games with the select value in selected column\n0 to exit:" << endl;
		cin >> answer;
		switch (answer[0])
		{
		case '1':
		{
			for (int i = 0; i < 6; i++)
			{
				if (i > 0)
					cout << ", ";
				cout << i << ": " << columnNames[i];
			}
			cout << endl;
			break;
		}
		case '2':
		{
			cout << "Enter collumn index:" << endl;
			cin >> answer;
			int ans = answer[0] - '0';
			if (ans > -1 && ans < 6)
			{
				if (keyMaps[ans] == nullptr)
				{
					keyMaps[ans] = generateKeyMap(0, entriesPtr);
				}

				keyMaps[ans]->printInOrderPlusCount();
			}
			else
			{
				cout << "Invalid input." << endl;
			}
			break;
		}
		case '3':
		{
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

	return 0;
}


TreeMap<string, OutputVector<GameEntry*>>* generateKeyMap(int column, OutputVector<GameEntry*>* entriesVec)
{
	TreeMap<string, OutputVector<GameEntry*>>* ret = new TreeMap<string, OutputVector<GameEntry*>>;
	string key;
	for (int i = 0; i < entriesVec->size(); i++)
	{
		switch (column)
		{
			case 0:
			{
				key = entriesVec->at(i)->getGameTitle();
				break;
			}
			case 1:
			{
				key = entriesVec->at(i)->getPlatform();
				break;
			}
			case 2:
			{
				key = entriesVec->at(i)->getReleaseDate();
				break;
			}
			case 3:
			{
				key = to_string(entriesVec->at(i)->getPrice());
				break;
			}
			case 4:
			{
				key = entriesVec->at(i)->getGenre();
				break;
			}
			case 5:
			{
				key = to_string(entriesVec->at(i)->getRating());
				break;
			}
			default:
			{
				cout << column;
				return nullptr;
			}
		}

		if (ret->containsKey(key))
		{
			OutputVector<GameEntry*>& gameList = ret->get(key);
			gameList.push_back(entriesVec->at(i));
		}
		else
		{
			OutputVector<GameEntry*> gameList;
			gameList.push_back(entriesVec->at(i));
			ret->put(key, gameList);
		}
	}

	return ret;
}