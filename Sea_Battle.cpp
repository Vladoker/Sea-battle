#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <time.h>


using namespace std;

int simb(char s);
void random(char sim, int maxlive, int mas1[10][10], int not_rand[10][10]);

void manual(char sim, int maxlive, int mas1[10][10], int not_rand[10][10], char mas[10]);
void show_one(char mas[10], int mas1[10][10]);
void show_two(char mas[10], int mas1[10][10], int mas2[10][10]);

void proverka_kill_palub4(int mas0[10][10], int mas1[10][10],int live);
void proverka_kill_palub3(int mas1[10][10], int bal3[6]);
void proverka_kill_palub1(int mas0[10][10], int mas1[10][10], int x, int y);


int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	
	char mas[10] = { 'A','B','V','G','D','E','j','Z','i','K' };
	int mas1[10][10];//��
	int not_rand[10][10];//��//����� ��� ������� ������������� ��� �� ������������� ���������� 

	int mas2[10][10];//����
	int not_rand2[10][10];//����////����� ��� ������� ������������� ��� �� ������������� ���������� 


	int pustoi[10][10];//����� ��� ������ ����� ��������� 
	int pustoi2[10][10];//������� ��� �� ���� �� ������� � �� �� �����
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) //���������� ����� ����������� �������� 
		{
			mas1[i][j] = 254;
			mas2[i][j] = 254;
			pustoi[i][j] = 254;
			pustoi2[10][10] = 254;
			not_rand[i][j] = 254;
			not_rand2[i][j] = 254;
		}

	}

	
	////-------------------------------------------------------------------------
	
	int o;
	while(true)
	{
		cout<< "�������� ����� ����������� �������� : 1-������������� 2-������ ����������� :";
		cin >> o;
		if (o == 1 || o == 2) break;
	}
	
							
	if (o == 1)
	{
		random('4', 4, mas1, not_rand);
		for (int i = 0; i < 2; i++) random('3', 3, mas1, not_rand); 
		for (int i = 0; i < 3; i++) random('2', 2, mas1, not_rand);
		for (int i = 0; i < 4; i++)random('1', 1, mas1, not_rand);
	}
	else if (o == 2)
	{
		cout << "\n���� ������� ��:\n"
			<< "\n* 1 ������� - ��� �� 4 ������ \"��������������\"\n"
			<< "\n* 2 ������� - ��� �� 3 ������ \"�����������\"\n"
			<< "\n* 3 ������� - ��� �� 2 ������ \"������������\"\n"
			<< "\n* 4 ������� - ��� �� 1 �������� \"�����������\"\n"
			<< "\n��� ���������� ������� �� ����� �������� ���� ����� ������.\n";

		show_one(mas, mas1); //������� ������ ����� ����� �������������� ��� ��������� ������� 
		manual('4', 4, mas1, not_rand,mas); //������� ��� ���������� ������� ������� 
		show_one(mas, mas1); 

		for (int i = 0; i < 2; i++) 
		{
			manual('3', 3, mas1, not_rand, mas);
			show_one(mas, mas1);
		}
		for (int i = 0; i < 3; i++)
		{
			manual('2', 2, mas1, not_rand, mas);
			show_one(mas, mas1);
		}
		for (int i = 0; i < 4; i++)
		{
			manual('1', 1, mas1, not_rand, mas);
			show_one(mas, mas1);
		}


		
		

	

	}
	
	show_two(mas,mas1,pustoi); //������� ��� ������ �������� ���� ����� ����� ���� ������ ����� ���������� ���� �� �������� ����� 
	////-------------------------------------------------------------------------
	// ������������� ����� 
	random('4', 4, mas2, not_rand2);
	for (int i = 0; i < 2; i++) random('3', 3, mas2, not_rand2);
	for (int i = 0; i < 3; i++) random('2', 2, mas2, not_rand2);
	for (int i = 0; i < 4; i++)random('1', 1, mas2, not_rand2);

	////-------------------------------------------------------------------------
	
	int life_vrag = 20,life=20;
	
	char f;
	int x, y;
	while (true)
	{
		while (true)
		{
			cout << "------------------------------------------------";//
			show_one(mas, mas2);// ������������ ����� ����� ��������������� !!!!!!!!!!!!!!!!!!!!!!
			cout<<"------------------------------------------------";//

			cout << "\n�������� ���� �������� �������� B3: ";
			cin >> f >> x;
			y = simb(f); //����������� ����� � ������ ����� 
			x--; // ����� �� ���� ������������ ����� ������� �� 1 
			if (y >= 0 && y < 10 && x >= 0 && x < 10)break; 
			else cout << "\n����� �� ������� ����� !";
		}

		if (mas2[x][y] == 254) //254 ��� ������ 
		{
			pustoi[x][y] = (int)'�'; //pustoi ��� ���� ���� �� ���������� ���� �������� 
			cout << "������\n";

			int x = rand() % 10, y = rand() % 10;

			if (pustoi2[x][y] != 254)
			{
				while (pustoi2[x][y] == 254)//�������� ���� ���� ��� �� ��������
				{
					x = rand() % 10; //0-9 
					y = rand() % 10;
				}
			}
			

			if (mas1[x][y] == 254) //���� ������
			{
				pustoi2[x][y] = (int)'�';
				mas1[x][y] = (int)'�';
			}
			else
			{
				pustoi2[x][y] = (int)'X';
				mas1[x][y] = (int)'X';

			}
			
		}
		else if (mas2[x][y] == (int)'4')
		{
			pustoi[x][y] = (int)'X';
			
			// �� ������� //proverka_kill_palub4(mas2,pustoi, palub4);//��� �� ���������� ������ ��� �������� ���� �� ����� 
			life_vrag--;
			cout << "\n��������� !!!\n";
		}
		else if (mas2[x][y] == (int)'3')
		{
			
			pustoi[x][y] = (int)'X';
			
			life_vrag--;
			cout << "\n��������� !!!\n";
		}
		else if (mas2[x][y] == (int)'2')
		{

			pustoi[x][y] = (int)'X';

			life_vrag--;
			cout << "\n��������� !!!\n";
		}
		else if (mas2[x][y] == (int)'1')
		{

			pustoi[x][y] = (int)'X';
			proverka_kill_palub1(mas2, pustoi, x, y);
			life_vrag--;
			cout << "\n��������� !!!\n";
		}
		
		show_two(mas, mas1, pustoi);
		cout << "\n����� ����� " << life_vrag;

		if (life_vrag == 0 || life == 00)break;
	}

	if (life_vrag == 0)cout << "\n--------------------------\n ����������� �� �������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	else cout << "\n--------------------------\n �� ��������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";


	


	

	


	

		
	_getch();
	return 0;
}

