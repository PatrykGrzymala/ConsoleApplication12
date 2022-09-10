#pragma once
#include "tower.h"

class buffTower :public tower
{
	buffTower();
	~buffTower();
	void activateHUD();
	void unactiveHUD();
	void upgrade();
	auto getWorkshopTemplate()->tower::workshopHandler *();
	tower::shopTemplate * buffTower::getShopTemplate();
	bool mouseOnHUD(const sf::Vector2f mousePos);
	bool isPointOnCircle(sf::Vector2f point);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void addBuff(buff buffer);
	void setPosition(sf::Vector2f position);
	bool canBuff(tower * tw);
	void workshopHandler::join(workshop *ws);
	void workshopHandler::configureUpgrader();
	bool workshopHandler::goldUpgradeAccesed();
	void workshopHandler::place();
	void workshopHandler::update();
	void workshopHandler::handleSeller();
	void workshopHandler::handleUpgrader();
	void workshopHandler::set();
	void workshopHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const;
	shopTemplate::shopTemplate(buffTower * ownr) : tower::shopTemplate(ownr);
	void shopTemplate::draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void shopTemplate::setPosition(sf::Vector2f position);
	sf::Vector2f buffTower::shopTemplate::getSize();





};