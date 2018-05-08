#include "includesVoids.h"
void SERVER_LOOP(){
	while(1){
		if(numUsersLoggedIn>0){
			currTime=GetTickCount();//CONSTANTLY UPDATE THE TIME OF THE SERVER;
			for(int n=0;n<100;n++){//count in increments of 100 initially starting at 0; and usercount is added in;
//			cout<<currTime<<"\n";//loopUserCount can be 0,100,200,300,...,1000,...
			cout<<"n: "<<n<<"\n";
				if(n+loopUserCount>=/*=*/numUsersLoggedIn){//if 0+1>=numUsersLoggedIn.. or is 99+1220>=numUsersLoggedIn reset, break;
					loopUserCount=0;break;
				}
				else if((currTime-user_[n+loopUserCount].time_)>1500&&user_[n+loopUserCount].username!=""){//logout user because timout;
					//LOGOUT USER
					logVariable=user_[n+loopUserCount].username;
					cout<<"test-----------------------------------------------------------------------------------------------------------------------------------------------------";
////					logValue=6;
					LOG();//LOGOUT THE USER;
					cout<<user_[n+loopUserCount].username<<" timed out with the id of: "<<n+loopUserCount<<"\n";
					user_[n+loopUserCount].time_=0;
					user_[n+loopUserCount].username="";
					user_[n+loopUserCount].ip="";
					numUsersLoggedIn-=1;
					//make some sort of function to allow the userlist to setback if a user was logged out;
				}
			}loopUserCount+=100;
			if(loopUserCount>numUsersLoggedIn){
				loopUserCount=0;
			}
		}//wait for a user to connect: 
			timeval timeout={.tv_sec=5,.tv_usec=0};
		    FD_SET(ServSock[i], &read_);
	    	select(ServSock[i]+1,&read_,NULL,NULL,&timeout);
		if(!FD_ISSET(ServSock[i],&read_)){//nobody connected;
			cout<<"nobody connected at the moment on: "<<Address<<"\n";
			if(user_size>0){
				for(int n=0;n<user_size;n++){
					if(user_[n].username!=""){
						logVariable+=user_[n].username;
						logValue=6;
						LOG();//LOGOUT THE USER;
					}
					user_[n].time_=0;
					user_[n].username="";
					user_[n].ip="";
				}
				loopUserCount=0;
				user_.resize(0);//?
				user_size=0;
				numUsersLoggedIn=0;
				logValue=0;
				LOG();//LOGOUT THE USER;
				logValue=9;
//				cout<<"now nobody connected";
			}
			continue;
		}
	    if(SocketType==SOCK_STREAM){//somebody connected;
	        ConnSock=accept(ServSock[i],(LPSOCKADDR)&From,&FromLen);
	        if(getnameinfo((LPSOCKADDR)&From,FromLen,Hostname,sizeof(Hostname),NULL,0,NI_NUMERICHOST)!= 0){
	        	strcpy(Hostname,"<unknown>");								printf("Accepted connection from %s.\n",Hostname);
			}
			while(AmountRead>=0){
				AmountRead=recv(ConnSock,recvBuffer,3000/*sizeof(recvBuffer)*/,0);
				if(AmountRead==0){
	//				cout<<"test";
					break;
				}
			}
			cout<<"someone connected: "<<recvBuffer<<"\n";
		//CREATE OR LOGIN:
			if(recvBuffer[0]=='/'){//if success send back "login success" (ID: use that id to tell server already connected;
				convert_.str("");
				LOGIN_CREATE();
				LOG();
			}
		//LOGGED IN;
			else{//Get connected user:
				RECEIVE();
				//cout<<logValue<<"--logval\n";
				LOG();//LOG DATA;
			}
	//		cout<<"connection closed";
	    }
//	    cout<<"sent: "<<sendBuffer<<"\n";
			RetVal=send(ConnSock,sendBuffer,3000/*(int)(strlen)(sendBuffer)*/,0);
			closesocket(ConnSock);
			memset(recvBuffer,0,sizeof(recvBuffer));
			memset(sendBuffer,0,sizeof(sendBuffer));
	}
}
