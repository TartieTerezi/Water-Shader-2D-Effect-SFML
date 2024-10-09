#include "common.h"
#include "DataManager.h"
#include "screen.h"

#define VITESSE_MAX 100;
#define TTLDIRECTION_MAX 10
#define POID_MAX 10


class Water
{
public:
	Water(Data* _data);
	~Water();

	float GetPoid();

	sf::Vector2f GetPos();
	void Update();
	void Draw();
	sf::Color GetColor();
private:
	sf::CircleShape m_circle;
	sf::Vector2f m_pos;
	float m_vitesse;
	float m_poid;


	Data* m_instanceData;
};

