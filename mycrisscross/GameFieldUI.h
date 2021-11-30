#pragma once
#include <iostream>
class GameFieldUI
{
	private:
		char fieldids[9] = { '0','1','2','3','4','5','6','7', '8' };
		char emptyfield[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-'};
	public:
		char GetGameField(size_t index) {
			return emptyfield[index];
		}
		void setGameField3(bool playerid, size_t index) {
			if (playerid) {
				emptyfield[index] = '0';
			}
			else {
				emptyfield[index] = 'X';
			}
		}
		void ShowStartField() {
			std::cout << "-" << fieldids[6] << "-|-" << fieldids[7] << "-|-" << fieldids[8] << "-\n";
			std::cout << "-" << fieldids[3] << "-|-" << fieldids[4] << "-|-" << fieldids[5] << "-\n";
			std::cout << "-" << fieldids[0] << "-|-" << fieldids[1] << "-|-" << fieldids[2] << "-\n";
		}
		void ShowCurrentField() 
		{
			std::cout << "-" << emptyfield[6] << "-|-" << emptyfield[7] << "-|-" << emptyfield[8] << "-\n";
			std::cout << "-" << emptyfield[3] << "-|-" << emptyfield[4] << "-|-" << emptyfield[5] << "-\n";
			std::cout << "-" << emptyfield[0] << "-|-" << emptyfield[1] << "-|-" << emptyfield[2] << "-\n";
		}
};

