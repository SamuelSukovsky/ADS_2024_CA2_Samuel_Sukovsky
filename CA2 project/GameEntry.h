#pragma once
#include <iostream>

using namespace std;
class GameEntry
{
	string game_title;
	string platform;
	string release_date;
	double price;
	string genre;
	float rating;
public:
	GameEntry();
	GameEntry(
		string game_title, 
		string platform, 
		string release_date, 
		double price,
		string genre,
		float rating);

	string getGameTitle();
	string getPlatform();
	string getReleaseDate();
	double getPrice();
	string getGenre();
	float getRating();

	friend ostream& operator<<(ostream& os, GameEntry& game)
	{
		os << game.getGameTitle() << ", " << game.getPlatform() << ", ";
		os << game.getReleaseDate() << ", €" << game.getPrice() << ", ";
		os << game.getGenre() << ", " << game.getRating();
		return os;
	}
};

GameEntry::GameEntry()
{
	this->game_title = "game_title";
	this->platform = "platform";
	this->release_date = "00/00/0000";
	this->price = 0;
	this->genre = "genre";
	this->rating = 0;
}

GameEntry::GameEntry(
	string game_title,
	string platform,
	string release_date,
	double price,
	string genre,
	float rating)
{
	this->game_title = game_title;
	this->platform = platform;
	this->release_date = release_date;
	this->price = price;
	this->genre = genre;
	this->rating = rating;
}

string GameEntry::getGameTitle()
{
	return game_title;
}
string GameEntry::getPlatform()
{
	return platform;
}
string GameEntry::getReleaseDate()
{
	return release_date;
}
double GameEntry::getPrice()
{
	return price;
}
string GameEntry::getGenre()
{
	return genre;
}
float GameEntry::getRating()
{
	return rating;
}