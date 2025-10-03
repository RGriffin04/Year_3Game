#include <SFML/Graphics.hpp>

const sf::Keyboard::Key controls[4] = {
		sf::Keyboard::A,
		sf::Keyboard::Z,
		sf::Keyboard::Up,
		sf::Keyboard::Down
};


const sf::Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;
const float time_step = 0.017f;


sf::CircleShape ball;
sf::RectangleShape paddles[2];

void init() {
	for (sf::RectangleShape& p : paddles) {
		p.setSize(paddleSize);
		p.setOrigin(paddleSize / 2.f);
	}

	ball.setRadius(ballRadius);
	ball.setOrigin(ballRadius, ballRadius);	

	paddles[0].setPosition(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f);
	paddles[1].setPosition(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f);

	ball.setPosition(gameWidth / 2.f, gameHeight / 2.f);
}

void update(float dt) {
	// handle paddle movement
	float direction = 0.0f;
	if (sf::Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (sf::Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}
	paddles[0].move(sf::Vector2f(0.f, direction * paddleSpeed * dt));
}

void render(sf::RenderWindow& window) {
	// Draw Everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Pong Game");
    init();

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();
        update(dt);

        window.clear();
        render(window);
        window.display();
    }
    return 0;
}