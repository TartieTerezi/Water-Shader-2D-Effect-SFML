#ifndef UTILS_H
#define UTILS_H

#include "Common.h"

namespace Sfml
{
	class Utils
	{
	public:
		static sf::Sprite LoadSprite(const std::string& _filename, bool _isCentered);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderWindow* _window);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderTexture* _renderTexture);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderTexture* _renderTexture,sf::Shader& _shader);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, float _angle, sf::RenderWindow* _window);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::Color _color, sf::RenderWindow* _window);
		static void blitSprite(sf::Sprite _sprite, sf::Vector2f _vectorPos, sf::Vector2f _vectorScale, sf::Color _color, sf::RenderWindow* _window);
		static void blitText(sf::Text _text, sf::Vector2f _vector, sf::RenderWindow* _window);
		static bool AABB_AABB_Collision(sf::RectangleShape* aabb1, sf::RectangleShape* aabb2);
		static sf::Vector2f GetRectangleLengthAxis(sf::RectangleShape* rect);
		static sf::Vector2f GetRectangleHeightAxis(sf::RectangleShape* rect);
		static sf::Vector2f* GetRectangleCorners(sf::RectangleShape* rect);
	};
	;
};



namespace Algo
{
	class Utils
	{
	public:
		static bool isCollission(float px, float py, float rx, float ry, float rw, float rh);
		static bool isCollissionCentred(float px, float py, float rx, float ry, float rw, float rh);
		static int Alea(int _min, int _max);
		static int Alea(int _max);
	};
	;
};


namespace Math
{
	class Utils
	{
	public:
		static float GetVectorLength(sf::Vector2f vector);
		static float DotProduct(sf::Vector2f v1, sf::Vector2f v2);
		static float DistSquare(sf::Vector2f _point1, sf::Vector2f _point2);
		static float Dot(sf::Vector2f _v1, sf::Vector2f _v2);
		static float ProjectionOnAxis(sf::Vector2f _axis, sf::Vector2f _point);
		static sf::Vector2f PointsToVect(sf::Vector2f _point1, sf::Vector2f _point2);
		static float produitScalaire(sf::Vector2f _vector1, sf::Vector2f _vector2);
		static void SATTest(sf::Vector2f _axe, sf::Vector2f _points[], float* _min, float* _max);
		static bool OverLaps(float _min1, float _max1, float _min2, float _max2);
		static bool Intersection(sf::RectangleShape* _forme1, sf::RectangleShape* _forme2);
		static sf::Vector2f NormalizeVector(sf::Vector2f vector);
		static sf::Vector2f RotateVector(sf::Vector2f vector, float angle);
		static float DegreesToRadians(float angle);
		static float RadiansToDegrees(float angle);

		static bool IsInBetween(float _value, float _min, float _max);
		static float Clamp(float _value, float _min, float _max);
		static sf::Vector2f Interpolation(float t, const sf::Vector2f& start, const sf::Vector2f& end);
	};
};
#endif // !UTILS_H
