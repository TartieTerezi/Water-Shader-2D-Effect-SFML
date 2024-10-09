#include "character.h"
#include "Utils.h"

Water::Water(Data* _data)
{
	this->m_instanceData = _data;

	this->m_poid = (rand() % POID_MAX) + 5;
	this->m_circle = sf::CircleShape(this->m_poid);

	this->m_circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

	this->m_pos = sf::Vector2f(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGTH);
	this->m_circle.setPosition(this->m_pos);

	this->m_vitesse = (rand() % 140 + 60);
}

Water::~Water()
{
}

float Water::GetPoid()
{
	return this->m_poid;
}

sf::Vector2f Water::GetPos()
{
	return this->m_pos;
}



void Water::Update()
{
	sf::Vector2f delta = { 0,0 };

	delta.y -= m_vitesse;

	this->m_pos -= this->m_instanceData->dt * delta;

	if (this->m_pos.y > SCREEN_HEIGTH + 20)
	{
		this->m_pos.y = -20;
		this->m_pos.x = rand() % SCREEN_WIDTH;
	}

	this->m_circle.setPosition(this->m_pos);
}

void Water::Draw()
{
	this->m_instanceData->RT.draw(this->m_circle);
}

sf::Color Water::GetColor()
{
	return this->m_circle.getFillColor();
}
