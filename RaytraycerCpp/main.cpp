#include <iostream>
#include <string>

int main() {
	std::string input = "";
	std::cout << "Hello World" << std::endl;
	std::cout << "Please put in some input: ";
	std::getline(std::cin, input);
	std::cout << "Your input: " + input << std::endl;
	std::cout << "Press any key to exit...";
	std::cin.get();
}