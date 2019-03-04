#include <iostream>
#include "Resource.h"

using namespace std;

int main() {
	Resource one = Resource(1, COAL);
	cout << one.getPrice() << " " + one.getType() << endl;
	return 0;
}