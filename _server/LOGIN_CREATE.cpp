#include "includesVoids.h"
void LOGIN_CREATE(){
	string subs[25]="";//from recv buffer each split up into one;
	int counter=0;//count the sub[n];
	string send1="";//what to send back to the client;
	for(int n=0;n<sizeof(recvBuffer);n++){
		if(recvBuffer[n]!=' '){
			subs[counter]+=recvBuffer[n];
		}
		else{
			counter+=1;
		}
		if(recvBuffer[n]=='\0'){
			counter=0;
			break;
		}
	}
	if(subs[0]=="/create"){
		bool allowCreate=true;
//		cout<<"attempt to login:";
		reade_.open("_USERLIST.txt");
		while(!reade_.eof()){
			getline(reade_,readMe);
			if(readMe==subs[1]){//cout<<"dd";
				allowCreate=false;
			}
			if(readMe=="\0"){
				break;
			}
		}reade_.close();
		if(allowCreate==true){
			write_.open("_USERINFO.txt",ios::app);//write_<<writeMe;
				write_<<subs[1]+" "+subs[2]<<"\n";
			write_.close();
			write_.open("_USERLIST.txt",ios::app);//write_<<writeMe;
				write_<<subs[1]<<"\n";
			write_.close();

			
			
//		cout<<"success create";
			convert_<<user_size;
			send1=convert_.str();//+" ";
			send1+=" successful login";//create success;
//			cout<<"|"<<send1<<"<--send1\n\n\n\n";
			
			for(int n=0;n<send1.length();n++){
				sendBuffer[n]=send1[n];
			}
			user_size+=1;
			user_.resize(user_size);//increase array size, so there is no boundary failure: 
			user_[user_size-1/*usersLoggedIn*/].time_=GetTickCount();
			user_[user_size-1/*usersLoggedIn*/].username=subs[1];
			user_[user_size-1/*usersLoggedIn*/].ip=Hostname;
			numUsersLoggedIn+=1;//increase num users connected;
			logVariable=subs[1];
			logValue=3;
		}
		else{
//			cout<<"fail create";
			send1="failed login";//create fail;
			for(int n=0;n<send1.length();n++){
				sendBuffer[n]+=send1[n];
			}
			//failed to create an account;
			logVariable=subs[1];
			logValue=1;
		}
	}	
	if(subs[0]=="/login"){
//		cout<<"attempt to login:";
		string userPass[2]="";
		reade_.open("_USERINFO.txt");
		if(subs[2]!=""||subs[2]!="\0"){
			subs[2].erase(subs[2].length()-1,1);
		}
		while(!reade_.eof()){
			getline(reade_,readMe);
			for(int n=0;n<readMe.length();n++){
				if(readMe[n]!=' '){
					userPass[counter]+=readMe[n];
				}
				else{
					counter+=1;
				}
			}counter=0;
			if(userPass[0]==subs[1]&&userPass[1]==subs[2]){
				break;
			}
			else{
				userPass[0]="";
				userPass[1]="";
			}
			if(readMe=="\0"){
				break;
			}
		}
		reade_.close();
		if(userPass[0]==subs[1]&&userPass[1]==subs[2]){
//		cout<<"success login";
			convert_<<user_size;
//			cout<<"usersize: "<<user_size<<"--\n";
			send1=convert_.str();//+" ";
			send1+=" successful login";//create success;
//			cout<<"|"<<send1<<"<--send1\n\n\n\n";
			for(int n=0;n<send1.length();n++){
				sendBuffer[n]+=send1[n];
			}
			user_size+=1;
			user_.resize(user_size);//increase array size, so there is no boundary failure: 
			user_[user_size-1/*usersLoggedIn*/].time_=GetTickCount();
			user_[user_size-1/*usersLoggedIn*/].username=subs[1];
			user_[user_size-1/*usersLoggedIn*/].ip=Hostname;
			numUsersLoggedIn+=1;//increase num users connected;
			logVariable=subs[1];
			logValue=4;
		}
		else{
//			cout<<"fail login";
			send1="failed login";//create fail;
			for(int n=0;n<send1.length();n++){
				sendBuffer[n]+=send1[n];
			}
			logVariable=subs[1];
			logValue=2;
		}
	}
	if(logValue!=9&&logValue!=1&&logValue!=2&&logValue!=3&&logValue!=4){
		logValue=7;//UNAUTHORIED SEND;
	}
}
