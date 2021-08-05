#include <iostream>
#include <string>
#include "PutItTogether.h"


int main() {
	int chapterNum;
	std::cout << "Hello Bro!" << std::endl;
	std::cout << "Please choose which chapter PIT program: ";
	std::cin >> chapterNum;
	switch (chapterNum) {
		case 1:
			PITChapter1();
			break;
		case 2:
			PITChapter2();
			break;
		default:
			std::cout << "Yo man, that chapter not exist!" << std::endl;
	}
	std::cout << "Press Enter to exit..." << std::endl;
	std::cin.get();
}