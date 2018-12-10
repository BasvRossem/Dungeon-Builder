#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "TileMap.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void writeToFile(sf::String name, std::vector<int> level) {
	std::ofstream myfile;
	std::string stdName = name;
	myfile.open(stdName);
	std::cout << level.size() << std::endl;
	for (int & character : level) {
		myfile << character << " ";
	}
	myfile.close();
	std::cout << "Saved" << std::endl;
}

void saveLevel(std::vector<int> level) {
	sf::RenderWindow saveWindow(sf::VideoMode(512, 256), "Tilemap");
	sf::Font font;
	if (!font.loadFromFile("PIXEARG_.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	sf::Text saveFileText("Save file name:", font, 24);
	saveFileText.setPosition(sf::Vector2f(8, 8));
	saveFileText.setFillColor(sf::Color::White);
	
	sf::Text saveFileNameText("", font, 24);
	saveFileNameText.setPosition(sf::Vector2f(8, 40));
	saveFileNameText.setFillColor(sf::Color::White);

	while (saveWindow.isOpen())
	{
		// handle events
		sf::Event event;
		while (saveWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				saveWindow.close();

			if (event.type == sf::Event::KeyPressed){
				sf::String name = saveFileNameText.getString();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { saveFileNameText.setString(name + "a"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { saveFileNameText.setString(name + "b"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { saveFileNameText.setString(name + "c"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { saveFileNameText.setString(name + "d"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { saveFileNameText.setString(name + "e"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { saveFileNameText.setString(name + "f"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { saveFileNameText.setString(name + "g"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { saveFileNameText.setString(name + "h"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { saveFileNameText.setString(name + "i"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { saveFileNameText.setString(name + "j"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { saveFileNameText.setString(name + "k"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { saveFileNameText.setString(name + "l"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { saveFileNameText.setString(name + "m"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) { saveFileNameText.setString(name + "n"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) { saveFileNameText.setString(name + "o"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) { saveFileNameText.setString(name + "p"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { saveFileNameText.setString(name + "q"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { saveFileNameText.setString(name + "r"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { saveFileNameText.setString(name + "s"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) { saveFileNameText.setString(name + "t"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) { saveFileNameText.setString(name + "u"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { saveFileNameText.setString(name + "v"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { saveFileNameText.setString(name + "w"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { saveFileNameText.setString(name + "x"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) { saveFileNameText.setString(name + "y"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { saveFileNameText.setString(name + "z"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { 
					int lastPos = name.getSize();
					name.erase(lastPos -1, 2);
					saveFileNameText.setString(name); 
					std::string newName = saveFileNameText.getString();
					std::cout << newName << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { 
					writeToFile(saveFileNameText.getString() + ".txt", level); 
					saveWindow.close();
				}
			}
		}
		
		
		saveWindow.clear();
		saveWindow.draw(saveFileText);
		saveWindow.draw(saveFileNameText);
		saveWindow.display();
	}
	//type in File name
	//Make said file
	//save level to file
	//saveFile.close()
}

void readFromFile(std::string name, std::vector<int> & level) {
	std::ifstream myfile(name);

	level = {};
	char c;
	while (myfile.get(c)) {
		if (c != ' ') {
			level.push_back(int(c) - 48);
		}
	}
}

void loadLevel(std::vector<int> & level) {
	sf::RenderWindow loadWindow(sf::VideoMode(512, 256), "Tilemap");
	sf::Font font;
	if (!font.loadFromFile("PIXEARG_.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	sf::Text loadFileText("File name:", font, 24);
	loadFileText.setPosition(sf::Vector2f(8, 8));
	loadFileText.setFillColor(sf::Color::White);

	sf::Text loadFileNameText("", font, 24);
	loadFileNameText.setPosition(sf::Vector2f(8, 40));
	loadFileNameText.setFillColor(sf::Color::White);

	while (loadWindow.isOpen())
	{
		// handle events
		sf::Event event;
		while (loadWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				loadWindow.close();

			if (event.type == sf::Event::KeyPressed) {
				sf::String name = loadFileNameText.getString();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { loadFileNameText.setString(name + "a"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { loadFileNameText.setString(name + "b"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { loadFileNameText.setString(name + "c"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { loadFileNameText.setString(name + "d"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { loadFileNameText.setString(name + "e"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { loadFileNameText.setString(name + "f"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { loadFileNameText.setString(name + "g"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { loadFileNameText.setString(name + "h"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { loadFileNameText.setString(name + "i"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { loadFileNameText.setString(name + "j"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { loadFileNameText.setString(name + "k"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { loadFileNameText.setString(name + "l"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { loadFileNameText.setString(name + "m"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) { loadFileNameText.setString(name + "n"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) { loadFileNameText.setString(name + "o"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) { loadFileNameText.setString(name + "p"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { loadFileNameText.setString(name + "q"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { loadFileNameText.setString(name + "r"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { loadFileNameText.setString(name + "s"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) { loadFileNameText.setString(name + "t"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) { loadFileNameText.setString(name + "u"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { loadFileNameText.setString(name + "v"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { loadFileNameText.setString(name + "w"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { loadFileNameText.setString(name + "x"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) { loadFileNameText.setString(name + "y"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { loadFileNameText.setString(name + "z"); }
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					int lastPos = name.getSize();
					name.erase(lastPos - 1, 2);
					loadFileNameText.setString(name);
					std::string newName = loadFileNameText.getString();
					std::cout << newName << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					sf::String newName = loadFileNameText.getString() + ".txt";
					std::string newerName = newName;
					std::cout << newerName << std::endl;
					readFromFile(newerName, level);
					loadWindow.close();
				}
			}
		}


		loadWindow.clear();
		loadWindow.draw(loadFileText);
		loadWindow.draw(loadFileNameText);
		loadWindow.display();
	}
}

int main(){
	int windowWidth = 512;
	int windowHeight = 544;
	int lastTilePos = 0;
	auto leftMouseButton = sf::Mouse::Left;
	auto rightMouseButton = sf::Mouse::Right;


	// create the window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tilemap");

	// define the level with an array of tile indices
	std::vector<int> level = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 16)) {
		return -1;
	}
		
	//
	sf::Font font;
	if (!font.loadFromFile("PIXEARG_.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	sf::Text loadText("Load", font, 24);
	loadText.setPosition(sf::Vector2f(128,516));
	loadText.setFillColor(sf::Color::White);

	sf::Text saveText("Save", font, 24);
	saveText.setPosition(sf::Vector2f(5, 516));
	saveText.setFillColor(sf::Color::White);

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(leftMouseButton) || sf::Mouse::isButtonPressed(rightMouseButton)) {
			sf::Vector2i position = sf::Mouse::getPosition(window);
			if (position.x >= 0 && position.x <= windowWidth) {
				if (position.y >= 0 && position.y <= 512) {
					int tileY = (position.y / 32) * 16;
					int tileX = (position.x / 32);
					int tilePosition = tileY + tileX;

					if (tilePosition != lastTilePos) {
						std::cout << tilePosition << ", " << lastTilePos << std::endl;
						lastTilePos = tilePosition;
						std::cout << lastTilePos << std::endl;
						if (sf::Mouse::isButtonPressed(leftMouseButton)) {
							level[tilePosition] = 1;
						}
						else if (sf::Mouse::isButtonPressed(rightMouseButton)) {
							level[tilePosition] = 0;
						}
						if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 16))
							std::cout << "Map loading went wrong" << std::endl;
					}
				}
				else if (position.y >= 512 && position.y < windowHeight) {
					sf::Vector2<float> mousePos = sf::Vector2f(position);
					if (saveText.getGlobalBounds().contains(mousePos)) {
						saveLevel(level);
					}
					else if (loadText.getGlobalBounds().contains(mousePos)) {
						loadLevel(level);
						if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 16)) {
							return -1;
						}
					}
				}

			}
			
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.draw(loadText);
		window.draw(saveText);
		window.display();
	}

	return 0;
}