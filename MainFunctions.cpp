#include "MainFunctions.h"

void Add_N(){
	int x1, x2, y1, y2;
	string name;
	cout << "please enter the name of the area" << endl;
	cin >> name;
	cout << "entering the 2 points of the area\nplease enter the x of point one" << endl;
	cin >> x1;
	cout << "enter the y of point one" << endl;
	cin >> y1;
	cout << "enter the x of point two" << endl;
	cin >> x2;
	cout << "enter the y of point two" << endl;
	cin >> y2;
	Area A(x1, y1, x2, y2, name);
	cout << "\nsuccessfully added "<< name <<"\n\npress any key to continue" << endl;
	getch();
	system("cls");
}
void Add_P(){
	int x1, y1;
	string name;
	cout << "please enter the name of the Pizza shop" << endl;
	cin >> name;
	cout << "entering the location of the shop\nplease enter the x" << endl;
	cin >> x1;
	cout << "enter the y" << endl;
	cin >> y1;

	/*if (checkPlace) {
	cout<<"here exist a pizza shop already, please try again"}
	*/

	pizzaMainBranch temp(name, x1, y1);
	//add to main_list
	cout << "\nsuccessfully added the pizza shop: " << name << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
}
void Add_Br(){
	int x1, y1;
	string name, mainName;
	cout << "please enter the name of the branch Pizza shop" << endl;
	cin >> name;
	cout << "enter the name of the main Pizza shop" << endl;
	cin >> mainName;
	cout << "entering the location of the shop\nplease enter the x" << endl;
	cin >> x1;
	cout << "enter the y" << endl;
	cin >> y1;

	/*if (checkPlace) {
	cout<<"here exist a pizza shop already, please try again"}
	*/

	pizzaBranch temp(name, mainName, x1, y1);
	//add to br_list
	cout << "\nsuccessfully added the branch pizza shop: " << name << "\nmain shop is: " << mainName << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
}
void Del_P(){
	
}
void Del_Br(){
	
}
void List_P(){
	
}
void List_Brs(){
	
}
void Near_P(){
	
}
void Near_Br(){
	
}
void Avail_P(){
	
}
void Most_Brs(){
	
}
void Undo(){
	
}