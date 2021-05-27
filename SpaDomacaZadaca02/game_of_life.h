#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 100;
	static const unsigned int REDAKA = 100;
	const int min = 1;
	const int max = 100;

	

	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	int koliko_susjeda(int i, int j);
	

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj(std::vector<std::vector<sf::RectangleShape>>& grid);
	void set_generacija(int i, int j);
	unsigned get_generacija_x();
	unsigned get_generacija_y();

};

#endif
