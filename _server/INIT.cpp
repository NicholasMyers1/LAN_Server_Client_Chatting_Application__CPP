#include "includesVoids.h"
void INIT_(int argc){
	//FILES:
		string afterRead="";
		int countLine=0;
		string getInput="";
		reade_.open("_USERINFO.txt");
		if(!reade_){//if the file is non-existent:
			reade_.close();
			write_.open("_USERINFO.txt");//write_<<writeMe;
			write_.close();
		}reade_.close();
		reade_.open("_USERLIST.txt");
		if(!reade_){//if the file is non-existent:
			reade_.close();
			write_.open("_USERLIST.txt");//write_<<writeMe;
			write_.close();
		}reade_.close();
		//
		reade_.open("_IP.cfg");
		if(!reade_){//if the file is non-existent:
			reade_.close();
			write_.open("_IP.cfg");//write_<<writeMe;
			write_.close();
		}
		else{//if the file exists:
			reade_.close();
			reade_.open("_IP.cfg");
			while(!reade_.eof()){
				getline(reade_,readMe);//reade_ from file, output to readMe;
				if(countLine==0){
					afterRead=readMe;
				}
				if(readMe=="\0"){
					break;
				}
				countLine+=1;
			}reade_.close();
			if(afterRead!=""){//if the text read from the file was not "";
				cout<<"Your saved server IPV4 address is: "<<afterRead<<"\n";
				cout<<"Use this IPV4 address? Type '1' and enter to use it.\n";
				cout<<"Otherwise, enter a new IPV4 address. (It will be rewritten in the _IP.cfg file).\n";
			}
		}
		reade_.open("_LOG.log");//CREATE A LOG FILE IF IT DOES NOT EXIST FOR THE SERVER: 
		if(!reade_){//if the file is non-existent:
			reade_.close();
			write_.open("_LOG.log");
			write_<<"(-1)=SERVER START\n(0)=NOBODY CONNECTED\n(1)=FAIL CREATE\n(2)=FAIL LOGIN\n(3)=SUCCESS CREATE AND LOGGEDIN\n(4)=SUCCESS LOGIN\n(5)=MESSAGE CAME IN\n(6)=A USER LOGGED OUT\n(7)=UNAUTHORIZED CONNECTION\n(8)=A COMMAND CAME IN\n";
			write_.close();
		}reade_.close();
		//
		cout<<"Enter an IPV4 address to use for the server: ";
		cin>>getInput;
		memset(Address,0,sizeof(Address));
		if(getInput=="1"){
			for(int n=0;n<afterRead.length();n++){
				Address[n]+=afterRead[n];
			}
		}
		else{
			for(int n=0;n<getInput/*afterRead*/.length();n++){
				Address[n]+=getInput[n];
//				cout<<n<<"\n";
			}
			write_.open("_IP.cfg");//write_<<writeMe;
				write_<<getInput+"\n";
			write_.close();				
		}cout<<"Server started with the IP of: "<<Address<<"..\n";
		logValue=-1;
		LOG();
		logValue=9;
	//SERVER STUFF:
	    if(argc>1){
	        Family=PF_INET6;SocketType=SOCK_STREAM;
	    }
	    if((RetVal=WSAStartup(MAKEWORD(2,2),&wsaData))!=0){
	        WSACleanup();
	    }
	    memset(&Hints,0,sizeof(Hints));//next four lines are for socket information;
		    Hints.ai_family=Family;
		    Hints.ai_socktype=SocketType;
		    Hints.ai_flags=AI_NUMERICHOST|AI_PASSIVE;
		    RetVal=getaddrinfo(Address, Port, &Hints, &AddrInfo);
	    for(i=0,AI=AddrInfo;AI!=NULL;AI=AI->ai_next,i++){
	        if((AI->ai_family!=PF_INET)&&(AI->ai_family!=PF_INET6))
	            continue;
	        ServSock[i]=socket(AI->ai_family,AI->ai_socktype,AI->ai_protocol);
	        if (bind(ServSock[i],AI->ai_addr,int(AI->ai_addrlen))==SOCKET_ERROR){
	            continue;
	        }
	    	if (SocketType==SOCK_STREAM){
	            if (listen(ServSock[i],5)==SOCKET_ERROR){
	 	        	continue;
	            }
	        }
	    }
	    	freeaddrinfo(AddrInfo);
	    	NumSocks=i;
	    	FD_ZERO(&SockSet);
	        FromLen=sizeof(From);
	    for(i=0;i<NumSocks;i++){
	        if(FD_ISSET(ServSock[i],&SockSet))
	    		break;
	    }
	    if(i==NumSocks){
	        for(i=0;i<NumSocks;i++)
	            FD_SET(ServSock[i],&SockSet);
	    }
	   	for(i=0;i<NumSocks;i++){
	    	if (FD_ISSET(ServSock[i],&SockSet)){
	        	FD_CLR(ServSock[i],&SockSet);
	        	break;
	        }
	    }
	//USER INFORMATION:
		user_.resize(user_size);//when another individual logs in, do: user_size+=1 just before user_.resize(user_size);
}
