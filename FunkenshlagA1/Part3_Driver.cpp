//#include <iostream>
//#include "Resource.h"
//#include "Player.h"
//#include "ResourceManager.h"
//#include "ResourceMarket.h"
//#include "House.h"
////
////using namespace std;
////
////int main() {
////    cout << "--------------------------------------------------------------" << endl;
////    cout << "This part will create 4 Arrays of the different Resource Types(Coal, Oil,Garbage, and Uranium)" << endl;
////    cout << "and print out their contents." << endl << endl;
////    //DECLARE AND INITIALIZE ARRAYS OF RESOURCES
////    Resource coal[3];
////    Resource oil[3];
////    Resource garbage[3];
////    Resource uranium[1];
////    for (int i = 0; i < sizeof(coal) / sizeof(Resource); i++) {
////        coal[i] = Resource(1, COAL);
////        oil[i] = Resource(3, OIL);
////        garbage[i] = Resource(7, GARBAGE);
////    }
////    uranium[0] = Resource(10, URANIUM);
////
////    //PRINT THE CONTENTS OF THE RESOURCE ARRAYS
////    cout << "ARRAY OF 3 COAL" << endl;
////    for (int i = 0; i < sizeof(coal) / sizeof(Resource); i++) {
////        cout << coal[i] << endl;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 3 OIL" << endl;
////    for (int i = 0; i < sizeof(oil) / sizeof(Resource); i++) {
////        cout << oil[i] << endl;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 3 GARBAGE" << endl;
////    for (int i = 0; i < sizeof(garbage) / sizeof(Resource); i++) {
////        cout << garbage[i] << endl;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 1 URANIUM" << endl;
////    for (int i = 0; i < sizeof(uranium) / sizeof(Resource); i++) {
////        cout << uranium[i] << endl;
////    }
////    cout << "--------------------------------------------------------------" << endl;
////
////    cout << "These arrays can then be placed within a Resource Market." << endl;
////    cout << "This is where the Resources will be kept on the map." << endl;
////    cout << "For this example they are being manually put in." << endl;
////
////    ResourceMarket rMarket = ResourceMarket();
////    rMarket.getSlots()[0].setCoal(coal);
////    rMarket.getSlots()[2].setOil(oil);
////    rMarket.getSlots()[6].setGarbage(garbage);
////    rMarket.getSlots()[9].setUranium(uranium);
////    cout << endl << "The Resource will now be printed again, but this time they are" << endl;
////    cout << "being printed from the Resource Market." << endl << endl;
////
////    cout << "ARRAY OF 3 COAL" << endl;
////    for (int i = 0; i < sizeof(coal) / sizeof(Resource); i++) {
////        cout << rMarket.getSlots()[0].getSlotCoal()[i] << endl;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 3 OIL" << endl;
////    for (int i = 0; i < sizeof(oil) / sizeof(Resource); i++) {
////        cout << rMarket.getSlots()[2].getSlotOil()[i] << endl;;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 3 GARBAGE" << endl;
////    for (int i = 0; i < sizeof(garbage) / sizeof(Resource); i++) {
////        cout << rMarket.getSlots()[6].getSlotGarbage()[i] << endl;
////    }
////    cout << endl;
////
////    cout << "ARRAY OF 1 URANIUM" << endl;
////    for (int i = 0; i < sizeof(uranium) / sizeof(Resource); i++) {
////        cout << rMarket.getSlots()[9].getSlotUranium()[i] << endl;
////    }
////    cout << "--------------------------------------------------------------" << endl << endl;
////    cout << "Houses will be kept within Player objects. Actually placing House Objects on the map is not needed." << endl;
////    House h1 = House(RED);
////    cout << h1.getColor() << endl;
////
////    cout << "--------------------------------------------------------------" << endl << endl;
////    cout << "Elektro is kept as integers within different classes. For example, a player as an" << endl;
////    cout << "amount of elektro kept at all times." << endl;
////    Player p1 = Player("Anthony", 50, RED);
////    cout << p1 << endl;
////    system("pause");
////
////    return 0;
////}
//
//int main() {
//	ResourceMarket* market = new ResourceMarket();
//	std::cout << *market << std::endl;
//
//	std::cout << "COAL: " << market->getNumOfCoal() << std::endl;
//	std::cout << "OIL: " << market->getNumOfOil() << std::endl;
//	std::cout << "GARBAGE: " << market->getNumOfGarbage() << std::endl;
//	std::cout << "URANIUM: " << market->getNumOfUranium() << std::endl;
//
//	market->bought(COAL, 1);
//	market->bought(GARBAGE, 1);
//	market->bought(OIL, 1);
//	market->bought(URANIUM, 1);
//	std::cout << *market << std::endl;
//	std::cout << "COAL: " << market->getNumOfCoal() << std::endl;
//	std::cout << "OIL: " << market->getNumOfOil() << std::endl;
//	std::cout << "GARBAGE: " << market->getNumOfGarbage() << std::endl;
//	std::cout << "URANIUM: " << market->getNumOfUranium() << std::endl;
//
//	market->resupply(2, 1);
//	std::cout << *market << std::endl;
//	std::cout << "COAL: " << market->getNumOfCoal() << std::endl;
//	std::cout << "OIL: " << market->getNumOfOil() << std::endl;
//	std::cout << "GARBAGE: " << market->getNumOfGarbage() << std::endl;
//	std::cout << "URANIUM: " << market->getNumOfUranium() << std::endl;
//	system("pause");
//}