#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdio.h>

using namespace std;

string owner_user , owner_pass ;
string iuser , user , user2 , ipass , pass , pass2 ;
string item_name , item_type ;
string string_choice , y1("Y") , y2("y") , n1("N") , n2("n");

int choice , price , quantity , total;

int owner_login();
int employee_login();
int sign_up();
int owner_menu();
int employee_menu();
int list_sales();
int add_item();
int sell_item();
int list_of_items();

int main()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                      WELCOME                                   " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] LOG-IN AS OWNER                                                   " << endl;
	cout << "          [2] LOG-IN AS AN EMPLOYEE                                             " << endl;
	cout << "          [3] SIGN UP AN EMPLOYEE ACCOUNT                                       " << endl;
	cout << "          [4] EXIT PROGRAM                                                      " << endl;	
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR CHOICE : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			owner_login();
			break;
		case 2:
			employee_login();
			break;
		case 3:
			sign_up();
			break;
		case 4:
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			cout << "      ERROR   " << endl;
			Sleep(3000);
			return main();
			break;
	}
}

int owner_login()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  OWNER LOGIN                                   " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  OWNER USERNAME : ";
	cin >> iuser;
	cout << "                  OWNER PASSWORD : ";
	cin >> ipass;
	ifstream owner;
	owner.open( "ownerinfo.txt");
	owner >> owner_user >> owner_pass ;
	owner.close();
	if ( iuser == owner_user && ipass == owner_pass )
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                      SUCCESSFULLY LOGGED IN AS OWNER                           " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(1500);
		system("cls");
		owner_menu();
		
	}
	else
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                       INVALID OWNER USERNAME OR PASSWORD                       " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(3000);
		system("cls");
		return main();
	}
	
}

int employee_login()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  LOG IN AS EMPLOYEE                            " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                      EMPLOYEE'S USERNAME : ";
	cin >> iuser ;
	cout << "                      EMPLOYEE'S PASSWORD : ";
	cin >> ipass ;
	ifstream employee_login;
	employee_login.open( iuser.c_str() );
	employee_login >> user >> pass;
	employee_login.close();
	if ( iuser == user && ipass == pass )
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                       SUCCESSFULLY LOGGED IN AS AN EMPLOYEE                    " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(1500);
		system("cls");
		employee_menu();
		
	}
	else
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                            INVALID USERNAME OR PASSWORD                        " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		return main();
	}
	
}

int sign_up()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                             REGISTER AN EMPLOYEE ACCOUNT                       " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                     USERNAME : " ;
	cin >> iuser;
	cout << "                     PASSWORD : " ;
	cin >> ipass;
	ifstream test;
	test.open( iuser.c_str() );
	if ( !( test.fail() ) )
	{
		test.close();
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                              USERNAME ALREADY TAKEN                            " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(1500);
		system("cls");
		return main();
	}
	test.close();
	ofstream create;
	create.open( iuser.c_str() );
	create << iuser << ' ' << ipass ;
	create.close();
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                            ACCOUNT SUCCESSFULLY CREATED!                       " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(2000);
	system("cls");
	return main();
}

int owner_menu()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   OWNER MENU                                   " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  [1] LIST OF SALES                                             " << endl;
	cout << "                  [2] ADD ITEM TO SHOP                                          " << endl;
	cout << "                  [3] LOG OUT AS OWNER                                          " << endl;
	cout << "                  [4] EXIT PROGRAM                                              " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  YOUR CHOICE : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			list_sales();
			break;
		case 2:
			add_item();
			break;
		case 3:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "                                LOGGING OUT AS OWNER                            " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(1500);
			system("cls");
			return main();
		case 4:
			system("pause");
			return 0;
			break;
		default: 
			system("cls");
			cout << "               ERROR  " << endl;
			Sleep(500);
			return owner_menu();		
	}
}

