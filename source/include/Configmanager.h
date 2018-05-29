//header file for ConfigManager

#include<iostream>
using namespace std;


#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

class Configmanager{

//keeping member variables private here
private:
	int m_input_h;
	int m_input_w;
	int m_stream_w;
	int m_stream_h;
	int m_port;
	string m_camUrl;


//public functions 
public:
	void setDefaults();
	void readFile(string fileName);
	void printParams();
};

#endif



  //int input_w = 640, input_h = 360, stream_w = 640, stream_h = 360, port = 80;