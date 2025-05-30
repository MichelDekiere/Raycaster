#include <SFML/Graphics.hpp>

int main()
{
    unsigned int winHeight = 800;
    unsigned int winWidth = winHeight;

    sf::RenderWindow window(sf::VideoMode({ winHeight, winWidth }), "Raycaster");
    sf::RectangleShape shape({ 100-10, 100-10 });
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    int map[8][8] =
    {
        {1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,0,1,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}
    };

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {

                if (map[j][i] == 1) {

                    sf::Transform t;
                    t.translate({ (float)i*100, (float)j*100 });
                    window.draw(shape, t);
                }

            }

        }
        window.display();
    }
}