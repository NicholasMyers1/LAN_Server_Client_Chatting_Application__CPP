#include "includesVoids.h"
	//ALL SERVER RELATED: 
	    char recvBuffer[10000],sendBuffer[10000],Hostname[NI_MAXHOST];//FIX BUFFER SIZE;/CHARS FOR SENDING DATA;
	    int Family=PF_UNSPEC;//FAMILY;
	    int SocketType=SOCK_STREAM;//DEFAULT_SOCKTYPE;
	    char *Port="64250";//port;
	    char Address[100];//char *Address;//="192.168.3.124";//"172.20.68.192";//"172.20.64.233";"fe80::d967:64f1:f578:5e25%12";//"104.136.234.116";//NULL;
	    int i,NumSocks,RetVal,FromLen,AmountRead;//integers to count things;
	    SOCKADDR_STORAGE From;//storage for socket addresses;
	    WSADATA wsaData;//wsa data;
	    addrinfo Hints, *AddrInfo, *AI;//address information;
	    SOCKET ServSock[FD_SETSIZE];//servsocket;??;
	    fd_set SockSet;//fd_set socket set;
		fd_set read_;//why does this have to be static, it crashes otherwise..
		SOCKET ConnSock;
		int argc;
	//FILES/CONV: 
    	ifstream reade_;
		ofstream write_;
		string readMe;
		string writeMe;
		stringstream convert_;
		int logValue=-1;
		string logStr="";//server started=-1;
		 
   	//TIMES_ETC:
		DWORD currTime;//gettickcount();
		int loopUserCount=0;
	//USERS:
		vector<USERS> user_;
		int user_size=0;//the size of the array for users;
		int numUsersLoggedIn=0;//number of users loggedin;
		string USERID="";//this is the userid that currently connected;
		int CURRID=0;
			string text[25];
			string sendText;
			int textCount=0;
			string logVariable="";
int main(){
	INIT_(argc);
		SERVER_LOOP();
return 0;}
