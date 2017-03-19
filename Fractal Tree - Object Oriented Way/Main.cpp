#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "Branch.h"
using namespace std;
using namespace sf;

int width = 800;
int height = 800;



int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Fractal Tree - Recursive");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(Color(51, 51, 51));

	int len = 150;
	Vector2f s, e;
	s = Vector2f(width / 2, height);
	e = Vector2f(width / 2, height - len);
	vector<Branch> tree;
	Branch root(s, e);
	tree.push_back(root);

	Branch newBranch = root.branch();
	tree.push_back(newBranch);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		/////////////////////////

		for (int i = 0; i < tree.size(); i++)
		{
			tree[i].show(window);
		}
		window.display();
	}

	return 0;
}