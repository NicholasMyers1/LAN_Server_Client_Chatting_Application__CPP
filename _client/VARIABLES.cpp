#include "includesVoids.h"
	//ALL SERVER RELATED: 
    	WSADATA wsaData;
    	SOCKET ConnectSocket = INVALID_SOCKET;
    	struct addrinfo *result = NULL,*ptr = NULL,hints;
    	const char *IP_;
    	string keepIP_;
			bool connected=false;
			bool loggedIn=false;
			string userID="";
			string username="";
    	char sendbuf[10000];
		char recvbuf[10000];
    	int iResult,sentTest;
    	int recvbuflen=10000;
    //TEXT:
    	TEXT TEXT_CMD[1000];//0 is for the a text explanation to the user;
    	TEXT CMD_OUTPUT[25];
			bool cmdMode=false;//put this before every piece of code that has CMD_OUTPUT[n]
			//int cmdNum=0;
    	TEXT TEXT_LIST[25];
    	TEXT TEXT_WRITE;
    	int textPos=0;
    //FILES: 
    	ifstream read_;
		ofstream write_;
		string readMe;
		string writeMe;
		int readCounter=0;
		string ipSave[10];
	//TIME: 
		DWORD connectTime=0;
		DWORD getTime=0;
