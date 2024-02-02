#include "MainFunctions.h"

void Add_N(AreaList* l){
	int x1, x2, y1, y2;
	string name;
	cout << "please enter the name of the area" << endl;
	cin >> name;
	cout << "entering the 2 points of the area\n\nplease enter the x of point one" << endl;
	cin >> x1;
	cout << "enter the y of point one" << endl;
	cin >> y1;
	cout << "enter the x of point two" << endl;
	cin >> x2;
	cout << "enter the y of point two" << endl;
	cin >> y2;
	Area temp(x1, y1, x2, y2, name);
	if (l->addArea(temp)) {
		cout << "\nsuccessfully added area: " << name << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 <<")\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << "\ncouldn't add the area: " << name << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << "), this area already exist with this name or those points\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
}
void Add_P(pizzaDataBase* db){
	int x1, y1;
	string name;
	cout << "please enter the name of the Pizza shop" << endl;
	cin >> name;
	cout << "entering the location of the shop\n\nplease enter the x" << endl;
	cin >> x1;
	cout << "enter the y" << endl;
	cin >> y1;

	/*if (checkPlace) {
	cout<<"here exist a pizza shop already, please try again"}
	*/

	pizzaMainBranch *temp = new pizzaMainBranch(name, x1, y1);
	if (db->addNewMainBranch(temp)) {
		cout << "\nsuccessfully added the main pizza shop: " << name << "\nlocation: (" << x1 << "," << y1 << ")\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << "\ncouldn't add the main pizza shop: " << name << "\nlocation: (" << x1 << "," << y1 << "), a pizza shop with this name already exist\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}

}
void Add_Br(pizzaDataBase* db){
	int x1, y1;
	string name, mainName;
	cout << "please enter the name of the branch Pizza shop" << endl;
	cin >> name;
	cout << "enter the name of the main Pizza shop" << endl;
	cin >> mainName;
	cout << "entering the location of the shop\n\nplease enter the x" << endl;
	cin >> x1;
	cout << "enter the y" << endl;
	cin >> y1;

	/*if (checkPlace) {
	cout<<"here exist a pizza shop already, please try again"}
	*/

	pizzaBranch* temp = new pizzaBranch(name, mainName, x1, y1);
	if (db->addNewBranch(temp)) {
		cout << "\nsuccessfully added the branch pizza shop: " << name << "\nlocation: (" << x1 << "," << y1 << ")\nmain shop: " << mainName << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << "\ncouldn't add the branch pizza shop: " << name << "\nlocation: (" << x1 << "," << y1 << ")\nmain shop: " << mainName << "\nthere already exist a brach with the same name or there is no main shop with this name at all\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
}
void Del_Br(pizzaDataBase* db){
	int x1, y1;
	cout << "entering the location of the shop that you want to delete\n\nplease enter the x" << endl;
	cin >> x1;
	cout << "enter the y" << endl;
	cin >> y1;
	Point temp(x1, y1);
	if (db->delBranch(temp)) {
		cout << "\nsuccessfully deleted the pizza shop in the location\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << "\ncouldn't delete the pizza shop in this location\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
}
void List_P(pizzaDataBase* db){
	string Aname;
	cout << "please enter the name of the area" << endl;
	cin >> Aname;
	/*
	search function here
	*/
    cout <<"\n\npress any key to continue" << endl;
	getch();
	system("cls");
}
void List_Brs(pizzaDataBase* db){
	string name;
	cout << "please enter the name of the main pizza brach" << endl;
	cin >> name;

	if(!db->printBranch(name))
		cout << "there doesn't exit any main pizza branch with this name";
	
    cout <<"\n\npress any key to continue" << endl;
	getch();
	system("cls");
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