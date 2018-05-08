#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
	#define WIN32_LEAN_AND_MEAN
	#define _WIN32_WINNT 0x501
		#include <winsock2.h>
		#include <ws2tcpip.h>
		#include <future>
		#include <math.h>
		#include <ctime>
		#include <windows.h>
		#include <iostream>
		#include <stdlib.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <cstring>
		#include <fstream>
		#include <GL/glew.h>
		#include <gl\gl.h>
		#include <gl\glext.h>
		#include <gl\glaux.h>
		#include <gl\glu.h>
		#include <GL\glut.h>
		#include <assert.h>
		#include <sstream>
		#include <iomanip>
		#include <ctime>
		#include <cstring>
		#include <cmath>
		#include <fstream>
		#include <time.h>
		#include <string.h>
		#include <string>
		#include <cstdlib>
		#include <cstdio>
		#include <gl\glfw.h>
		#include <vector>
		#include <conio.h>
		#include <new>
	using namespace std;
	//DEFINITIONS: 
	//VOIDS: 
		void INIT();
		void SERVER();
			void mousemoveunpressed(int x, int y);
			void mouseclick(int button,int state,int x,int y);
			void skeyd (int key,int x,int y);
			void keyPressed(unsigned char key,int x,int y);
		void TEXTWRITE();
		void COMMANDS();
		void RECEIVE();
	//STRUCTURES: 
		extern struct addrinfo *result,*ptr,hints;
		struct TEXT{
			string text;
		};extern TEXT TEXT_CMD[1000];extern TEXT TEXT_LIST[25];extern TEXT CMD_OUTPUT[25];extern TEXT TEXT_WRITE;
		extern int textPos;/*,cmdNum;*/extern bool cmdMode;
	//GLOBALS: 
		//ALL SERVER RELATED: 
		    extern WSADATA wsaData;
		    extern SOCKET ConnectSocket;
		    extern struct addrinfo *result,*ptr;
		    extern const char *IP_;
		    extern string keepIP_;//this is only used because of a problem with extern chars taking in garbage data and producing a false ip address;
			extern bool loggedIn;
			extern string userID;
			extern string username;
			extern bool connected;
		    extern char sendbuf[10000];// = "this is a test";
			extern char recvbuf[10000];
		    extern int iResult,sentTest;
		    extern int recvbuflen;
	    //FILES: 
			extern ifstream read_;
			extern ofstream write_;
			extern string readMe;
			extern string writeMe;
			extern int readCounter;
			extern string ipSave[10];
    	//TIMES_ETC: 
    		extern DWORD connectTime;
    		extern DWORD getTime;
		//MAIN_LOOP STUFF: 
#endif
