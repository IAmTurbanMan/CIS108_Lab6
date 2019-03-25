#pragma once
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

void programLoad(string fileName);

void addSong();

void saveSong(metadata::Song& s, string fileName);

void listSong();

void menu();
