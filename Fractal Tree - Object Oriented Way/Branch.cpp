
#include "Branch.h"

Branch::Branch(Vector2f begin_, Vector2f end_)
{
	begin = begin_;
	end = end_;
}


Branch::~Branch()
{
}

void Branch::show(RenderWindow &target_) {
	Vertex line[] = {
		Vertex(begin),
		Vertex(end)
	};
	target_.draw(line, 2, sf::Lines);
}

Branch Branch::branch() {

    
	Vector2f dir = this->end - this->begin;
	cout << "D X: " << dir.x << " D Y: " << dir.y << "\n";

	int angle = 9;
	/*
	Transform rot;
	rot.rotate(angle, this->begin.x, this->begin.y);
	Vector2f positionARL = rot.transformPoint(dir);
	dir = positionARL;*/
	Vector2f newEnd = this->end+dir;
	cout << "E X: " << this->end.x << " E Y: " << this->end.y << "\n";
	cout << "D X: " << dir.x << " D Y: " << dir.y << "\n";
	cout << "NE X: " << newEnd.x << " NE Y: " << newEnd.y << "\n";
	Branch right(this->end, newEnd);
	return right;
}