// BrickBreaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow app(sf::VideoMode(520, 450), "BrickBreaker!");
	app.setFramerateLimit(60);

	//textures
	sf::Texture block_tex, background_tex, ball_tex, paddle_tex;
	
	block_tex.loadFromFile("Data/block01.png");
	background_tex.loadFromFile("Data/background.png");
	ball_tex.loadFromFile("Data/ball.png");
	paddle_tex.loadFromFile("Data/paddle.png");

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(520, 450));
	background.setPosition(0, 0);
	background.setTexture(&background_tex);

	sf::RectangleShape pad;
	pad.setSize(sf::Vector2f(90, 9));
	pad.setPosition(215, 440);
	pad.setTexture(&paddle_tex);

	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(12, 12));
	ball.setPosition(254, 300);
	ball.setTexture(&ball_tex);

	//setting blocks

	sf::Sprite blocks[1000];

	int n = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			blocks[n].setTexture(block_tex);
			blocks[n].setPosition(i * 43, j * 20);
			n++;
		}
	}

	//game loop
	while (app.isOpen()) {
		sf::Event e;
		while (app.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				app.close();
			}
		}
		app.clear();
		//drawing
		app.draw(background);
		app.draw(pad);
		app.draw(ball);
		for (int i = 0; i < n; i++) {
			app.draw(blocks[i]);
		}

		app.display();
	}



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
