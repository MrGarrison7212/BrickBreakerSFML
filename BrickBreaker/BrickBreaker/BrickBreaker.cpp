// BrickBreaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow app(sf::VideoMode(520, 450), "BrickBreaker!");
	app.setFramerateLimit(60);


	//states
	bool left = false;
	bool right = false;
	//variables
	int xVelocityPad = 0;
	int xVelocityBall = -2;
	int yVelocityBall = -2;

	//sound
	sf::SoundBuffer pad_hit_buf;
	sf::SoundBuffer block_hit_buf;

	pad_hit_buf.loadFromFile("Data/padhit.wav");
	block_hit_buf.loadFromFile("Data/blockhit.wav");


	sf::Sound pad_hit;
	sf::Sound block_hit;

	pad_hit.setBuffer(pad_hit_buf);
	block_hit.setBuffer(block_hit_buf);


	//textures
	sf::Texture block_tex, background_tex, ball_tex, paddle_tex;
	
	block_tex.loadFromFile("Data/block01.png");
	background_tex.loadFromFile("Data/background.png");
	ball_tex.loadFromFile("Data/ball.png");
	paddle_tex.loadFromFile("Data/pad.png");

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
			//key pressed
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Left) {
				left = true;
			}

			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Right) {
				right = true;
			}
			//key released
			if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Left) {
				left = false;
			}

			if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Right) {
				right = false;
			}
		}
		//LOGIC
		//pad
		if (left == true) {
			xVelocityPad = -5;
		}

		if (right == true) {
			xVelocityPad = 5;
		}

		if (left == true && right == true) {
			xVelocityPad = 0;
		}

		if (left == false && right == false) {
			xVelocityPad = 0;
		}


		pad.move(xVelocityPad, 0);

		//pad out of bounds
		if (pad.getPosition().x < 0) {
			pad.setPosition(0, 440);
		}

		if (pad.getPosition().x > 430) {
			pad.setPosition(430, 440);
		}

		//ball
		if (ball.getPosition().x < 0) {
			xVelocityBall = -xVelocityBall;
		}

		if (ball.getPosition().x > 502) {
			xVelocityBall = -xVelocityBall;
		}

		if (ball.getPosition().y < 0) {
			yVelocityBall = -yVelocityBall;
		}

		ball.move(0, yVelocityBall);
		//collision with blocks
		for (int i = 0; i < n; i++) {
			if (ball.getGlobalBounds().intersects(blocks[i].getGlobalBounds()) == true) {
				blocks[i].setPosition(-100, 0);
				yVelocityBall = -yVelocityBall;
				block_hit.play();
			}
		}

		ball.move(xVelocityBall, 0);
		for (int i = 0; i < n; i++) {
			if (ball.getGlobalBounds().intersects(blocks[i].getGlobalBounds()) == true) {
				blocks[i].setPosition(-100, 0);
				xVelocityBall = -xVelocityBall;
				block_hit.play();
			}
		}

		//collision with pad
		if (ball.getGlobalBounds().intersects(pad.getGlobalBounds()) == true) {
			yVelocityBall = -yVelocityBall;
			pad_hit.play();
		}


		
		//rendering
		app.clear();
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
