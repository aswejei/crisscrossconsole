#pragma once
class WinsChecker
{
	private:
		int MoveCounter;// ������� �����, ������������ ��� ���� ����� �������� ����� ��� ���������� 9 ����� ��� ���������� ������
		int CombinationsField[8][2]; // ������ � ������ ����� ��������� � �������
		//      X       0
		//i0   0-3     0-3      ��������� / 
		//i1   0-3     0-3      ��������� \
		//i2   0-3     0-3		������ 0-2
		//i3   0-3     0-3		������ 3-5
		//i4   0-3     0-3		������ 6-8
		//i5   0-3     0-3		������� 0, 3, 6
		//i6   0-3     0-3		������� 1, 4, 7
		//i7   0-3     0-3		������� 2, 5, 8
																		//6 7 8
																		//3 4 5
																		//0 1 2
		void FillFieldState(int fieldnumber, bool playerid) //��������� � ������ � ������ ����� ����� ���
		{
			int k = playerid;
			if (fieldnumber % 4 == 0)
			{
				CombinationsField[0][k]++;
			}
			if ((fieldnumber % 2 == 0 && fieldnumber%4!=0)||(fieldnumber==4))
			{
				CombinationsField[1][k]++;
			}
			switch (fieldnumber / 3)
			{
			case 0: {CombinationsField[2][k]++; break; }
			case 1: {CombinationsField[3][k]++; break; }
			case 2: {CombinationsField[4][k]++; break; }
			}
			switch (fieldnumber % 3)
			{
			case 0: {CombinationsField[5][k]++; break; }
			case 1: {CombinationsField[6][k]++; break; }
			case 2: {CombinationsField[7][k]++; break; }
			}
		}
	public:
		WinsChecker() 
		{
			MoveCounter = 0;
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 1; j++)
				{
					this->CombinationsField[i][j] = 0;
				}
			}
		}
		char CheckFieldState(int fieldnumber, bool playerid) //��������� ��������� ���� �� ������� ������ ���������/������� ��� �� ������
		{
			MoveCounter++;
			FillFieldState(fieldnumber, playerid);
			char fieldstate='N';
			for (int i = 0; i < 8; i++) 
			{
				for(int j=0; j<=1; j++)
				if (CombinationsField[i][j] == 3) 
				{
					if (j == 0) { fieldstate = 'X'; }
					else { fieldstate = '0'; }
				}
			}
			if (MoveCounter == 9 &&fieldstate!='X'&&fieldstate!='0') 
			{
				fieldstate = 'D';
			}
			return fieldstate;
		}
		
};

