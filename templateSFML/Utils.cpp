#include "Utils.h"

#define PI 3.14159
#define SQRT2 1.41421
#define SQRT3 1.73205
#define COS30 0.15425
#define COS45 0.52532

#define GRAVITE_TERRE 9.807
#define GRAVITE_LUNE 1.62
#define GRAVITE_MARS 3.721
#define GRAVITE_VENUS 8.87
#define GRAVITE_PLUTON 0.62
#define GRAVITE_JUPITER 24.79
#define GRAVITE_SATURNE 10.44
#define GRAVITE_MERCURE 3.7
#define GRAVITE_SOLEIL 274


sf::Sprite Sfml::Utils::LoadSprite(const std::string& _filename, bool _isCentered)
{
    sf::Texture* textTemp = new sf::Texture();
    textTemp->loadFromFile(_filename);

    sf::Sprite spriteTemp;
    spriteTemp.setTexture(*textTemp);

    if (_isCentered)
    {
        spriteTemp.setOrigin(textTemp->getSize().x / 2, textTemp->getSize().y / 2);
    }

    return spriteTemp;
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderWindow* _window)
{
    _sprite.setPosition(_vector);
    _window->draw(_sprite);
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderTexture* _renderTexture)
{
    _sprite.setPosition(_vector);
    _renderTexture->draw(_sprite);
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::RenderTexture* _renderTexture, sf::Shader& _shader)
{
    _sprite.setPosition(_vector);
    _renderTexture->draw(_sprite,&_shader);
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, float _angle, sf::RenderWindow* _window)
{
    _sprite.setRotation(_angle);
    _sprite.setPosition(_vector);
    _window->draw(_sprite);
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vector, sf::Color _color, sf::RenderWindow* _window)
{
    _sprite.setPosition(_vector);
    _sprite.setColor(_color);
    _window->draw(_sprite);
}

void Sfml::Utils::blitSprite(sf::Sprite _sprite, sf::Vector2f _vectorPos, sf::Vector2f _vectorScale, sf::Color _color, sf::RenderWindow* _window)
{
    _sprite.setPosition(_vectorPos);
    _sprite.setScale(_vectorScale);
    _sprite.setColor(_color);
    _window->draw(_sprite);
}

void Sfml::Utils::blitText(sf::Text _text, sf::Vector2f _vector, sf::RenderWindow* _window)
{
    _text.setPosition(_vector);
    _window->draw(_text);
}

bool Sfml::Utils::AABB_AABB_Collision(sf::RectangleShape* aabb1, sf::RectangleShape* aabb2)
{
    sf::Vector2f R1Min = aabb1->getPosition();
    sf::Vector2f R2Min = aabb2->getPosition();

    sf::Vector2f R1Max = aabb1->getPosition() + aabb1->getSize();
    sf::Vector2f R2Max = aabb2->getPosition() + aabb2->getSize();

    return !((R1Max.x < R2Min.x)
        || (R1Min.x > R2Max.x)
        || (R1Max.y < R2Min.y)
        || (R1Min.y > R2Max.y));
}

sf::Vector2f Sfml::Utils::GetRectangleLengthAxis(sf::RectangleShape* rect)
{
    sf::Vector2f rectSize = rect->getSize();
    float rectRotation = Math::Utils::DegreesToRadians(rect->getRotation());

    return sf::Vector2f(rectSize.x * cos(rectRotation), rectSize.x * sin(rectRotation));
}

sf::Vector2f Sfml::Utils::GetRectangleHeightAxis(sf::RectangleShape* rect)
{
    sf::Vector2f rectSize = rect->getSize();
    float rectRotation = Math::Utils::DegreesToRadians(rect->getRotation());

    return sf::Vector2f(-rectSize.y * sin(rectRotation), rectSize.y * cos(rectRotation));
}

sf::Vector2f* Sfml::Utils::GetRectangleCorners(sf::RectangleShape* rect)
{
    sf::Vector2f* corners = new sf::Vector2f[4];

    sf::Vector2f rectPos = rect->getPosition();
    sf::Vector2f lengthAxis = GetRectangleLengthAxis(rect);
    sf::Vector2f heightAxis = GetRectangleHeightAxis(rect);

    corners[0] = sf::Vector2f(rectPos.x - lengthAxis.x / 2 - heightAxis.x / 2, rectPos.y - lengthAxis.y / 2 - heightAxis.y / 2);
    corners[1] = sf::Vector2f(rectPos.x - lengthAxis.x / 2 + heightAxis.x / 2, rectPos.y - lengthAxis.y / 2 + heightAxis.y / 2);
    corners[2] = sf::Vector2f(rectPos.x + lengthAxis.x / 2 + heightAxis.x / 2, rectPos.y + lengthAxis.y / 2 + heightAxis.y / 2);
    corners[3] = sf::Vector2f(rectPos.x + lengthAxis.x / 2 - heightAxis.x / 2, rectPos.y + lengthAxis.y / 2 - heightAxis.y / 2);

    return corners;
}

bool Algo::Utils::isCollission(float px, float py, float rx, float ry, float rw, float rh)
{
    // is the point inside the rectangle's bounds?
    if (px >= rx &&        // right of the left edge AND
        px <= rx + rw &&   // left of the right edge AND
        py >= ry &&        // below the top AND
        py <= ry + rh) {   // above the bottom
        return true;
    }
    return false;
}

