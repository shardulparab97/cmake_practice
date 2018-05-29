//Configmanager.cpp

#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include <sstream>

using namespace std;

#include "include/Configmanager.h"


//reads the config file and gets the values of the member variables

void Configmanager::setDefaults(){

  //int input_w = 640, input_h = 360, stream_w = 640, stream_h = 360, port = 80;
  m_input_w = 640;
  m_input_h = 360;
  m_stream_w = 640;
  m_stream_h = 360;
  m_port = 80;
}

void Configmanager::readFile(string fileName){

	ifstream myfile (fileName);
	string line;

	if(myfile.is_open()){
		while(getline(myfile,line)){
			//cout<<line<<endl;
			if(line.size()>0){
		    vector <string> tokens;

			stringstream check1(line);
     
    		string intermediate;
     
    		// Tokenizing w.r.t. space ' '
    		while(getline(check1, intermediate, ' '))
    			{
        			tokens.push_back(intermediate);
    			}

    			if(tokens.size() == 2){
    				stringstream value(tokens[1]);
        			if(tokens[0] == "input_w"){
        				//m_input_w = atoi(tokens[1]);
        				value>>m_input_w;
        			}

        			else if(tokens[0] == "input_h"){
        				//m_input_h = atoi(tokens[1]);
        				value>>m_input_h;
        			}

        			else if(tokens[0] == "stream_w"){
        				//m_stream_w = atoi(tokens[1]);
        				value>>m_stream_w;
        			}

        			else if(tokens[0] == "stream_h"){
        				//m_stream_h = tokens[1];
        				value>>m_stream_h;
        			}

        			else if(tokens[0] == "port"){
        				//m_port = tokens[1];
        				value>>m_port;
        			}
        			
        			else{
        				cout<<"Invalid arguments passed in config file"<<endl;
        				cout<<"Using defaults after this"<<endl;
        				return;
        			}
        		}

        		else{
        				cout<<"Invalid arguments passed in config file"<<endl;
        				cout<<"Using defaults after this"<<endl;
        				return;
        		}
    		}
    	}
    		myfile.close();
	}

	else{
		cout<<"Unable to open the file";
	}
}

	void Configmanager::printParams(){
		cout<<"Input w = "<<m_input_w<<endl;
		cout<<"Input h = "<<m_input_h<<endl;
		cout<<"stream_h = "<<m_stream_h<<endl;
		cout<<"stream_w= "<<m_stream_w<<endl;
		cout<<"port= "<<m_port<<endl;

	}
