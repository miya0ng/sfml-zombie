#pragma once

class HitBox
{
public:
	HitBox();

	sf::RectangleShape rect;

	void UpdateTransform(const sf::Transformable& tr, const sf::FloatRect& localBounds);
	//transformalble < ���� �׸��ⰴü�� ���� �����Լ� �����ִ� Ŭ����

	void Draw(sf::RenderWindow& window);
};

