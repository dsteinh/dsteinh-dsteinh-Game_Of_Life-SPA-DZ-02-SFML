#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	
	float gridSizeF = 10.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
	float dt = 0.f;
	sf::Clock dtClock;
	
	sf::Vector2u mousePosGrid;
	sf::Vector2f mousePosView;
	std::string gridPosX, gridPosY;
	

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Hello, SFML world!");
	window.setFramerateLimit(120);

	sf::View view;
	view.setSize(1920.f, 1080.f);
	view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
	float viewSpeed = 200.f;

	sf::RectangleShape shape(sf::Vector2f(gridSizeF, gridSizeF));

	const int gridTileSize = 100;
	std::vector<std::vector<sf::RectangleShape>> grid;
	grid.resize(gridTileSize, std::vector<sf::RectangleShape>());

	for (int x = 0; x < gridTileSize; x++)
	{
		grid[x].resize(gridTileSize, sf::RectangleShape());
		for (int y = 0; y < gridTileSize; y++)
		{
			grid[x][y].setSize(sf::Vector2f(gridSizeF, gridSizeF));
			grid[x][y].setFillColor(sf::Color::Transparent);
			//grid[x][y].setOutlineThickness(0.5f);
			//grid[x][y].setOutlineColor(sf::Color::White);
			grid[x][y].setPosition(x * gridSizeF, y * gridSizeF);
		}
	}
	while (window.isOpen())
	{
		dt = dtClock.restart().asSeconds();

		mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		if (mousePosView.x >= 0.f)
		{
		mousePosGrid.x = mousePosView.x / gridSizeU;
		}

		if (mousePosView.y >= 0.f)
		{
		mousePosGrid.y = mousePosView.y / gridSizeU;	
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		

		for (int x = 0; x < gridTileSize; x++)
		{
			for (int y = 0; y < gridTileSize; y++)
			{
				window.draw(grid[x][y]);
			
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			
			grid[mousePosGrid.x][mousePosGrid.y].setFillColor(sf::Color::White);
			
		}
		
		std::cout << "( "<< mousePosGrid.x << ", " << mousePosGrid.y <<" )" << std::endl;

		
		window.display();
	}

	return 0;
}