bool Algo::Utils::isCollissionCentred(float px, float py, float rx, float ry, float rw, float rh)
{
    return false;
}

int Algo::Utils::Alea(int _min, int _max)
{
    return (_min + rand() % (_max - _min + 1));
}

int Algo::Utils::Alea(int _max)
{
    return (rand() % _max + 1);
}

float Math::Utils::GetVectorLength(sf::Vector2f vector)
{
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

float Math::Utils::DotProduct(sf::Vector2f v1, sf::Vector2f v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}


float Math::Utils::DistSquare(sf::Vector2f _point1, sf::Vector2f _point2)
{
    float x = _point2.x - _point1.x;
    float y = _point2.y - _point1.y;
    return ((x * x) + (y * y));
}

float Math::Utils::Dot(sf::Vector2f _v1, sf::Vector2f _v2)
{
    return _v1.x * _v2.x + _v1.y * _v2.y;
}

float Math::Utils::ProjectionOnAxis(sf::Vector2f _axis, sf::Vector2f _point)
{
    return Dot(_axis, _point);
}

sf::Vector2f Math::Utils::PointsToVect(sf::Vector2f _point1, sf::Vector2f _point2)
{
    return sf::Vector2f({ _point2.x - _point1.x,_point2.y - _point1.y });
}

float Math::Utils::produitScalaire(sf::Vector2f _vector1, sf::Vector2f _vector2)
{
    return  _vector1.x * _vector2.x + _vector1.y * _vector2.y;
}

void Math::Utils::SATTest(sf::Vector2f _axe, sf::Vector2f _points[], float* _min, float* _max)
{
    *_min = std::numeric_limits<float>::infinity();
    *_max = -std::numeric_limits<float>::infinity();

    for (int i = 0; i < 4; i++)
    {
        float dotProduct = Math::Utils::Dot(_axe, _points[i]);

        if (dotProduct < *_min)
        {
            *_min = dotProduct;
        }

        if (dotProduct > *_max)
        {
            *_max = dotProduct;
        }
    }
}

bool Math::Utils::OverLaps(float _min1, float _max1, float _min2, float _max2)
{
    return (_min1 <= _min2 && _min2 <= _max1) || (_min2 <= _min1 && _min1 <= _max2);
}

bool Math::Utils::Intersection(sf::RectangleShape* _forme1, sf::RectangleShape* _forme2)
{
    float forme1Min, forme1Max, forme2Min, forme2Max = 0;
    sf::Vector2f* rectangleCorner1 = Sfml::Utils::GetRectangleCorners(_forme1);
    sf::Vector2f* rectangleCorner2 = Sfml::Utils::GetRectangleCorners(_forme2);


    for (int i = 0; i < 4; i++)
    {
        sf::Vector2f axe = rectangleCorner1[i] - rectangleCorner1[(i + 1) % 4];

        Math::Utils::SATTest(axe, rectangleCorner1, &forme1Min, &forme1Max);
        Math::Utils::SATTest(axe, rectangleCorner2, &forme2Min, &forme2Max);

        if (!Math::Utils::OverLaps(forme1Min, forme1Max, forme2Min, forme2Max))
        {
            return 0;
        }

    }


    for (int i = 0; i < 4; i++)
    {
        sf::Vector2f axe = rectangleCorner2[i] - rectangleCorner1[(i + 1) % 4];

        Math::Utils::SATTest(axe, rectangleCorner2, &forme1Min, &forme1Max);
        Math::Utils::SATTest(axe, rectangleCorner2, &forme2Min, &forme2Max);

        if (!OverLaps(forme1Min, forme1Max, forme2Min, forme2Max))
        {
            return 0;
        }

    }

    return true;
}

sf::Vector2f Math::Utils::NormalizeVector(sf::Vector2f vector)
{
    float vectorLength = GetVectorLength(vector);
    if (vectorLength == 0.0f)
    {
        return sf::Vector2f(0, 0);
    }

    float newX = vector.x / vectorLength;
    float newY = vector.y / vectorLength;

    return sf::Vector2f(newX, newY);
}

sf::Vector2f Math::Utils::RotateVector(sf::Vector2f vector, float angle)
{
    float COS = cos(angle);
    float SIN = sin(angle);

    float newX = vector.x * COS - vector.y * SIN;
    float newY = vector.x * SIN + vector.y * COS;

    return sf::Vector2f(newX, newY);
}

float Math::Utils::DegreesToRadians(float angle)
{
    return angle * (float)PI / 180;
}

float Math::Utils::RadiansToDegrees(float angle)
{
    return angle * 180 / (float)PI;
}

bool Math::Utils::IsInBetween(float _value, float _min, float _max)
{
    return (_value <= _max && _value >= _min);
}

float Math::Utils::Clamp(float _value, float _min, float _max)
{
    if (_value > _max) return _max;
    else if (_value < _min) return _min;
    else return _value;
}

sf::Vector2f Math::Utils::Interpolation(float t,const sf::Vector2f& start, const sf::Vector2f& end)
{
    float ratio = Clamp(t, 0, 1);

    return sf::Vector2f(0,0);
    //return ((1 - ratio) * start / t) * end;
}

