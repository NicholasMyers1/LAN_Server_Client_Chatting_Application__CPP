#include "includesVoids.h"
void SERVER(){
	iResult= WSAStartup(MAKEWORD(2,2), &wsaData);// Initialize Winsock
	ZeroMemory( &hints, sizeof(hints) );
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
			IP_=keepIP_.c_str();
	iResult= getaddrinfo(IP_/*"25.90.129.120"*/,"64250",&hints,&result);// Resolve the server address and port
	for(ptr=result; ptr != NULL ;ptr=ptr->ai_next){// Attempt to connect to an address until one succeeds
	    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol); // Create a SOCKET for connecting to server
	    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);// Connect to server.
	}cout<<iResult<<"\n";
	if(sendbuf[0]=='\0'){
		string connectAll=userID+" "+username;
		for(int n=0;n<connectAll.length();n++){
			sendbuf[n]=connectAll[n];
		}
	}
	
	
	cout<<sendbuf<<"\n\n\n\n";
	
	
		sentTest/*iResult*/=send( ConnectSocket, sendbuf,3000, 0 );// Send an initial buffer	
//		printf("Bytes Sent: %ld\n",sentTest/*iResult*/);
	iResult=shutdown(ConnectSocket, SD_SEND);// shutdown the connection since no more data will be sent
	//RECEIVE:
//	cout<<iResult<<"\n";
	if(iResult>=0){
			iResult=recv(ConnectSocket,recvbuf,3000/*sizeof(recvbuf)*//*sizeof(recvbuf)*/,0);
		if(connected==false||connected==true&&loggedIn==false){//FIX SO IT DOES NOT SHOW ON A FAILED LOGIN;
			for(int n=0;n<25;n++){
				CMD_OUTPUT[n].text="";
			}
			CMD_OUTPUT[0].text="Please login: "+TEXT_CMD[5].text+" or create an account: "+ TEXT_CMD[4].text;
			CMD_OUTPUT[1].text="You can disconnect and logout of the server at any time by typing the command: /logout";
			CMD_OUTPUT[2].text="You have successfully connected to the server of: "+keepIP_;
		}
		else{
			int count_=24;
			//cout<<"recv: "<<recvbuf;
			if(recvbuf[0]!='\0'){
				for(int n=0;n<25;n++){
					TEXT_LIST[n].text="";
				}
			}
			for(int n=0;n<(int)strlen(recvbuf);n++){
				if(recvbuf[n]!='\n'){
					TEXT_LIST[count_].text+=recvbuf[n];
				}
				if(recvbuf[n]=='\n'){
					count_-=1;
				}
			}
		}
		connected=true;
	}
		if(connected==true&&sentTest==-1||connected==true&&iResult==-1){
			for(int n=0;n<25;n++){
				CMD_OUTPUT[n].text="";
				TEXT_LIST[n].text="";
			}
			CMD_OUTPUT[0].text=TEXT_CMD[3].text;
			CMD_OUTPUT[1].text="Connection lost. Server may be experiencing difficulties, or it was shut down. You can attempt to connect again.";
			loggedIn=false;
			connected=false;
			username="";
			userID="";
			cmdMode=true;
			TEXT_WRITE.text="/";
			textPos=1;
		}
	else if(connected==false){
		for(int n=2;n<12;n++){
			CMD_OUTPUT[n].text=(n+46);
			CMD_OUTPUT[n].text+=": "+ipSave[n-2];
		}
		CMD_OUTPUT[0].text=TEXT_CMD[3].text;
		CMD_OUTPUT[1].text="Connection failed. The server may be experiencing difficulties, or it was shut down. You can attempt to connect again.";
	}
//	cout<<"Buffer:"<<recvbuf<<"\n";
//	cout<<iResult<<"<--iresult"<<sentTest<<"<--sendvalue";
	closesocket(ConnectSocket);// cleanup
	WSACleanup();
//		cout<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
			RECEIVE();
			memset(recvbuf,0,sizeof(recvbuf));
			memset(sendbuf,0,sizeof(sendbuf));
	connectTime=GetTickCount();
}
