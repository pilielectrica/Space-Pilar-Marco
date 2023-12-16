#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;
int main()
{
    // Crear una ventana SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Movimiento Rectilíneo Uniforme Variado");
    // Definir la posición y velocidad inicial del objeto
    sf::Vector2f position(100.0f, 100.0f);
    sf::Vector2f velocity(2, 0.0f); // Velocidad inicial en el eje x (MRU) en el eje y(MRUV)
    // Constante de aceleración para el MRUV
    const float acceleration = 2;
    const float deceleration = 0.5;
    bool izquierda = false;
    bool derecha = false;


    // Bucle principal del juego
    while (window.isOpen())
    {
        float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        // Acelerar
        if (Keyboard::isKeyPressed(Keyboard::Right) && velocity.x < 5) {
            velocity.x += acceleration * deltaTime; derecha = true; izquierda = false;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left) && velocity.x > -5) {
            velocity.x -= acceleration * deltaTime; izquierda = true; derecha = false;
        }

        // Desacelerar
        if (derecha && velocity.x > 0) {
            velocity.x -= deceleration * deltaTime;
        }
        else if (izquierda && velocity.x < 0) {
            velocity.x += deceleration * deltaTime;
        }

        // Mover
        position.x += velocity.x * deltaTime;
        // Limpiar la ventana
        window.clear();
        // Dibujar el objeto en su posición actual
        sf::CircleShape object(60, 30);
        object.setPosition(position);
        object.setFillColor(sf::Color::Red);
        window.draw(object);
        // Mostrar todo en la ventana
        window.display();
    }
    return 0;
}