#include "Border.h"
#include "PhysicsManager.h"

Border::Border(std::string name) : AGameObject(name), CollisionListener()
{
	this->name = name;
}

Border::~Border()
{

}

void Border::initialize()
{
	this->sprite = new sf::Sprite();

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(2000.0f, 50.0f)); // Width 200, Height 50
	rectangle->setFillColor(sf::Color::White); // Set color to white
	rectangle->setOutlineThickness(2.0f);
	rectangle->setOutlineColor(sf::Color::Black);
	rectangle->setOrigin(rectangle->getSize().x / 2, rectangle->getSize().y / 2);

	this->setPosition(1920 / 2, 2000);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(rectangle);
	this->attachComponent(renderer);

	Collider* collider = new Collider(this->name + " Collider");
	collider->setOffset(rectangle->getGlobalBounds());
	collider->assignListener(this);
	this->attachComponent(collider);

	PhysicsManager::getInstance()->trackObject(collider);
}

void Border::onCollisionEnter(AGameObject* object) {}
void Border::onCollisionExit(AGameObject* object) {}