int simb(char s)
{
	char sm = toupper(s);
	if (sm == 'A')return 0;
	else if (sm == 'B')return 1;
	else if (sm == 'V')return 2;
	else if (sm == 'G')return 3;
	else if (sm == 'D')return 4;
	else if (sm == 'E')return 5;
	else if (sm == 'J')return 6;
	else if (sm == 'Z')return 7;
	else if (sm == 'I')return 8;
	else if (sm == 'K')return 9;
	
}


void random(char sim, int maxlive, int mas1[10][10],int not_rand[10][10]) //�������������� ������������� ��������
{
	            
	int x = rand() % 10, y = rand() % 10;//0-9  

	
	int z = 1;

	while (not_rand[x][y] != 254)
	{
		x = rand() % 10;
		y = rand() % 10;
	}

	
	mas1[x][y] = (int)sim;
	not_rand[x][y] = (int)sim;
	if ( x - 1 >= 0 && y - 1 >= 0)not_rand[x - 1][y - 1] = (int)sim; //^^<<
	if ( x + 1 < 10 && y - 1 >= 0)not_rand[x + 1][y - 1] = (int)sim; //���<<
	if ( x - 1 >= 0 && y + 1 < 10)not_rand[x - 1][y + 1] = (int)sim; //^^>>
	if ( x + 1 < 10 && y + 1 < 10)not_rand[x + 1][y + 1] = (int)sim; //���>>
	


	
	if (z == 1)
	{

		if (maxlive == 4 && y - 3 >= 0 && not_rand[x][y - 1] ==254 && not_rand[x][y - 2] == 254&& not_rand[x][y - 3] == 254)
		{
			mas1[x][y - 1] = (int)sim;//<<
			mas1[x][y - 2] = (int)sim;//<<
			mas1[x][y - 3] = (int)sim;//<<	

			not_rand[x][y - 1] = (int)sim;//<<
			not_rand[x][y - 2] = (int)sim;//<<
			not_rand[x][y - 3] = (int)sim;//<<	

			if (x - 1 >= 0 && (y - 1) - 3 >= 0)not_rand[x - 1][(y - 1) - 3] = (int)sim; //^^<<
			if (x + 1 < 10 && (y - 1) - 3 >= 0)not_rand[x + 1][(y - 1) - 3] = (int)sim; //���<<
			if (x - 1 >= 0 && (y)-3 >= 0)not_rand[x - 1][(y)-3] = (int)sim;//^^
			if (x + 1 < 10 && (y)-3 >= 0)not_rand[x + 1][(y)-3] = (int)sim;//���
			if ((y - 1) - 3 >= 0)not_rand[x][(y - 1) - 3] = (int)sim;//<<
			if (x - 1 >= 0 && (y + 1)-3 < 10 && (y + 1) - 3 >=0)not_rand[x - 1][(y + 1)-3] = (int)sim; //^^>>
			if (x + 1 < 10 && (y + 1)-3 < 10 && (y + 1) - 3 >=0)not_rand[x + 1][(y + 1)-3] = (int)sim; //���>>


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���

		}
		else if (maxlive == 3 && y - 2 >= 0 && not_rand[x][y - 1] == 254 && not_rand[x][y - 2] == 254)
		{
			mas1[x][y - 1] = (int)sim;//<<
			mas1[x][y - 2] = (int)sim;//<<

			not_rand[x][y - 1] = (int)sim;//<<
			not_rand[x][y - 2] = (int)sim;//<<	

			if ( x - 1 >= 0 && (y - 1)-2 >= 0)not_rand[x - 1][(y - 1)-2] = (int)sim; //^^<<
			if (x + 1 < 10 && (y - 1)-2 >= 0)not_rand[x + 1][(y - 1) - 2] = (int)sim; //���<<
			if ( x - 1 >= 0 && (y) - 2 >= 0)not_rand[x - 1][(y)-2] = (int)sim;//^^
			if ( x + 1 < 10 && (y) - 2 >= 0)not_rand[x + 1][(y)-2] = (int)sim;//���
			if ( (y - 1)-2 >= 0)not_rand[x][(y - 1)-2] = (int)sim;//<<

			if ( y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if ( x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if ( x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else if (maxlive == 2 && y - 1 >= 0 && not_rand[x][y - 1] == 254)
		{
			mas1[x][y - 1] = (int)sim;//<<



			not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0 && (y - 1) - 1 >= 0)not_rand[x - 1][(y - 1) - 1] = (int)sim; //^^<<
			if (x + 1 < 10 && (y - 1) - 1 >= 0)not_rand[x + 1][(y - 1) - 1] = (int)sim; //���<<
			if ((y - 1) - 1 >= 0)not_rand[x][(y - 1) - 1] = (int)sim;//<<
			if (x - 1 >= 0 && (y + 1) - 1 < 10 && (y + 1) - 1 >= 0)not_rand[x - 1][(y + 1) - 1] = (int)sim; //^^>>
			if (x + 1 < 10 && (y + 1) - 1 < 10 && (y + 1) - 1 >= 0)not_rand[x + 1][(y + 1) - 1] = (int)sim; //���>>


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			
			
		}
		else if (maxlive == 1)
		{
			if ( y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if ( y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if ( x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if ( x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else
		{
			z = 2;
		}
	}

	if (z == 2)
	{

		if (maxlive == 4 && y + 3 < 10 && not_rand[x][y + 1] ==254 && not_rand[x][y + 2] == 254 && not_rand[x][y + 3] == 254)
		{
			mas1[x][y + 1] = (int)sim;//>>
			mas1[x][y + 2] = (int)sim;//>>
			mas1[x][y + 3] = (int)sim;//>>


			not_rand[x][y + 1] = (int)sim;//>>
			not_rand[x][y + 2] = (int)sim;//>>
			not_rand[x][y + 3] = (int)sim;//>>	

			if (x - 1 >= 0 && (y - 1) + 3 >= 0 && (y - 1) + 3 < 10)not_rand[x - 1][(y - 1) +3] = (int)sim; //^^<<
			if (x + 1 < 10 && (y - 1) + 3 >= 0 && (y - 1) + 3 < 10 )not_rand[x + 1][(y - 1) + 3] = (int)sim; //���<<
			if (x - 1 >= 0 && (y)+3 >= 0 && (y)+3 < 10 )not_rand[x - 1][(y)+3] = (int)sim;//^^
			if (x + 1 < 10 && (y)+3 >= 0 && (y)+3 < 10)not_rand[x + 1][(y)+3] = (int)sim;//���
			if ((y + 1) + 3 < 10)not_rand[x][(y + 1)+3] = (int)sim;//>>
			if (x - 1 >= 0 && (y + 1) + 3 < 10)not_rand[x - 1][(y + 1) + 3] = (int)sim; //^^>>
			if (x + 1 < 10 && (y + 1) + 3 < 10)not_rand[x + 1][(y + 1) + 3] = (int)sim; //���>>


			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���

		}
		else if (maxlive == 3 &&  y + 2 < 10 && not_rand[x][y + 1] == 254 && not_rand[x][y + 2] == 254 )
		{
			mas1[x][y + 1] = (int)sim;//>>
			mas1[x][y + 2] = (int)sim;//>>


			not_rand[x][y + 1] = (int)sim;//>>
			not_rand[x][y + 2] = (int)sim;//>>

			
			if (x - 1 >= 0 && (y)+2 >= 0 && (y)+2 < 10)not_rand[x - 1][(y)+2] = (int)sim;//^^
			if (x + 1 < 10 && (y)+2 >= 0 && (y)+2 < 10)not_rand[x + 1][(y)+2] = (int)sim;//���
			if ((y + 1) + 2 < 10)not_rand[x][(y + 1) + 2] = (int)sim;//>>
			if (x - 1 >= 0 && (y + 1) + 2 < 10)not_rand[x - 1][(y + 1) + 2] = (int)sim; //^^>>
			if (x + 1 < 10 && (y + 1) + 2 < 10)not_rand[x + 1][(y + 1) + 2] = (int)sim; //���>>


			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else if (maxlive == 2 &&  y + 1 < 10 && not_rand[x][y + 1] == 254)
		{
			mas1[x][y + 1] = (int)sim;//>>



			not_rand[x][y + 1] = (int)sim;//>>
			

			if (x - 1 >= 0 && (y - 1) + 1 >= 0 && (y - 1) + 1 < 10)not_rand[x - 1][(y - 1) + 1] = (int)sim; //^^<<
			if (x + 1 < 10 && (y - 1) + 1 >= 0 && (y - 1) + 1 < 10)not_rand[x + 1][(y - 1) + 1] = (int)sim; //���<<
			if ((y + 1) + 1 < 10)not_rand[x][(y + 1) + 1] = (int)sim;//>>
			if (x - 1 >= 0 && (y + 1) + 1 < 10)not_rand[x - 1][(y + 1) + 1] = (int)sim; //^^>>
			if (x + 1 < 10 && (y + 1) + 1 < 10)not_rand[x + 1][(y + 1) + 1] = (int)sim; //���>>


			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<

		}
		else if (maxlive == 1)
		{
			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else
		{
			z = 3;
		}
	}

	if (z == 3)
	{

		if (maxlive==4 && x - 3 >= 0 && not_rand[x-1][y] == 254 && not_rand[x-2][y] == 254 && not_rand[x-3][y] == 254)
		{
			mas1[x - 1][y] = (int)sim;//^^
			mas1[x - 2][y] = (int)sim;//^^
			mas1[x - 3][y] = (int)sim;//^^


			not_rand[x-1][y] = (int)sim;//^^
			not_rand[x-2][y] = (int)sim;//^^
			not_rand[x-3][y] = (int)sim;//^^	

			if ((x - 1)-3 >= 0 && y - 1 >= 0)not_rand[(x - 1)-3][y - 1] = (int)sim; //^^<<
			if ((x + 1)-3 < 10 && (x + 1) - 3 >=0 && y - 1 >= 0)not_rand[(x + 1)-3][y - 1] = (int)sim; //���<<
			if ((x - 1)-3 >= 0)not_rand[(x - 1)-3][y] = (int)sim;//^^
			if ((x) -3 >= 0 && y - 1 >= 0)not_rand[(x)-3][y - 1] = (int)sim;//<<
			if ((x)-3>=0 && y + 1 < 10)not_rand[(x)-3][y + 1] = (int)sim;//>>
			if ((x - 1)-3 >= 0 && y + 1 < 10)not_rand[(x - 1)-3][y + 1] = (int)sim; //^^>>
			if ((x + 1)-3 < 10 && (x + 1) - 3 >=0 && y + 1 < 10)not_rand[(x + 1)-3][y + 1] = (int)sim; //���>>


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
	    else if (maxlive == 3 && x - 2 >= 0 && not_rand[x - 1][y] == 254 && not_rand[x - 2][y] == 254)
		{
			mas1[x - 1][y] = (int)sim;//^^
			mas1[x - 2][y] = (int)sim;//^^

			not_rand[x - 1][y] = (int)sim;//^^
			not_rand[x - 2][y] = (int)sim;//^^	

			if ((x - 1) - 2 >= 0 && y - 1 >= 0)not_rand[(x - 1) - 2][y - 1] = (int)sim; //^^<<
			if ((x - 1) - 2 >= 0)not_rand[(x - 1) - 2][y] = (int)sim;//^^
			if ((x)-2 >= 0 && y - 1 >= 0)not_rand[(x)-2][y - 1] = (int)sim;//<<
			if ((x)-2 >= 0 && y + 1 < 10)not_rand[(x)-2][y + 1] = (int)sim;//>>
			if ((x - 1) - 2 >= 0 && y + 1 < 10)not_rand[(x - 1) - 2][y + 1] = (int)sim; //^^>>
			


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
	    else if (maxlive == 2 && x - 1 >= 0 && not_rand[x - 1][y] == 254)
		{
			mas1[x - 1][y] = (int)sim;//^^

			not_rand[x - 1][y] = (int)sim;//^^
				

			if ((x - 1) - 1 >= 0 && y - 1 >= 0)not_rand[(x - 1) - 1][y - 1] = (int)sim; //^^<<
			if ((x - 1) - 1 >= 0)not_rand[(x - 1) - 1][y] = (int)sim;//^^
			if ((x - 1) - 1 >= 0 && y + 1 < 10)not_rand[(x - 1) - 1][y + 1] = (int)sim; //^^>>


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else if (maxlive == 1)
		{
			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else
		{
			z = 4;
		}
	}

	if (z == 4)
	{

		if (maxlive==4 && x+3 < 10 && not_rand[x + 1][y] == 254 && not_rand[x + 2][y] == 254 && not_rand[x + 3][y] == 254)
		{
			mas1[x + 1][y] = (int)sim;//����
			mas1[x + 2][y] = (int)sim;//����
			mas1[x + 3][y] = (int)sim;//����

			not_rand[x + 1][y] = (int)sim;//����
			not_rand[x + 2][y] = (int)sim;//����
			not_rand[x + 3][y] = (int)sim;//����

			if ((x - 1) + 3 >= 0 && (x - 1) + 3 < 10 && y - 1 >= 0)not_rand[(x - 1) + 3][y - 1] = (int)sim; //^^<<
			if ((x + 1) + 3 < 10 && y - 1 >= 0)not_rand[(x + 1) + 3][y - 1] = (int)sim; //���<<
			if ((x)+3 < 10 && y - 1 >= 0)not_rand[(x)+3][y - 1] = (int)sim;//<<
			if ((x)+3 < 10 && y + 1 < 10)not_rand[(x)+3][y + 1] = (int)sim;//>>
			if ((x - 1) + 3 >= 0 && (x - 1) + 3 < 10 && y + 1 < 10)not_rand[(x - 1) + 3][y + 1] = (int)sim; //^^>>
			if ((x + 1) + 3 < 10 && y + 1 < 10)not_rand[(x + 1) + 3][y + 1] = (int)sim; //���>>
			if ((x + 1)+3 < 10)not_rand[(x + 1)+3][y] = (int)sim;//���


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			
			
		}
		else if (maxlive == 3 && x + 2 < 10 && not_rand[x + 1][y] == 254 && not_rand[x + 2][y] == 254)
		{
			mas1[x + 1][y] = (int)sim;//����
			mas1[x + 2][y] = (int)sim;//����


			not_rand[x + 1][y] = (int)sim;//����
			not_rand[x + 2][y] = (int)sim;//����
			

			
			if ((x + 1) + 2 < 10 && y - 1 >= 0)not_rand[(x + 1) + 2][y - 1] = (int)sim; //���<<
			if ((x)+2 < 10 && y - 1 >= 0)not_rand[(x)+2][y - 1] = (int)sim;//<<
			if ((x)+2 < 10 && y + 1 < 10)not_rand[(x)+2][y + 1] = (int)sim;//>>
			if ((x + 1) + 2 < 10 && y + 1 < 10)not_rand[(x + 1) + 2][y + 1] = (int)sim; //���>>
			if ((x + 1) + 2 < 10)not_rand[(x + 1) + 2][y] = (int)sim;//���


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
		}
		else if (maxlive == 2 && x + 1 < 10 && not_rand[x + 1][y] == 254)
		{
			mas1[x + 1][y] = (int)sim;//����

			not_rand[x + 1][y] = (int)sim;//����
			

			if ((x + 1) + 1 < 10 && y - 1 >= 0)not_rand[(x + 1) + 1][y - 1] = (int)sim; //���<<
			
			if ((x + 1) + 1 < 10 && y + 1 < 10)not_rand[(x + 1) + 1][y + 1] = (int)sim; //���>>
			if ((x + 1) + 1 < 10)not_rand[(x + 1) + 1][y] = (int)sim;//���


			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
		}
		else if (maxlive == 1)
		{
			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
		else
		{
			z = 1;
		}
	
	}

}


void manual(char sim, int maxlive, int mas1[10][10], int not_rand[10][10],char mas[10]) //���������� �������� �������
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x,y;
	char s;
	while (true)
	{
		cout << "\n�������� ��������� ������ ���������� "<<maxlive<<"-�������� �������� B5= ";
		cin >> s >> x;
		 y = simb(s);
		 x--;
		if (y >= 0 && y < 10 && x >= 0 && x < 10 && not_rand[x][y] == 254)break;
		else cout << "\n������ ��� ����� �� ������� �����!!!!!!\n";
	}
	

	mas1[x][y] = (int)sim;
	not_rand[x][y] = (int)sim;
	if (x - 1 >= 0 && y - 1 >= 0)not_rand[x - 1][y - 1] = (int)sim; //^^<<
	if (x + 1 < 10 && y - 1 >= 0)not_rand[x + 1][y - 1] = (int)sim; //���<<
	if (x - 1 >= 0 && y + 1 < 10)not_rand[x - 1][y + 1] = (int)sim; //^^>>
	if (x + 1 < 10 && y + 1 < 10)not_rand[x + 1][y + 1] = (int)sim; //���>>


	int z=1;
	while (maxlive!=1)
	{
		cout << "\n�������� �����������:\n4:Left<<\n6:Right>>\n8:Up^^\n2:Down\n�����:";
		cin >> z;
		if (z == 4 || z == 6 || z == 8 || z == 2)break;

	}




	
	bool b=true;
	

	while (b)
	{
		if (z == 4)
		{

			if (maxlive == 4 && y - 3 >= 0 && not_rand[x][y - 1] == 254 && not_rand[x][y - 2] == 254 && not_rand[x][y - 3] == 254)
			{
				b = false;
				mas1[x][y - 1] = (int)sim;//<<
				mas1[x][y - 2] = (int)sim;//<<
				mas1[x][y - 3] = (int)sim;//<<	

				not_rand[x][y - 1] = (int)sim;//<<
				not_rand[x][y - 2] = (int)sim;//<<
				not_rand[x][y - 3] = (int)sim;//<<	

				if (x - 1 >= 0 && (y - 1) - 3 >= 0)not_rand[x - 1][(y - 1) - 3] = (int)sim; //^^<<
				if (x + 1 < 10 && (y - 1) - 3 >= 0)not_rand[x + 1][(y - 1) - 3] = (int)sim; //���<<
				if (x - 1 >= 0 && (y)-3 >= 0)not_rand[x - 1][(y)-3] = (int)sim;//^^
				if (x + 1 < 10 && (y)-3 >= 0)not_rand[x + 1][(y)-3] = (int)sim;//���
				if ((y - 1) - 3 >= 0)not_rand[x][(y - 1) - 3] = (int)sim;//<<
				if (x - 1 >= 0 && (y + 1) - 3 < 10 && (y + 1) - 3 >= 0)not_rand[x - 1][(y + 1) - 3] = (int)sim; //^^>>
				if (x + 1 < 10 && (y + 1) - 3 < 10 && (y + 1) - 3 >= 0)not_rand[x + 1][(y + 1) - 3] = (int)sim; //���>>


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���

			}
			else if (maxlive == 3 && y - 2 >= 0 && not_rand[x][y - 1] == 254 && not_rand[x][y - 2] == 254)
			{
				b = false;
				mas1[x][y - 1] = (int)sim;//<<
				mas1[x][y - 2] = (int)sim;//<<

				not_rand[x][y - 1] = (int)sim;//<<
				not_rand[x][y - 2] = (int)sim;//<<	

				if (x - 1 >= 0 && (y - 1) - 2 >= 0)not_rand[x - 1][(y - 1) - 2] = (int)sim; //^^<<
				if (x + 1 < 10 && (y - 1) - 2 >= 0)not_rand[x + 1][(y - 1) - 2] = (int)sim; //���<<
				if (x - 1 >= 0 && (y)-2 >= 0)not_rand[x - 1][(y)-2] = (int)sim;//^^
				if (x + 1 < 10 && (y)-2 >= 0)not_rand[x + 1][(y)-2] = (int)sim;//���
				if ((y - 1) - 2 >= 0)not_rand[x][(y - 1) - 2] = (int)sim;//<<

				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
			}
			else if (maxlive == 2 && y - 1 >= 0 && not_rand[x][y - 1] == 254)
			{
				b = false;
				mas1[x][y - 1] = (int)sim;//<<



				not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0 && (y - 1) - 1 >= 0)not_rand[x - 1][(y - 1) - 1] = (int)sim; //^^<<
				if (x + 1 < 10 && (y - 1) - 1 >= 0)not_rand[x + 1][(y - 1) - 1] = (int)sim; //���<<
				if ((y - 1) - 1 >= 0)not_rand[x][(y - 1) - 1] = (int)sim;//<<
				if (x - 1 >= 0 && (y + 1) - 1 < 10 && (y + 1) - 1 >= 0)not_rand[x - 1][(y + 1) - 1] = (int)sim; //^^>>
				if (x + 1 < 10 && (y + 1) - 1 < 10 && (y + 1) - 1 >= 0)not_rand[x + 1][(y + 1) - 1] = (int)sim; //���>>


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>


			}
			else
			{
				while (true)
				{
					cout << "\n������ �������� ������ �����������:\n4:Left<<\n6:Right>>\n8:Up^^\n2:Down\n�����:";
					cin >> z;
					if (z == 4 || z == 6 || z == 8 || z == 2)break;
				}
			}
		}

		if (z == 6)
		{

			if (maxlive == 4 && y + 3 < 10 && not_rand[x][y + 1] == 254 && not_rand[x][y + 2] == 254 && not_rand[x][y + 3] == 254)
			{
				b = false;
				mas1[x][y + 1] = (int)sim;//>>
				mas1[x][y + 2] = (int)sim;//>>
				mas1[x][y + 3] = (int)sim;//>>


				not_rand[x][y + 1] = (int)sim;//>>
				not_rand[x][y + 2] = (int)sim;//>>
				not_rand[x][y + 3] = (int)sim;//>>	

				if (x - 1 >= 0 && (y - 1) + 3 >= 0 && (y - 1) + 3 < 10)not_rand[x - 1][(y - 1) + 3] = (int)sim; //^^<<
				if (x + 1 < 10 && (y - 1) + 3 >= 0 && (y - 1) + 3 < 10)not_rand[x + 1][(y - 1) + 3] = (int)sim; //���<<
				if (x - 1 >= 0 && (y)+3 >= 0 && (y)+3 < 10)not_rand[x - 1][(y)+3] = (int)sim;//^^
				if (x + 1 < 10 && (y)+3 >= 0 && (y)+3 < 10)not_rand[x + 1][(y)+3] = (int)sim;//���
				if ((y + 1) + 3 < 10)not_rand[x][(y + 1) + 3] = (int)sim;//>>
				if (x - 1 >= 0 && (y + 1) + 3 < 10)not_rand[x - 1][(y + 1) + 3] = (int)sim; //^^>>
				if (x + 1 < 10 && (y + 1) + 3 < 10)not_rand[x + 1][(y + 1) + 3] = (int)sim; //���>>


				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���

			}
			else if (maxlive == 3 && y + 2 < 10 && not_rand[x][y + 1] == 254 && not_rand[x][y + 2] == 254)
			{
				b = false;
				mas1[x][y + 1] = (int)sim;//>>
				mas1[x][y + 2] = (int)sim;//>>


				not_rand[x][y + 1] = (int)sim;//>>
				not_rand[x][y + 2] = (int)sim;//>>


				if (x - 1 >= 0 && (y)+2 >= 0 && (y)+2 < 10)not_rand[x - 1][(y)+2] = (int)sim;//^^
				if (x + 1 < 10 && (y)+2 >= 0 && (y)+2 < 10)not_rand[x + 1][(y)+2] = (int)sim;//���
				if ((y + 1) + 2 < 10)not_rand[x][(y + 1) + 2] = (int)sim;//>>
				if (x - 1 >= 0 && (y + 1) + 2 < 10)not_rand[x - 1][(y + 1) + 2] = (int)sim; //^^>>
				if (x + 1 < 10 && (y + 1) + 2 < 10)not_rand[x + 1][(y + 1) + 2] = (int)sim; //���>>


				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
			}
			else if (maxlive == 2 && y + 1 < 10 && not_rand[x][y + 1] == 254)
			{
				b = false;
				mas1[x][y + 1] = (int)sim;//>>



				not_rand[x][y + 1] = (int)sim;//>>


				if (x - 1 >= 0 && (y - 1) + 1 >= 0 && (y - 1) + 1 < 10)not_rand[x - 1][(y - 1) + 1] = (int)sim; //^^<<
				if (x + 1 < 10 && (y - 1) + 1 >= 0 && (y - 1) + 1 < 10)not_rand[x + 1][(y - 1) + 1] = (int)sim; //���<<
				if ((y + 1) + 1 < 10)not_rand[x][(y + 1) + 1] = (int)sim;//>>
				if (x - 1 >= 0 && (y + 1) + 1 < 10)not_rand[x - 1][(y + 1) + 1] = (int)sim; //^^>>
				if (x + 1 < 10 && (y + 1) + 1 < 10)not_rand[x + 1][(y + 1) + 1] = (int)sim; //���>>


				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<

			}
			else
			{
				while (true)
				{
					cout << "\n������ �������� ������ �����������:\n4:Left<<\n6:Right>>\n8:Up^^\n2:Down\n�����:";
					cin >> z;
					if (z == 4 || z == 6 || z == 8 || z == 2)break;
				}
			}
		}

		if (z == 8)
		{

			if (maxlive == 4 && x - 3 >= 0 && not_rand[x - 1][y] == 254 && not_rand[x - 2][y] == 254 && not_rand[x - 3][y] == 254)
			{
				b = false;
				mas1[x - 1][y] = (int)sim;//^^
				mas1[x - 2][y] = (int)sim;//^^
				mas1[x - 3][y] = (int)sim;//^^


				not_rand[x - 1][y] = (int)sim;//^^
				not_rand[x - 2][y] = (int)sim;//^^
				not_rand[x - 3][y] = (int)sim;//^^	

				if ((x - 1) - 3 >= 0 && y - 1 >= 0)not_rand[(x - 1) - 3][y - 1] = (int)sim; //^^<<
				if ((x + 1) - 3 < 10 && (x + 1) - 3 >= 0 && y - 1 >= 0)not_rand[(x + 1) - 3][y - 1] = (int)sim; //���<<
				if ((x - 1) - 3 >= 0)not_rand[(x - 1) - 3][y] = (int)sim;//^^
				if ((x)-3 >= 0 && y - 1 >= 0)not_rand[(x)-3][y - 1] = (int)sim;//<<
				if ((x)-3 >= 0 && y + 1 < 10)not_rand[(x)-3][y + 1] = (int)sim;//>>
				if ((x - 1) - 3 >= 0 && y + 1 < 10)not_rand[(x - 1) - 3][y + 1] = (int)sim; //^^>>
				if ((x + 1) - 3 < 10 && (x + 1) - 3 >= 0 && y + 1 < 10)not_rand[(x + 1) - 3][y + 1] = (int)sim; //���>>


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
			}
			else if (maxlive == 3 && x - 2 >= 0 && not_rand[x - 1][y] == 254 && not_rand[x - 2][y] == 254)
			{
				b = false;
				mas1[x - 1][y] = (int)sim;//^^
				mas1[x - 2][y] = (int)sim;//^^

				not_rand[x - 1][y] = (int)sim;//^^
				not_rand[x - 2][y] = (int)sim;//^^	

				if ((x - 1) - 2 >= 0 && y - 1 >= 0)not_rand[(x - 1) - 2][y - 1] = (int)sim; //^^<<
				if ((x - 1) - 2 >= 0)not_rand[(x - 1) - 2][y] = (int)sim;//^^
				if ((x)-2 >= 0 && y - 1 >= 0)not_rand[(x)-2][y - 1] = (int)sim;//<<
				if ((x)-2 >= 0 && y + 1 < 10)not_rand[(x)-2][y + 1] = (int)sim;//>>
				if ((x - 1) - 2 >= 0 && y + 1 < 10)not_rand[(x - 1) - 2][y + 1] = (int)sim; //^^>>



				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
			}
			else if (maxlive == 2 && x - 1 >= 0 && not_rand[x - 1][y] == 254)
			{
				b = false;
				mas1[x - 1][y] = (int)sim;//^^

				not_rand[x - 1][y] = (int)sim;//^^


				if ((x - 1) - 1 >= 0 && y - 1 >= 0)not_rand[(x - 1) - 1][y - 1] = (int)sim; //^^<<
				if ((x - 1) - 1 >= 0)not_rand[(x - 1) - 1][y] = (int)sim;//^^
				if ((x - 1) - 1 >= 0 && y + 1 < 10)not_rand[(x - 1) - 1][y + 1] = (int)sim; //^^>>


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
			}
			else
			{
				while (true)
				{
					cout << "\n������ �������� ������ �����������::\n4:Left<<\n6:Right>>\n8:Up^^\n2:Down\n�����:";
					cin >> z;
					if (z == 4 || z == 6 || z == 8 || z == 2)break;
				}
			}
		}

		if (z == 2)
		{

			if (maxlive == 4 && x + 3 < 10 && not_rand[x + 1][y] == 254 && not_rand[x + 2][y] == 254 && not_rand[x + 3][y] == 254)
			{
				b = false;
				mas1[x + 1][y] = (int)sim;//����
				mas1[x + 2][y] = (int)sim;//����
				mas1[x + 3][y] = (int)sim;//����

				not_rand[x + 1][y] = (int)sim;//����
				not_rand[x + 2][y] = (int)sim;//����
				not_rand[x + 3][y] = (int)sim;//����

				if ((x - 1) + 3 >= 0 && (x - 1) + 3 < 10 && y - 1 >= 0)not_rand[(x - 1) + 3][y - 1] = (int)sim; //^^<<
				if ((x + 1) + 3 < 10 && y - 1 >= 0)not_rand[(x + 1) + 3][y - 1] = (int)sim; //���<<
				if ((x)+3 < 10 && y - 1 >= 0)not_rand[(x)+3][y - 1] = (int)sim;//<<
				if ((x)+3 < 10 && y + 1 < 10)not_rand[(x)+3][y + 1] = (int)sim;//>>
				if ((x - 1) + 3 >= 0 && (x - 1) + 3 < 10 && y + 1 < 10)not_rand[(x - 1) + 3][y + 1] = (int)sim; //^^>>
				if ((x + 1) + 3 < 10 && y + 1 < 10)not_rand[(x + 1) + 3][y + 1] = (int)sim; //���>>
				if ((x + 1) + 3 < 10)not_rand[(x + 1) + 3][y] = (int)sim;//���


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^


			}
			else if (maxlive == 3 && x + 2 < 10 && not_rand[x + 1][y] == 254 && not_rand[x + 2][y] == 254)
			{
				b = false;
				mas1[x + 1][y] = (int)sim;//����
				mas1[x + 2][y] = (int)sim;//����


				not_rand[x + 1][y] = (int)sim;//����
				not_rand[x + 2][y] = (int)sim;//����



				if ((x + 1) + 2 < 10 && y - 1 >= 0)not_rand[(x + 1) + 2][y - 1] = (int)sim; //���<<
				if ((x)+2 < 10 && y - 1 >= 0)not_rand[(x)+2][y - 1] = (int)sim;//<<
				if ((x)+2 < 10 && y + 1 < 10)not_rand[(x)+2][y + 1] = (int)sim;//>>
				if ((x + 1) + 2 < 10 && y + 1 < 10)not_rand[(x + 1) + 2][y + 1] = (int)sim; //���>>
				if ((x + 1) + 2 < 10)not_rand[(x + 1) + 2][y] = (int)sim;//���


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			}
			else if (maxlive == 2 && x + 1 < 10 && not_rand[x + 1][y] == 254)
			{
				b = false;
				mas1[x + 1][y] = (int)sim;//����

				not_rand[x + 1][y] = (int)sim;//����


				if ((x + 1) + 1 < 10 && y - 1 >= 0)not_rand[(x + 1) + 1][y - 1] = (int)sim; //���<<

				if ((x + 1) + 1 < 10 && y + 1 < 10)not_rand[(x + 1) + 1][y + 1] = (int)sim; //���>>
				if ((x + 1) + 1 < 10)not_rand[(x + 1) + 1][y] = (int)sim;//���


				if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
				if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
				if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			}
			else
			{
				while (true)
				{
					cout << "\n������ �������� ������ �����������::\n4:Left<<\n6:Right>>\n8:Up^^\n2:Down\n�����:";
					cin >> z;
					if (z == 4 || z == 6 || z == 8 || z == 2)break;
				}
			}

		}

		if (z == 1)
		{
			b = false;
			if (y + 1 < 10)not_rand[x][y + 1] = (int)sim;//>>
			if (y - 1 >= 0)not_rand[x][y - 1] = (int)sim;//<<
			if (x - 1 >= 0)not_rand[x - 1][y] = (int)sim;//^^
			if (x + 1 < 10)not_rand[x + 1][y] = (int)sim;//���
		}
	}



}

void show_one(char mas[10],int mas1[10][10]) //������� ���� ����� (�����)
{
	//SetConsoleOutputCP(866);
	SetConsoleCP(437);
	SetConsoleOutputCP(437);



	cout << "\n\n  ";

	for (int i = 0; i < 10; i++)

		cout << " " << mas[i];

	cout << "\n_______________________\n";


	int m = 0;


	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << ++m;
		for (int l = 0; l < 10; l++)
		{
			cout << setw(2) << (char)mas1[i][l];
		}
		cout << endl;
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
} 

void show_two(char mas[10], int mas1[10][10], int mas2[10][10])//������� ��� ������ �������� ���� �����
{
	//SetConsoleOutputCP(866);
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	cout << "\n  ";

	for (int i = 0; i < 10; i++)

	cout << " " << mas[i];

	cout << "           ";

	for (int i = 0; i < 10; i++)
	cout << " " << mas[i];



	cout << "\n________________________________________________________\n";


	int m = 0, m2 = 0;


	for (int i = 0; i < 10; i++)
	{
	cout << setw(2) << ++m;
	for (int l = 0; l < 10; l++)
	cout << setw(2) << (char)mas1[i][l];
	cout << "         " << setw(2) << ++m2;
	for (int j = 0; j < 10; j++)
	{
	cout << setw(2) << (char)mas2[i][j];

	}
	cout << endl;
	}

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}


void proverka_kill_palub4(int mas0[10][10],int mas1[10][10],int live)// ������ ������� '�'
{
	
	if (live==0)//�������� ��������������� <<
	{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					if (mas0[x][y] == (int)'4')
					{
						if (x - 1 >= 0 && (y - 1) >= 0)mas1[x - 1][(y - 1)] = (int)'�'; //^^<<
						if (x + 1 < 10 && (y - 1) >= 0)mas1[x + 1][(y - 1)] = (int)'�'; //���<<
						if (x - 1 >= 0 && (y + 1) < 10 && (y + 1) >= 0)mas1[x - 1][(y + 1)] = (int)'�'; //^^>>
						if (x + 1 < 10 && (y + 1) < 10 && (y + 1) >= 0)mas1[x + 1][(y + 1)] = (int)'�'; //���>>
					}
				}
			}
	}


}

void proverka_kill_palub3(int mas1[10][10],int bal3[6])// ������ ������� ������� ������� '�'
{
	for (int m = 0; m < 6; m++)
	{
		
				if (mas1[*bal3][*bal3+1] != 254 && mas1[*bal3+2][*bal3+3] != 254 && mas1[*bal3+4][*bal3+5] != 254)//254=0
				{
					if ((bal3[m]) - 1 >= 0 && (bal3[m + 1]) - 1 >= 0)mas1[(bal3[m])-1][(bal3[m + 1])-1] = (int)'�'; //^^<<
					if ((bal3[m]) + 1 && (bal3[m + 1]) - 1 >= 0)mas1[(bal3[m])+1][(bal3[m + 1])-1] = (int)'�'; //���<<
					if ((bal3[m]) - 1 >= 0 && (bal3[m + 1]) + 1 < 10 && (bal3[m + 1]) + 1 >= 0)mas1[(bal3[m])-1][(bal3[m + 1])+1] = (int)'�'; //^^>>
					if ((bal3[m]) + 1 < 10 && (bal3[m + 1]) + 1 < 10 && (bal3[m + 1]) + 1 >= 0)mas1[(bal3[m])+1][(bal3[m + 1])+1] = (int)'�'; //���>>
				}
				else break;
			
	}

	
}

void proverka_kill_palub1(int mas0[10][10], int mas1[10][10], int x, int y)// ������ ������� '�'
{
	if (mas0[x][y] != 254 && mas0[x][y - 1] == 254 && mas0[x][y + 1] == 254 && mas0[x - 1][y] == 254 && mas0[x + 1][y] == 254)//�������� ������������� �� kill
	{
		if (y - 1 >= 0)mas1[x][y - 1] = (int)'�';//<<
		if (y + 1 < 10)mas1[x][y + 1] = (int)'�';//>>
		if (x - 1 >= 0)mas1[x - 1][y] = (int)'�';//^^
		if (x + 1 < 10)mas1[x + 1][y] = (int)'�';//niz

		if (x - 1 >= 0 && y - 1 >= 0)mas1[x - 1][y - 1] = (int)'�'; //^^<<
		if (x + 1 < 10 && y - 1 >= 0)mas1[x + 1][y - 1] = (int)'�'; //���<<
		if (x - 1 >= 0 && y + 1 < 10)mas1[x - 1][y + 1] = (int)'�'; //^^>>
		if (x + 1 < 10 && y + 1 < 10)mas1[x + 1][y + 1] = (int)'�'; //���>>
	}
}

