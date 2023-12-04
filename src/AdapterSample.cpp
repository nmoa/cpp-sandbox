#include <iostream>
#include <string>

// Existing class that we want to adapt
class LegacyRectangle {
public:
	LegacyRectangle(int x1, int y1, int x2, int y2) {
		m_x1 = x1;
		m_y1 = y1;
		m_x2 = x2;
		m_y2 = y2;
		std::cout << "LegacyRectangle: create. (" << x1 << "," << y1 << ") => (" << x2 << "," << y2 << ")" << std::endl;
	}

	void oldDraw() {
		std::cout << "LegacyRectangle: oldDraw. (" << m_x1 << "," << m_y1 << ") => (" << m_x2 << "," << m_y2 << ")" << std::endl;
	}

private:
	int m_x1, m_y1, m_x2, m_y2;
};

// New interface that our client expects
class Rectangle {
public:
	Rectangle(int x, int y, int width, int height) {
		m_x      = x;
		m_y      = y;
		m_width  = width;
		m_height = height;
		std::cout << "Rectangle: create. (" << x << "," << y << ") => (" << width << "," << height << ")" << std::endl;
	}

	void draw() {
		std::cout << "Rectangle: draw. (" << m_x << "," << m_y << ") => (" << m_width << "," << m_height << ")" << std::endl;
	}

private:
	int m_x, m_y, m_width, m_height;
};

// Adapter class that adapts the LegacyRectangle to the new Rectangle interface
class RectangleAdapter : public Rectangle {
public:
	RectangleAdapter(int x1, int y1, int x2, int y2) : Rectangle(x1, y1, x2 - x1, y2 - y1), m_legacyRectangle(x1, y1, x2, y2) {
		std::cout << "RectangleAdapter: create." << std::endl;
	}

	void draw() {
		std::cout << "RectangleAdapter: draw." << std::endl;
		m_legacyRectangle.oldDraw();
	}

private:
	LegacyRectangle m_legacyRectangle;
};

// Client code that uses the new Rectangle interface
void draw(Rectangle& r) {
	r.draw();
}

int main() {
	// Create a Rectangle object using the new interface
	Rectangle rect(10, 20, 30, 40);
	draw(rect);

	// Create a LegacyRectangle object and adapt it to the new interface using the adapter
	RectangleAdapter adaptedRect(10, 20, 30, 40);
	draw(adaptedRect);

	return 0;
}
