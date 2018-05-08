#include "includesVoids.h"
void RECEIVE(){
	bool checkSuccess=false;
	bool commandCameIn=false;
	USERID="\0";
	convert_.str("");
	int count_=0;
	sendText="";
	for(int n=0;n<(int)(strlen)(recvBuffer)/*sizeof(recvBuffer)*/;n++){
		if(recvBuffer[n]!=' '&&recvBuffer[n]!='\0'){
			USERID+=recvBuffer[n];
//					cout<<n<<"n";
		}
		else{
			break;
		}
	}
//			cout<<"userid: "<<USERID;//<<"||"<<recvBuffer[0];
	for(int n=0;n<USERID.length();n++){
		if(USERID[n]>=(int)48&&USERID[n]<=(int)57){
//					cout<<"inrange"<<USERID[n]<<"\n";
			checkSuccess=true;
		}
		else{
			checkSuccess=false;
		}
	}//is this for loop needed?
	if(checkSuccess==true){
		stringstream convert_(USERID);
		convert_>>CURRID;
		cout<<user_[CURRID].username<<"//";
		user_[CURRID].time_=GetTickCount();
		
		

		for(int n=0;n<(int)(strlen)(recvBuffer);n++){//check for a command;
			//cout<<recvBuffer[n]<<"||"<<n<<"\n";
			if(recvBuffer[n]==' '){
				count_+=1;
			}
			if(count_==2){
				n+=1;
				cout<<recvBuffer[n];
				if(recvBuffer[n]=='/'){
					commandCameIn=true;
					logVariable=recvBuffer;
					logValue=8;
					RECEIVE_COMMAND();
				}
				break;
			}
		}count_=0;
		
		
		//update the chat with a message of up to 50 characters ending with a \n;
		//id name message: //and textCount==0 initially and once past 24, it goes back to 0;
		//string text[25]-----string sendText;
		if(commandCameIn==false){
			string temp_;
			for(int n=0;n<(int)(strlen)(recvBuffer);n++){
				if(count_>=1){
					temp_+=recvBuffer[n];
				}
				if(recvBuffer[n]==' '){
					count_+=1;
				}
			}//cout<<"temp: "<<temp_<<"\n\n";
			for(int n=24;n>-1;n--){
				if(count_!=1){
					if(n!=0){
						text[n]=text[n-1];
					}
					else{
						text[n]=temp_;
					}
				}
				sendText+=text[n]+"\n";
			}
			for(int n=0;n<sendText.length();n++){
				sendBuffer[n]+=sendText[n];
			}
			logVariable=recvBuffer;
			logValue=5;
		}
//			cout<<sendText<<"\nsend: "<<sendBuffer<<"\n";
	}//confirm connection is valid through ip address, username, and current user id;
	else{
		logVariable=recvBuffer;
		logValue=7;
	}
	if(USERID=="\0"||recvBuffer[user_[CURRID].username.length()+USERID.length()+1+1+1]=='\0'){
		cout<<recvBuffer<<"recvbuflength";
		logValue=9;//NOTHING;
	}
}
