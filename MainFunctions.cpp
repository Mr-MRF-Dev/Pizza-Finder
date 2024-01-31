#include "MainFunctions.h"

void Add_N(){
	int x1, x2, y1, y2;
	string name;
	cout << "please enter the name of the area" << endl;
	cin >> name;
	cout << "entering  the 2 points of the area\nplease enter the x of point one" << endl;
	cin >> x1;
	cout << "enter the y of point one" << endl;
	cin >> y1;
	cout << "enter the x of point two" << endl;
	cin >> x2;
	cout << "enter the y of point two" << endl;
	cin >> y2;
	Area A(x1, y1, x2, y2, name);
	cout << "successfully added "<< name <<"\n\npress any key to continue" << endl;
	getch();
	system("cls");
}
void Add_P(){
	
}
void Add_Br(){
	
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