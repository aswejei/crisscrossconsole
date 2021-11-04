#pragma once
class GameFieldInteractive
{
	private:
		bool gamefield[3][3][2];
		//���������� ������ ���������� ����������, ���������� � ���� �� ������ ���� ���������� � ������� ���� � ������ ����,
		//� �� ������ ���� ���������� � ���, ��� �����(������� - true/����� - false)

		//int MoveCounter;  ������� ����� �����, �������������  �� 1 ��� ������ ����, ������������ ��� ����������� ������

		//int CombinationsField[8][2];
		//������ �� 8 ����� � 2 �������, 1 ������� - ����� ���������, 2 ������� - ����� �������, 1 ������ - ������� ���������, 2 ������ - �������� ���������
		//3-5 ������ - 1-3 ������ ����(����� �����), 6-8 ������ - 1-3 ������� ����(����� �������)

		struct fieldid //��������� ������������� ����� ����, �������� ������������� � ����� ���� � ������� gamefield
		{
			int field1;
			int field2;
			fieldid(int fieldnumber) {
				this->field1 = fieldnumber/3;
				this->field2 = fieldnumber%3;
			}
		};
		bool CheckMovePossibility(int fieldnumber)//����� ������������ ����������� �������� ������ �� ������� ��������/������ � ����������� ����
		{
			fieldid id(fieldnumber);
			if (gamefield[id.field1][id.field2][0] == false)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
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
		bool GetMove(int fieldnumber, bool playerID) //����� ������ ���� � ����, � ������ ������������� ���� ���������� false, � ������ ������ - true
		{
			if (CheckMovePossibility(fieldnumber)) 
			{
				fieldid id(fieldnumber);
				gamefield[id.field1][id.field2][0] = true;
				if (playerID) 
				{
					gamefield[id.field1][id.field2][1] = true;
				}
				else 
				{
					gamefield[id.field1][id.field2][1] = false;
				}
				//MoveCounter++;
				return true;
			}
			else
			{
				return false;
			}
		}
		
};
