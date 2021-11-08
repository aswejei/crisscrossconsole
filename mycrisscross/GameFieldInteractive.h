#pragma once
class GameFieldInteractive
{
	private:
		bool gamefield[3][3][2];
		//трехмерный массив логических переменных, содержащий в себе на первом слое информацию о наличии хода в данном поле,
		//а на втором слое информацию о том, кто ходил(крестик - true/нолик - false)

		//int MoveCounter;  счетчик числа ходов, увеличивается  на 1 при каждом ходе, используется для определения ничьей

		//int CombinationsField[8][2];
		//массив на 8 строк и 2 столбца, 1 столбец - число крестиков, 2 столбец - число ноликов, 1 строка - главная диагональ, 2 строка - побочная диагональ
		//3-5 строки - 1-3 строки поля(снизу вверх), 6-8 строки - 1-3 столбцы поля(слева направо)

		//struct fieldid //структура преобразующая номер поля, вводимый польщователем в номер поля в массиве gamefield
		//{
			/*int field1;
			int field2;*/
			
		int field1;
		int field2;
		void fieldid(int fieldnumber)
		{
				this->field1 = fieldnumber / 3;
				this->field2 = fieldnumber % 3;	
		};
		//};
		//bool CheckMovePossibility(int fieldnumber)//метод определяющий возможность походить исходя из наличия крестика/нолика в проверяемом поле
		//{
		//	fieldid id(fieldnumber);
		//	if (gamefield[id.field1][id.field2][0] == false)
		//	{
		//		return true;
		//	}
		//	else
		//	{
		//		return false;
		//	}
		//}
	public:
		/*bool GetGameField(int fieldnumber) 
		{
			fieldid id(fieldnumber);
			return gamefield[id.field1][id.field2][1];
		}*/

		GameFieldInteractive() 
		{
			//this->MoveCounter = 0;
			for (int i = 0; i <= 2; i++) 
			{
				for (int j = 0; j <= 2; j++) 
				{
					for (int k = 0; k <= 1; k++) 
					{
						gamefield[i][j][k] = false;
					}
				}
			}
		}
		void GetMove(int fieldnumber, bool playerID) //метод записи хода в поле, в случае невозможности хода возвращает false, в случае успеха - true
		{
			
				/*fieldid id(fieldnumber);*/
			    fieldid(fieldnumber);
				gamefield[field1][field2][0] = true;
				if (playerID) 
				{
					gamefield[field1][field2][1] = true;
				}
				else 
				{
					gamefield[field1][field2][1] = false;
				}
				//MoveCounter++;

		}
		bool CheckMovePossibility(int fieldnumber)//метод определяющий возможность походить исходя из наличия крестика/нолика в проверяемом поле
		{
			/*fieldid id(fieldnumber);*/
			fieldid(fieldnumber);
			if (gamefield[field1][field2][0] == false)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
};

