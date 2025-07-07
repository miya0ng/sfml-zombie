#include "stdafx.h"
#include "zombie.h"
#include "Player.h"

Zombie::Zombie(const std::string& name)
	: GameObject(name)
{
}

void Zombie::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	body.setPosition(pos);
}

void Zombie::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	body.setRotation(rot);
}

void Zombie::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	body.setScale(s);
}

void Zombie::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	body.setOrigin(o);
}

void Zombie::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(body, preset);
	}
}

void Zombie::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	SetType(type);//기본타입호출해놓기..
}

void Zombie::Release()
{
}

void Zombie::Reset()
{
	player = (Player*)SCENE_MGR.GetCurrentScene()->FindGameObject("Player");
	body.setTexture(TEXTURE_MGR.Get(texId));
	SetOrigin(Origins::MC);
	SetPosition({ 0.f,0.f });
	SetRotation(0.f);
	SetScale({ 1.f, 1.f
		});
}

void Zombie::Update(float dt)
{
	if (Utils::Distance(player->GetPosition(), GetPosition()) <= 5.f)
	{
		direction = { 0.f,0.f };
	}
	else
	{
		direction = Utils::GetNormal(player->GetPosition() - GetPosition());
		SetRotation(Utils::Angle(direction));
		SetPosition(GetPosition() + direction * speed * dt);
	}
}

void Zombie::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Zombie::SetType(Types type)
{
	this->type = type;
	switch (this->type)
	{
	case Types::Bloater:
		texId = "graphics/bloater.png";
		maxHp = 50000000000;
		speed = 20.f;
		damage = 100.f;
		attackIntervale = 1.f;

		break;
	case Types::Chase:
		texId = "graphics/chaser.png";
		maxHp = 500;
		speed = 10.f;
		damage = 100.f;
		attackIntervale = 1.f;

		break;
	case Types::Crawler:
		texId = "graphics/crawler.png";
		maxHp = 50;
		speed = 50.f;
		damage = 10.f;
		attackIntervale = 1.f;

		break;

	}

}
