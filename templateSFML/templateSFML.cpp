
#include "common.h"
#include "screen.h"
#include "DataManager.h"
#include "Utils.h"
#include "character.h"

void load(Data* _data)
{
    _data->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGTH), NAME_APP, sf::Style::Fullscreen);
    _data->window->setFramerateLimit(60);
    _data->isLoaded = true;
}


struct Splash
{
    Water* water;
    Splash* nextSplash;
};


int main()
{
    Data data;

    load(&data);
    srand(time(0));

    Splash* newSplash = nullptr;
    for (short i = 0; i < 5000; i++)
    {
        newSplash = new Splash({ new Water(&data),newSplash });
    }

    data.RT.create(SCREEN_WIDTH, SCREEN_HEIGTH);
    sf::Sprite renderSprite;
    renderSprite.setTexture(data.RT.getTexture());
   
    data.dt = data.clock.restart().asSeconds();

    sf::Shader shader;
    shader.loadFromFile("../Assets/Shaders/eau.frag", sf::Shader::Fragment);


    while (data.window->isOpen())
    {
        while (data.window->pollEvent(data.event))
        {
            //KEYBOARD
            switch (data.event.type)
            {
            case sf::Event::Closed:
                data.window->close();
                break;
            case sf::Event::KeyPressed:
                if (data.event.key.code == sf::Keyboard::Escape)
                {
                    data.window->close();
                }
                break;
            break;
            default:
                break;
            }
        }

        //UPDATE
        data.dt = data.clock.restart().asSeconds();

        //UPDATE

        Splash* SplashElement = newSplash;
        do {
            SplashElement->water->Update();

            SplashElement = SplashElement->nextSplash;
        } while (SplashElement->nextSplash != nullptr);

        //DRAW
        data.window->clear();
        data.RT.clear();

        SplashElement = newSplash;
        do {
            SplashElement->water->Draw();
            SplashElement = SplashElement->nextSplash;
        } while (SplashElement != nullptr);


        data.RT.display();
        data.window->draw(renderSprite,&shader);
        data.window->display();
    }
}

