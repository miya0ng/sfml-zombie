#pragma once

class HitBox
{
public:
	HitBox();

	sf::RectangleShape rect;

	void UpdateTransform(const sf::Transformable& tr, const sf::FloatRect& localBounds);
	//transformalble < 여러 그리기객체를 위한 가상함수 갖고있는 클래스

	void Draw(sf::RenderWindow& window);
};