int list_sales()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   LIST OF SALES                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	ifstream list_of_sales;
	list_of_sales.open( "saleslist.txt");
	while ( !list_of_sales.eof() )
	{
		list_of_sales >> item_name >> item_type >> price >> quantity >> total;
		cout << "           ITEM NAME : " << item_name << endl;
		cout << "           ITEM TYPE : " << item_type << endl;
		cout << "           PRICE PER ITEM : " << price << endl;
		cout << "           QUANTITY : " << quantity << endl;
		cout << "           TOTAL AMOUNT : " << total << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}
	list_of_sales.close();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                      [1] GO BACK TO OWNER MENU                                 " << endl;
	cout << "                      [2] EXIT PROGRAM                                          " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                      YOUR CHOICE : ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			return owner_menu();
			break;
		case 2:
			system("pause");
			return 0;
			break;
		default:
			return list_sales();
			break;
	}
}

int add_item()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                               ADDING ITEM TO SHOP                              " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                        ITEM NAME : " ;
	cin >> item_name ;
	cout << "                        ITEM TYPE : " ;
	cin >> item_type ;
	cout << "                        ITEM PRICE : " ;
	cin >> price;
	ifstream test;
	test.open( item_name.c_str() );
	if ( !( test.fail() ) )
	{
		test.close();
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                          ITEM ALREADY IN STORE                                 " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		return owner_menu();
	}
	ofstream add_item;
	add_item.open( item_name.c_str() );
	add_item << item_name << ' ' << item_type << ' ' << price ;
	add_item.close();
	ofstream list;
	list.open( "itemlists.txt", ios::app );
	list << item_name << ' ' << item_type << endl;
	list.close();
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                            ITEM SUCCESSFULLY ADDED TO SHOP                     " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(1500);
	system("cls");
	return owner_menu();
	
}

int employee_menu()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  EMPLOYEE MENU                                 " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                         [1] SELL ITEM                                          " << endl;
	cout << "                         [2] LIST OF ITEMS IN SHOP                              " << endl;
	cout << "                         [3] LOG OUT AS AN EMPLOYEE                             " << endl;
	cout << "                         [4] EXIT PROGRAM                                       " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                         YOUR CHOICE : " ;
	cin >> choice;
	switch ( choice )
	{
		case 1:
			sell_item();
			break;
		case 2:
			list_of_items();
			break;
		case 3:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "                                LOGGING OUT AS AN EMPLOYEE                      " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return main();
			break;
		case 4:
			system("pause");
			return 0 ;
			break;
		default:
			return employee_menu();
			break;
	}
}

int sell_item()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                    SELLING AN ITEM                             " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                    ITEM NAME : ";
	cin >> item_name;
	ifstream sell;
	sell.open( item_name.c_str() );
	if ( sell.fail() )
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                                 ITEM NOT FOUND                                 " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		return employee_menu();
	}
	sell >> item_name >> item_type >> price ;
	sell.close();
	cout << "                    ITEM TYPE : " << item_type << endl;
	cout << "                    ITEM PRICE : " << price << endl;
	cout << "                    HOW MANY ITEMS ARE SOLD : " ;
	cin >> quantity ;
	total = price * quantity ;
	cout << "                    TOTAL PRICE : " << total << endl;
	cout << "                    FINISH TRANSACTION? (Y/N) " ;
	cin >> string_choice;
	if ( string_choice == y1 || string_choice == y2 )
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                            TRANSACTION FINISHED                                " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(1500);
		ofstream list;
		list.open( "saleslist.txt" , ios::app );
		list << item_name << ' ' << item_type << ' ' << price << ' ' << quantity << ' ' << total << endl;
		list.close();
		system("cls");
		return employee_menu(); 
	}
	else
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                            TRANSACTION CANCELLED                               " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(1500);
		system("cls");
		return employee_menu();
	}
	
}

int list_of_items()
{
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  LIST OF ITEMS                                 " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	ifstream list_items;
	list_items.open( "itemlist.txt");
	while ( !list_items.eof() )
	{
		list_items >> item_name >> item_type ;
		cout << "                   ITEM NAME: " << item_name << endl;
		cout << "                   ITEM TYPE: " << item_type << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}
	list_items.close();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          [1] GO BACK TO EMPLOYEE MENU                          " << endl;
	cout << "                          [2] EXIT PROGRAM                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          YOUR CHOICE : ";
	cin >> choice;
	switch ( choice )
	{
		case 1:
			return employee_menu();
			break;
		case 2:
			system("pause");
			return 0;
		default:
			return list_of_items();
			break;
	}
}
