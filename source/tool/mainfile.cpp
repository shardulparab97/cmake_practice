#include<iostream>
#include "include/Configmanager.h"

using namespace std;

int main(){
	Configmanager cm;
	cm.readFile("conf.txt");
	cm.printParams();
	return 0;
}