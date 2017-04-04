#include "unittest.h"
#include <iostream>

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		// HACK pause to let me read it
		system("pause");
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;
	// HACK pause to let me read it
	system("pause");
	return 0;
}