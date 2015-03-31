// Warning: This code isn't nice at all, so don't even think about using it in production code. ;-)

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Road");
    window.setFramerateLimit(60);

    sf::RectangleShape grass(sf::Vector2f(262.f, 768.f));
    grass.setFillColor(sf::Color(0, 100, 0));

    sf::RectangleShape road(sf::Vector2f(500.f, 768.f));
    road.setFillColor(sf::Color(50, 50, 50));
    road.setPosition(262.f, 0.f);

    const float HEIGHT = 70.f;
    const unsigned int STRIPES_COUNT = 7;

    sf::RectangleShape greyLight(sf::Vector2f(1024.f, HEIGHT));
    greyLight.setFillColor(sf::Color(50, 50, 50, 20));

    sf::RectangleShape greyDark(sf::Vector2f(1024.f, HEIGHT));
    greyDark.setFillColor(sf::Color(50, 50, 50, 50));

    sf::RectangleShape stripeWhite(sf::Vector2f(14.f, HEIGHT));
    stripeWhite.setFillColor(sf::Color::White);

    sf::RectangleShape stripeRed(sf::Vector2f(14.f, HEIGHT));
    stripeRed.setFillColor(sf::Color::Red);

    sf::Clock animation;
    float moved = 0.f;

    while(window.isOpen())
    {
        if(animation.getElapsedTime().asMilliseconds() > 10)
        {
            animation.restart();
            moved += 5.f;
            if(moved > HEIGHT*2)
                moved = 0.f;
        }

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        grass.setPosition(0.f, 0.f);
        window.draw(grass);

        grass.setPosition(762.f, 0.f);
        window.draw(grass);

        window.draw(road);

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            stripeWhite.setPosition(262.f, (moved+i*HEIGHT*2)-HEIGHT*2);
            window.draw(stripeWhite);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            stripeRed.setPosition(262.f, (moved+i*HEIGHT*2)-HEIGHT);
            window.draw(stripeRed);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            stripeWhite.setPosition(504.f, (moved+i*HEIGHT*2)-HEIGHT);
            window.draw(stripeWhite);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            stripeWhite.setPosition(748.f, (moved+i*HEIGHT*2)-HEIGHT*2);
            window.draw(stripeWhite);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            stripeRed.setPosition(748.f, (moved+i*HEIGHT*2)-HEIGHT);
            window.draw(stripeRed);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            greyLight.setPosition(0.f, (moved+i*HEIGHT*2)-HEIGHT*2);
            window.draw(greyLight);
        }

        for(unsigned int i = 0; i < STRIPES_COUNT; ++i)
        {
            greyDark.setPosition(0.f, (moved+i*HEIGHT*2)-HEIGHT);
            window.draw(greyDark);
        }

        window.display();
    }
}
