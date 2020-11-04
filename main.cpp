#include "Vector.h"
#include <iostream>


 struct Point {
	int x;
	int y;
	int z;
};

void printPoint(const Point& point) {
	std::cout << "(" << point.x << ", " << point.y << ", " << point.z << "); ";
}
int main() {
	size_t n = 10;
	int r = 5;
	vector<int>* a = new vector<int>();
	vector<int> b;
	b.size();
	Point dot;
	dot.x = 0;
	dot.y = 5;
	dot.z = 10;
	Point insDot;
	insDot.x = 256;
	insDot.y = 256;
	insDot.z = 256;
	vector<Point> c(10, dot);
	for (int i = 0; i < c.size(); i++) {

		printPoint(c[i]);
	}
	std::cout << '\n';
	return 0;
}