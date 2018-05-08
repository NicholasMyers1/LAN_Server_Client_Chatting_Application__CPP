#include "includesVoids.h"
void RECEIVE_COMMAND(){
	string subs[25]="";//from recv buffer each split up into one;
	int counter=0;//count the sub[n];
	cout<<"A COMMAND CAME IN;";//A COMMAND CAME IN;
	for(int n=0;n<sizeof(recvBuffer);n++){
		if(recvBuffer[n]!=' '){
			subs[counter]+=recvBuffer[n];
		}
		else{
			counter+=1;
		}
		if(recvBuffer[n]=='\0'){
			break;
		}
	}
	//DELETE THE NULL CHARACTER IN THE LAST PART OF THE LAST STRING;
	subs[counter].erase(subs[counter].length()-1,1);
	counter=0;
	if(subs[2]=="/online"){
		sendText="/online ";
		for(int n=0;n<user_size;n++){
			if(user_[n].username!=""&&user_[n].username!="\0"){
				sendText+=user_[n].username+",";
			}
		}
	}
	else if(subs[2]=="/logout"){//SPECIAL COMMAND;
		cout<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";
		//LOGOUT USER
		logVariable=user_[CURRID].username;
		logValue=6;
		LOG();//LOGOUT THE USER;
		cout<<user_[CURRID].username<<" logged out: "<<CURRID<<"\n";
		user_[CURRID].time_=0;
		user_[CURRID].username="";
		user_[CURRID].ip="";
		numUsersLoggedIn-=1;
		sendText="/logout";
		logValue=9;
	}
	for(int n=0;n<sendText.length();n++){
		sendBuffer[n]+=sendText[n];
	}
	//cout<<"sent???: "<<sendBuffer<<"\n";
}
