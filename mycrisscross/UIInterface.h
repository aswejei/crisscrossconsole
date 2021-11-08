#pragma once
#include"WinsChecker.h"
#include"GameFieldInteractive.h"
#include"Inputchecker.h"
#include"GameFieldUI.h"
#include<iostream>
#include<string>
class UIInterface
{
	public:
		void StartUI() 
		{
			std::cout << "Enter start to start the game"<<std::endl;
			std::string s;
			std::getline(std::cin, s);
			while (InputChecker::Startchecker(s) != true) {
				std::cout << "Input is incorrect, please try again"<<std::endl;
				std::getline(std::cin, s);
			}
			WinsChecker checker1;
			GameFieldInteractive game1;
			GameFieldUI ui1;
			
			std::cout << "Enter X or 0 depending on who would be the first player"<<std::endl;
			std::string c;
			std::getline(std::cin, c);
			while (InputChecker::CrissCrossChecker(c) != true) {
				std::cout << "Input is incorrect, please try again" << std::endl;
				std::getline(std::cin, c);
			}
			bool playerid=false;
			if (c == "X") {
				playerid = false;
			}
			else if (c == "0") {
				playerid = true;
			}
			std::cout << c << " would be the first player to make move" << std::endl;
			std::cout << std::endl;
			std::cout << "All fields are marked with numbers, if ypu are making move, enter the field number you would like to make move to" << std::endl;
			ui1.ShowStartField();
			std::cout << "Choose field number to make move as ";
			if (playerid) 
			{
				std::cout << "0" << std::endl;
			}
			else 
			{ 
				std::cout << "X" << std::endl;
			}
			std::getline(std::cin, s);
			while (InputChecker::MoveChecker(s) != true) 
			{
				std::cout << "Input is incorrect, please try again" << std::endl;
				std::getline(std::cin, s);
			}
			int fieldnumber=std::stoi(s);
			bool mcc = game1.CheckMovePossibility(fieldnumber);
		/*	game1.GetMove(fieldnumber, playerid);*/
			while (!mcc) 
			{
				std::cout << "It's impossible to make move to the chosen field, please try again" << std::endl;
				std::cout << "Choose field number to make move as ";
				if (playerid)
				{
					std::cout << "0" << std::endl;
				}
				else
				{
					std::cout << "X" << std::endl;
				}
				std::getline(std::cin, s);
				while (InputChecker::MoveChecker(s) != true)
				{
					std::cout << "Input is incorrect, please try again" << std::endl;
					std::getline(std::cin, s);
				}
				fieldnumber = std::stoi(s);
				mcc = game1.CheckMovePossibility(fieldnumber);
			}
			game1.GetMove(fieldnumber, playerid);
			ui1.setGameField3(playerid, fieldnumber);
			ui1.ShowCurrentField();
			char st = checker1.CheckFieldState(fieldnumber, playerid);
			playerid = !playerid;
			do 
			{
				std::cout << "Choose field number to make move as ";
				if (playerid)
				{
					std::cout << "0" << std::endl;
				}
				else
				{
					std::cout << "X" << std::endl;
				}
				std::getline(std::cin, s);
				while (InputChecker::MoveChecker(s) != true)
				{
					std::cout << "Input is incorrect, please try again" << std::endl;
					std::getline(std::cin, s);
				}
				fieldnumber = std::stoi(s);
				bool mcc=game1.CheckMovePossibility(fieldnumber);
				/*	game1.GetMove(fieldnumber, playerid);*/
				while (!mcc)
				{
					std::cout << "It's impossible to make move to the chosen field, please try again" << std::endl;
					std::cout << "Choose field number to make move as ";
					if (playerid)
					{
						std::cout << "0" << std::endl;
					}
					else
					{
						std::cout << "X" << std::endl;
					}
					std::getline(std::cin, s);
					while (InputChecker::MoveChecker(s) != true)
					{
						std::cout << "Input is incorrect, please try again" << std::endl;
						std::getline(std::cin, s);
					}
					fieldnumber = std::stoi(s);
					/*mcc = game1.CheckMovePossibility(fieldnumber);*/
					mcc=game1.CheckMovePossibility(fieldnumber);
				}
				game1.GetMove(fieldnumber, playerid);
				ui1.setGameField3(playerid, fieldnumber);
				ui1.ShowCurrentField();
				st = checker1.CheckFieldState(fieldnumber, playerid);
				playerid = !playerid;
			} while (st=='N');
			if (st == 'X') { std::cout << "X's win!" << std::endl; }else 
				if(st=='0'){ std::cout << "0's win!" << std::endl; }else
				{std::cout << "Draw!" << std::endl;}
		}
};

