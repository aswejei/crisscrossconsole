#pragma once
 class InputChecker
{
	public:
		InputChecker() {
		}
		static bool CrissCrossChecker(std::string crisscross) 
		{
			std::string Cross = "X";
			std::string Zero = "0";
			/*char* crcr= new char[crisscross.length() + 1];
			strcpy(crcr, crisscross.c_str());*/
			if (crisscross==Cross||crisscross==Zero)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		static bool MoveChecker(std::string move1)
		{
			/*char* move = new char[move1.length() + 1];
			strcpy(move, move1.c_str());*/
			if (move1 == "0"|| move1 == "1" || move1 == "2" || move1 == "3" || move1 == "4" || move1 == "5" || move1 == "6" || move1 == "7" || move1 == "8")
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		static bool Startchecker(std::string start1) 
		{
			std::string Start = "start";
			/*char* start = new char[start1.length() + 1];
			strcpy(start, start1.c_str());*/
			if (/*start[0] == Start && start[1] == '\0' && std::strlen(start)==2*/start1==Start) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		//static bool GameQuitChecker(std::string gamequit1) 
		//{
		//	/*char* gamequit = new char[gamequit1.length() + 1];
		//	strcpy(gamequit, gamequit1.c_str());*/
		//	if (gamequit1==GameQuit) 
		//	{
		//		return true;
		//	}
		//	else 
		//	{
		//		return false;
		//	}
		//}
};

