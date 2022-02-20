#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdio.h>

using namespace std;

int log_in();
int sign_up();
int store();
int add_item_to_shelve();
int log_in_as_admin();
int admin_menu();

string username , fname , lname , mname , password , item_number , item_name ;
int choice , price , points;

int main()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   HOME PAGE                                    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] LOG IN " << endl;
	cout << "          [2] LOG IN AS ADMIN " << endl;
	cout << "          [3] SIGN UP " << endl;
	cout << "          [4] EXIT PROGRAM " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR CHOICE : ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			log_in();
			break;
		case 2:
			log_in_as_admin();
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
			cout << "          INVALID INPUT  " << endl;
			Sleep(2000);
			return main();
			break;
	}
	
}

int log_in()
{
	string lusername , lpassword;
	system("cls");
	cout << "          USERNAME : " ; cin >> username;
	cout << "          PASSWORD : " ; cin >> password;
	ifstream l_in;
	l_in.open( username.c_str() );
	l_in >> lusername >> lpassword >> fname >> mname >> lname >> points ;
	l_in.close();
	if ( username == lusername && password == lpassword )
	{
		system("cls");
		cout << "          SUCCESSFULLY LOGGED IN! " << endl;
		Sleep(2000);
		store();
	}
	else
	{
		system("cls");
		cout << "          FAILED LOG IN ATTEMPT! " << endl;
		Sleep(2000);
		return main();
	}
}

int sign_up()
{
	system("cls");
	cout << endl << "-------------------------------------------------------------------------------------------------" << endl;		
	cout << "					Welcome!" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "			Please fill up the following to register." << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl << endl;	
	cout << "	First name:			"; cin >> fname;
	cout << "	Surname:			"; cin >> lname;
	cout << "	Middle Initial:	    "; cin >> mname; 		
	cout << "	User name:			"; cin >> username;			
	cout << "	Password:			"; cin >> password;
	cout << endl << "-------------------------------------------------------------------------------------------------" << endl;
	ofstream s_up;
	s_up.open( username.c_str());
	points = 10000;
	s_up << username << ' ' << password << ' ' << fname << ' ' << mname << ' ' << lname  << ' ' << points;
	s_up.close();
	system("cls");
	cout << "          ACCOUNT SUCCESSFULLY CREATED!  " << endl;
	Sleep(2000);
	return main();
}

int log_in_as_admin()
{
	string auser, apass , ausername , apassword;
	system("cls");
	cout << "          ADMIN USERNAME : " ; cin >> ausername ;
	cout << "          ADMIN PASSWORD : " ; cin >> apassword ;
	ifstream admin;
	admin.open( "adminaccount.txt" );
	admin >> auser >> apass;
	admin.close();
	if ( ausername == auser && apassword == apass )
	{
		system("cls");
		cout << "          ADMIN LOG IN SUCCESSFUL! " << endl;
		Sleep(2000);
		admin_menu();
	}
	else
	{
		system("cls");
		cout << "          ADMIN LOG IN FAILED! " << endl;
		Sleep(2000);
		return main();
	}
}

int admin_menu()
{
	system("cls");
	cout << "          [1] ADD ITEM TO SHELVE " << endl;
	cout << "          [2] LOG OUT            " << endl;
	cout << "          [3] EXIT PROGRAM       " << endl;
	cout << "          YOUR CHOICE: " ; cin >> choice;
	switch (choice)
	{
		case 1:
			add_item_to_shelve();
			break;
		case 2:
			return main();
			break;
		case 3:
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			cout << "          INVALID INPUT   " << endl;
			Sleep(2000);
			return admin_menu();
			break;
	}
}
int add_item_to_shelve()
{
	cout << "          ITEM NUMBER : " ; cin >> item_number;
	cout << "          ITEM NAME   : " ; cin >> item_name ;
	cout << "          PRICE : "       ; cin >> price;
	ifstream add_item_test;
	add_item_test.open( item_number.c_str() );
	if ( !(add_item_test.fail()) )
	{
		add_item_test.close();
		system("cls");
		cout << "          ITEM NUMBER IS ALREADY TAKEN! "	<< endl;
		Sleep(2000);
		return add_item_to_shelve();
	}
	ofstream add_item;
	add_item.open( item_number.c_str() );
	add_item << item_number << ' ' << item_name << ' ' << price << endl;
	add_item.close();
	ofstream database;
	database.open( "database.txt", ios::app );
	database << item_number << ' ' << item_name << ' ' << endl;
	database.close();
	system("cls");
	cout << "          ITEM SUCCESSFULLY ADDED!  " << endl;
	Sleep(2000);
	return admin_menu();
}

int store()
{
	string display_item_name , display_item_number;
	int quantity, total;
	string buy;
	system("cls");
	ifstream database;
	database.open( "database.txt");
	while ( !database.eof() )
	{
		database >> display_item_number >> display_item_name ;
		cout << "  ITEM NUMBER: " << display_item_number << endl;
		cout << "       ITEM NAME: " << display_item_name << endl;
	}
	database.close();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          CHOOSE AN ITEM NUMBER YOU WANT TO BUY: " ;
	cin >> buy;
	ifstream storee;
	storee.open( buy.c_str() );
	storee >> item_number >> item_name >> price;
	if ( storee.fail() )
	{
		system("cls");
		cout << "          ITEM NUMBER NOT FOUND! " << endl;
		Sleep(2000);
		return store();
	}
	else
	{
		system("cls");
		cout << "          ITEM NUMBER : " << item_number << endl;
		cout << "          ITEM NAME : " << item_name << endl;
		cout << "          PRICE : " << price << endl;
		cout << "          HOW MANY ITEMS WOULD YOU LIKE TO BUY? " ; cin >> quantity;
		total= price * quantity;
		system("cls");
		cout << "          SUCCESSFULLY PURCHASED " << quantity << " " << item_name << " !" << endl;
		cout << "                       IT COSTS: " << total << endl;
		points -= total;
		Sleep(2000);
		return store();
		
	}
}



