#include "bullet.h"
#include "Template.h"
#include "attackTower.h"

bullet::bullet(sf::Vector2f size, attackTower* ownr)
{
	bullets.setSize(size);
	velocity.x = 1;
	velocity.y  = 1;
	owner = ownr;
	dmg = owner->getPower();
	timer = sf::Time::Zero;
	speed = 0.001f;
}

bullet::~bullet() {

}
