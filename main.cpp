#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;


namespace Game
{
    class PianoTiles : public sf::Drawable, public sf::Transformable
    {
    public:
        sf::Vector2u windowSize;

        PianoTiles(sf::Vector2u windowSize_)
            : windowSize(windowSize_) { }

    private:
        virtual void draw(sf::RenderWindow &target, sf::RenderStates states) const
        {
            
        }
    };

    class Tiles : public sf::Drawable, public sf::Transformable
    {
    private:
        sf::VertexArray         m_vertices;

        std::vector<uint8_t>    m_layout;

        uint8_t                 m_tileCountPerRow;

        unsigned int            m_tileTotalCount;

        

    public:

        Tiles(std::vector<uint8_t> *layout_, unsigned int tileTotalCount_, uint8_t tileCountPerRow_= 4)
        {
            generateTiles(layout_, tileTotalCount_, tileCountPerRow_);
        }

        void generateTiles(std::vector<uint8_t> *layout_, unsigned int tileTotalCount_, uint8_t tileCountPerRow_)
        {
            m_vertices.resize(m_tileTotalCount);

            std::vector<std::vector<uint8_t>> parseTileLayout 
                = parseCompressedTiles(layout_, tileTotalCount_, tileCountPerRow_);
        }

        void update(float &dt)
        {
            
        }
    };

    std::vector<std::vector<uint8_t>> parseCompressedTiles(std::vector<uint8_t> *layout, unsigned int tileTotalCount, uint8_t tileCountPerRow)
    {
        std::vector<std::vector<uint8_t> > parsedTiles;
        parsedTiles.reserve(tileTotalCount);

        
        for (unsigned int tileCounter = 0; uint8_t &byte: *layout)
        {
            for (uint8_t i = 0; i < 7; i++)
                if (byte & (uint8_t)std::pow(2, i))
                {
                    cout << i << endl;

                    if (i >= tileCountPerRow) break;

                    if (++tileCounter >= tileTotalCount) 
                        return parsedTiles;
                }
        }    
    }
}


int main()
{
    float windowScale = 30;

    sf::RenderWindow window(sf::VideoMode(9 * windowScale, 16 * windowScale), "SFML works!");
    window.setVerticalSyncEnabled(true);

    std::vector<uint8_t> tileLayout
    {
        0b01000000,
        0b10100000,
        0b01000000,
        0b00100000,
        0b01000000,
        
    }

    Game::PianoTiles pianoTiles();

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        float dt = (float)deltaClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed);
                window.close();
        }

        //cout << 1 / dt << endl;

        shape.move(0, 10 * dt);

        window.clear();
        window.draw(shape);
        window.display();
    }   

    return 0;
}

