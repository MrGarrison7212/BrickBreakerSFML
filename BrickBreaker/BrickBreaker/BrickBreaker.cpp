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
	sf::Texture block, background, ball, paddle;
	
	block.loadFromFile("Data/block01.png");
	background.loadFromFile("Data/background.png");
	ball.loadFromFile("Data/ball.png");
	paddle.loadFromFile("Data/paddle.png");

	sf::Sprite sBackground(background), sBall(ball), sPaddle(paddle);

	sPaddle.setPosition(300, 440);
	sBall.setPosition(300, 300);

	//setting blocks

	sf::Sprite blocks[1000];

	int n = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			blocks[n].setTexture(block);
			blocks[n].setPosition(i * 43, j * 20);
			n++;
		}
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
