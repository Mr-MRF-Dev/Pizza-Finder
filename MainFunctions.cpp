#include "MainFunctions.h"

void Add_N(AreaList* l){
	int x1, x2, y1, y2;
	string name;
	cout << Color_Orange << "please enter the name of the area" << Color_Reset << endl;
	cin >> name;
	cout << Color_Orange << "entering the 2 points of the area\n\nplease enter the x of point one" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y of point one" << Color_Reset << endl;
	cin >> y1;
	cout << Color_Orange << "enter the x of point two" << Color_Reset << endl;
	cin >> x2;
	cout << Color_Orange << "enter the y of point two" << Color_Reset << endl;
	cin >> y2;
	Area temp(x1, y1, x2, y2, name);
	if (l->addArea(temp)) {
		cout << Color_Green << "\nsuccessfully added area: " << Color_Green_Blue << name << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 <<")" << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << Color_Red << "\ncouldn't add the area: " << Color_Green_Blue << name << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << Color_Red << ", this area already exist with this name or those points" << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
}

void Add_P(pizzaDataBase* db, KDTree* ap){
	int x1, y1;
	string name;
	cout << Color_Orange << "please enter the name of the Pizza shop" << Color_Reset << endl;
	cin >> name;
	cout << Color_Orange << "entering the location of the shop\n\nplease enter the x" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y" << Color_Reset << endl;
	cin >> y1;
	pizzaMainBranch *temp = new pizzaMainBranch(name, x1, y1);

	if (!ap->insert(temp)) {
	cout << Color_Red << "here exist a pizza shop already, couldn't add the pizza shop" << Color_Yellow << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
	delete temp;
	}
	else if (db->addNewMainBranch(temp)) {
		cout << Color_Green << "\nsuccessfully added the main pizza shop: " << Color_Green_Blue  << name << "\nlocation: (" << x1 << "," << y1 << ")" << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << Color_Red << "\ncouldn't add the main pizza shop: " << Color_Green_Blue << name << "\nlocation: (" << x1 << "," << y1 << ")" << Color_Red << ", a pizza shop with this name already exist" << Color_Yellow << "\n\npress any key to continue" << endl;
		ap->deleteNode(temp->getPoint());
		delete temp;
		getch();
		system("cls");
	}

}

void Add_Br(pizzaDataBase* db, KDTree *ap){
	int x1, y1;
	string name, mainName;
	cout << Color_Orange << "please enter the name of the branch Pizza shop" << Color_Reset << endl;
	cin >> name;
	cout << Color_Orange << "enter the name of the main Pizza shop" << Color_Reset << endl;
	cin >> mainName;
	cout << Color_Orange << "entering the location of the shop\n\nplease enter the x" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y" << Color_Reset << endl;
	cin >> y1;
	pizzaBranch* temp = new pizzaBranch(name, mainName, x1, y1);

	if (!ap->insert(temp)) {
	cout << Color_Red << "here exist a pizza shop already, couldn't add the pizza shop" << Color_Yellow << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
	delete temp;
	}
	else if (db->addNewBranch(temp)) {
		cout << Color_Green << "\nsuccessfully added the branch pizza shop: " << Color_Green_Blue << name << "\n location: (" << x1 << "," << y1 << ")\nmain shop: " << mainName << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << Color_Red << "\ncouldn't add the branch pizza shop: " << Color_Green_Blue << name << "\nlocation: (" << x1 << "," << y1 << ")\nmain shop: " << mainName << Color_Red << "\nthere already exist a brach with the same name or there is no main shop with this name at all" << Color_Yellow << "\n\npress any key to continue" << endl;
		ap->deleteNode(temp->getPoint());
		delete temp;
		getch();
		system("cls");
	}
}

void Del_Br(pizzaDataBase* db, KDTree *ap){
	int x1, y1;
	cout << Color_Orange << "entering the location of the shop that you want to delete\n\nplease enter the x" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y" << Color_Reset <<endl;
	cin >> y1;
	Point temp(x1, y1);
	string brName = db->getBranchName(temp);
	if (db->delBranch(temp)) {
		//delete the point from ap
		ap->deleteNode(temp);
		cout << Color_Green <<"\nsuccessfully deleted the pizza shop: " << Color_Aqua << brName << Color_Green << " in the location: " << Color_Aqua << "(" << x1 << ", " << y1 << ")" << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
	else {
		cout << Color_Red << "\ncouldn't delete the pizza shop in this location" << Color_Yellow << "\n\npress any key to continue" << endl;
		getch();
		system("cls");
	}
}

void List_P(KDTree* ap, AreaList* l){
	string Aname;
	cout << Color_Orange << "please enter the name of the area" << Color_Reset << endl;
	cin >> Aname;
	/*
	search function here
	*/

	Area * a = l->search(Aname); 
	if (a) {
		for (auto i : ap->searchArea(a)) {
			cout << *i << endl;
		}
	}

	else {
		// not found area

	}


    cout << Color_Yellow << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
}

void List_Brs(pizzaDataBase* db){
	string name;
	cout << Color_Orange << "please enter the name of the main pizza brach" << Color_Reset << endl;
	cin >> name;

	if(!db->printBranch(name))
		cout << Color_Red << "there doesn't exit any main pizza branch with this name";
	
    cout << Color_Yellow << "\n\npress any key to continue" << endl;
	getch();
	system("cls");
}

void Near_P(KDTree* ap){
	int x1, y1;
	cout << Color_Orange << "finding the nearest pizza shop to this location\nplease enter the x" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y" << Color_Reset <<endl;
	cin >> y1;
	Point temp(x1, y1);

	branch* tmp = ap->findNearstBranch(temp);
	if(tmp!=NULL){
		cout << *tmp;
	}
	else{
		cout << " no branch";
	}

}

void Near_Br(){
	
}

void Avail_P(KDTree* ap){
	int x1, y1, r;
	cout << Color_Orange << "finding pizza shops in near by location\nplease enter the x" << Color_Reset << endl;
	cin >> x1;
	cout << Color_Orange << "enter the y" << Color_Reset <<endl;
	cin >> y1;
	cout << Color_Orange << "enter the Radius" << Color_Reset <<endl;
	cin >> r;
	Point temp(x1, y1);

	for (auto i : ap->findInRadius(temp,r)) {
		cout << *i << endl;
	}
	
	// not found area

    cout << Color_Yellow << "\n\npress any key to continue" << endl;
	getch();
	system("cls");



}

void Most_Brs(){
	
}

void Undo(){
	
}