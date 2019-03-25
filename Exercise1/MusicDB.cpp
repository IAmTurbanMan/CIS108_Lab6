#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "MusicDB.h"
#include "Song.h"

using namespace std;

metadata::Song aSong;

vector <metadata::Song> mySongs;

void programLoad(string fileName)
{
	metadata::Song aSong;
	ifstream musicDatabase;
	mySongs.clear();
	char ch;
	
	musicDatabase.open(fileName, ios::in | ios::binary);
	while (musicDatabase.is_open() && musicDatabase.peek() != EOF)
	{
		musicDatabase.read((char*)& aSong, sizeof(aSong));
		mySongs.push_back(aSong);
	}
	musicDatabase.close();
}

void addSong()											//function to add a song to the database
{
	cout << "\n" << "Enter song title: ";
	cin.getline(aSong.title, 64);						//input into the title of the aSong struct
	cout << "Enter artist: ";
	cin.getline(aSong.artist, 32);						//input into artist
	cout << "Enter album: ";
	cin.getline(aSong.album, 64);						//input into album
	cout << "Enter track number: ";
	cin >> aSong.track;									//input into track
	cout << "Enter release year: ";
	cin >> aSong.releaseYear;							//input into  release year
	cout << " Blues\n" << " Country\n" << " Electronic\n" << " Folk\n" << " Hip Hop\n" << " Jazz\n" << " Latin\n" << " Pop\n" << " Rock\n";
	cout << "Choose a genre: ";

	string genreString;
	
	while (true)
	{
		getline (cin, genreString);

		//a series of if statements to read a string and input the string into the genre field of the struct.
		//I hope this is how to do it
		//Look into converting string to lower case

		if (genreString == "Blues" || genreString == "blues")
		{
			aSong.genre = aSong.Blues;
			break;
		}

		else if (genreString == "Electronic" || genreString == "electronic")
		{
			aSong.genre = aSong.Electronic;
			break;
		}

		else if (genreString == "Country" || genreString == "country")
		{
			aSong.genre = aSong.Country;
			break;
		}

		else if (genreString == "Folk" || genreString == "folk")
		{
			aSong.genre = aSong.Folk;
			break;
		}

		else if (genreString == "Hip Hop" || genreString == "hip hop" || genreString == "Hip hop")
		{
			aSong.genre = aSong.HipHop;
			break;
		}

		else if (genreString == "Jazz" || genreString == "jazz")
		{
			aSong.genre = aSong.Jazz;
			break;
		}

		else if (genreString == "Latin" || genreString == "latin")
		{
			aSong.genre = aSong.Latin;
			break;
		}

		else if (genreString == "Pop" || genreString == "pop")
		{
			aSong.genre = aSong.Pop;
			break;
		}

		else if (genreString == "Rock" || genreString == "rock")
		{
			aSong.genre = aSong.Rock;
			break;
		}
	}

  	mySongs.push_back (aSong);
}

void saveSong(metadata::Song& aSong, string fileName)
{

	ofstream musicDatabase;
	musicDatabase.open(fileName, ios::out | ios::binary);
	auto vectorCount = mySongs.begin();
	while (vectorCount != mySongs.end())
	{
		metadata::Song aSong = *vectorCount;
		musicDatabase.write((char*)&aSong, sizeof(aSong));
		vectorCount++;
	}

	//ofstream outFile;

	//outFile.open(database, ios::out | ios::app);

	//for (int idx = 0; idx < mySongs.size(); idx++)
	//{
	//	outFile << "Title : " << mySongs[idx].title << "\n";
	//	outFile << "Artist: " << mySongs[idx].artist << "\n";
	//	outFile << "Album : " << mySongs[idx].album << "\n";
	//	outFile << "Track : " << mySongs[idx].track << "\n";
	//	outFile << "Year  : " << mySongs[idx].releaseYear << "\n";

	//	if (mySongs[idx].genre == 0)
	//	{
	//		outFile << "Genre : Blues\n";
	//	}

	//	if (mySongs[idx].genre == 1)
	//	{
	//		outFile << "Genre : Country\n";
	//	}

	//	if (mySongs[idx].genre == 2)
	//	{
	//		outFile << "Genre : Electronic\n";
	//	}

	//	if (mySongs[idx].genre == 3)
	//	{
	//		outFile << "Genre : Folk\n";
	//	}

	//	if (mySongs[idx].genre == 4)
	//	{
	//		outFile << "Genre : Hip Hop\n";
	//	}

	//	if (mySongs[idx].genre == 5)
	//	{
	//		outFile << "Genre : Jazz\n";
	//	}

	//	if (mySongs[idx].genre == 6)
	//	{
	//		outFile << "Genre : Latin\n";
	//	}

	//	if (mySongs[idx].genre == 7)
	//	{
	//		outFile << "Genre : Pop\n";
	//	}

	//	if (mySongs[idx].genre == 8)
	//	{
	//		outFile << "Genre : Rock\n";
	//	}
	//	outFile << "\n";
	//}
	//outFile.close();
}

void listSong()
{
	int vectorCount = 0;
	vector <metadata::Song>::iterator songCount;
	metadata::Song aSong;

	for (songCount = mySongs.begin(); songCount < mySongs.end(); songCount++)
	{
		aSong = *songCount;
		cout << "#" << vectorCount + 1 << "\n";
		cout << "Title : " << aSong.title << "\n";
		cout << "Artist: " << aSong.artist << "\n";
		cout << "Album : " << aSong.album << "\n";
		cout << "Track : " << aSong.track << "\n";
		cout << "Year  : " << aSong.releaseYear << "\n";
		if (aSong.genre == 0)
			cout << "Genre : Blues\n";
		if (aSong.genre == 1)
			cout << "Genre : Country\n";
		if (aSong.genre == 2)
			cout << "Genre : Electronic\n";
		if (aSong.genre == 3)
			cout << "Genre : Folk\n";
		if (aSong.genre == 4)
			cout << "Genre : Hip Hop\n";
		if (aSong.genre == 5)
			cout << "Genre : Jazz\n";
		if (aSong.genre == 6)
			cout << "Genre : Latin\n";
		if (aSong.genre == 7)
			cout << "Genre : Pop\n";
		if (aSong.genre == 8)
			cout << "Genre : Rock\n";
	//	cout << "Genre : " << aSong.genre << "\n";
		vectorCount++;
	}

	//ifstream inFile(database);
	//string line;
	//while (getline(inFile, line))
	//{
	//	cout << line << "\n";
	//}
}

void menu()
{
	cout << "add  : add a song to the database\n";
	cout << "list : list the songs in the database\n";
	cout << "save : save the songs to the database\n";
	cout << "menu : display this menu\n";
	cout << "x    : exit the program\n";
}