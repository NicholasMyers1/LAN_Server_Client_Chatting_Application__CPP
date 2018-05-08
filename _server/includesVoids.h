#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
	#define _WIN32_WINNT 0x501
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#include <stdio.h>
	#include <string.h>
	#include <string>
	#include <direct.h>
	#include <thread>
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <pthread.h>
	#include <vector>
	#include <Windows.h>
	using namespace std;
	//DEFINITIONS: 
	//VOIDS: 
		extern void INIT_(int argc);
		extern void SERVER_LOOP();
		extern void LOGIN_CREATE();
		extern void RECEIVE();
		extern void RECEIVE_COMMAND();
		extern void LOG();
	//STRUCTURES: 
	//GLOBALS: 
		//ALL SERVER RELATED: 
		    extern char recvBuffer[10000/*128*/],sendBuffer[10000],Hostname[NI_MAXHOST];//FIX BUFFER SIZE;/CHARS FOR SENDING DATA;
		    extern int Family;//FAMILY;
		    extern int SocketType;//DEFAULT_SOCKTYPE;
		    extern char *Port;//port;
		    extern char Address[100];//char *Address;//"192.168.1.120";"fe80::d967:64f1:f578:5e25%12";//"104.136.234.116";//NULL;
		    extern int i,NumSocks,RetVal,FromLen,AmountRead;//integers to count things;
		    extern SOCKADDR_STORAGE From;//storage for socket addresses;
		    extern WSADATA wsaData;//wsa data;
		    extern addrinfo Hints, *AddrInfo, *AI;//address information;
		    extern SOCKET ServSock[FD_SETSIZE];//servsocket;??;
		    extern fd_set SockSet;//fd_set socket set;
			extern fd_set read_;//why does this have to be static, it crashes otherwise..0
			extern SOCKET ConnSock;
			extern int argc;
	    //FILES/CONV: 
	    	extern ifstream reade_;
			extern ofstream write_;
			extern string readMe;
			extern string writeMe;
			extern stringstream convert_; 
			extern int logValue;//0,1,2,3;-1 for nobody connected and log last user out. -2 for absolute, so it does not keep logging. 
			extern string logStr;
    	//TIMES_ETC:
			extern DWORD currTime;//gettickcount(); 
			extern int loopUserCount;
    	//USERS:
    		struct USERS{
    			string ip;
    			string username;
    			DWORD time_;//get tick count;
   			};extern vector<USERS> user_;extern int user_size,numUsersLoggedIn;
   			extern string USERID;//this is the userid that currently connected;
   			extern int CURRID;
				extern string text[25];
				extern string sendText;
				extern int textCount;
				extern string logVariable;
		//MAIN_LOOP STUFF: 
#endif
