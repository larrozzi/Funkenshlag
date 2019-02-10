# include PLayer.h
#include <iostream>


using std::shared_ptr;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;

 Player :: Player()
{}

 Player::Player(string name, shared_ptr<HouseColor> color, int elektro) :
	 name{ name }, elektro{ elektro }, color{ color }
 {}

 Player ::~Player()
 {}

 string getName() const{
	 return name;
 }

 void setName(string name) {
	 this->name = name;
 }


 int getElektro() const {
	 return elektro;
 }
 void setElektro(int elektro) {
	 this->elektro = elektro;
 }

 vector <shared_ptr<House>> getHouses() {
	 return houses;
 }

 vector <shared_ptr<PowerPlant>> getPowerplant() {
	 return powerplants;
 }
 vector <Resource> getRecources() {
	 return resources;
 }

 bool bidonPowerPlant(cardDeck&, int position, int price) {
	 if (position >= 0 && position <= 3 & getElektro() >= price)
		 setElektro(getElektro() - price);
	 // further rules
 }
 bool AddPowerPlant(<shared_ptr<PowerPlant>> powerplants) {

 }
 void ReplacePowerPlant(<shared_ptr<PowerPlant>> newplant, int toReplace) {

 }
 int getHighestPowerPlant() {
	 int max;
	 for (std::shared_ptr<PowerPlant> highestplant : powerplants) {
		 if (highestplant->getPrice() > max)
			 max = highestplant->getPrice();
	 }
	 return max;

 }

 shared_ptr<HouseColor> const& getColor() const {

 }

 bool BuyResources(ResourceMarket&, shared_ptr<PowerPlant>, Resource, int) {

 }

 void ShowGameStatus() const {

 }

 inline std::ostream& operator<<(std::ostream& stream, const Player& player) {
	 
 }
