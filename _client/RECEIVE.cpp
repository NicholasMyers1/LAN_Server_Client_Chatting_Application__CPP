#include "includesVoids.h"
void RECEIVE(){
	string doStuff[50]="";
	int count=0;
	for(int n=0;n<sizeof(recvbuf);n++){
		if(recvbuf[n]!=' '){
			doStuff[count]+=recvbuf[n];
		}
		else{
			count+=1;
		}
		if(recvbuf[n]=='\0'){
			break;
		}
	}
	doStuff[count].erase(doStuff[count].length()-1,1);
//	cout<<doStuff[0]<<"|"<<doStuff[1]<<"|"<<doStuff[2]<<"|dostuff";
	if(loggedIn==false){
		if(doStuff[1]=="successful"&&doStuff[2]=="login"){
			for(int n=0;n<25;n++){
				CMD_OUTPUT[n].text="";
			}
			loggedIn=true;
			userID=doStuff[0];
//			cout<<"LOGGEDIN TRUE";
			cmdMode=false;
			TEXT_WRITE.text="";
			textPos=0;
		}
		else{
			username="";
			userID="";;
		}
	}
	else if(loggedIn==true){//if logged in is true:
		cout<<recvbuf<<"<---\n";
		if(doStuff[0]=="/online"){
			cout<<"online";
			//do some \n stuff and subtract 1 eventually: 
			//for now: start at 24-1: CMD_OUTPUT[23]
			CMD_OUTPUT[23].text=doStuff[1];
		}
		else if(doStuff[0]=="/logout"){
			for(int n=0;n<25;n++){
				TEXT_LIST[n].text="";
			}
			for(int n=2;n<12;n++){
				CMD_OUTPUT[n].text=(n+46);
				CMD_OUTPUT[n].text+=": "+ipSave[n-2];
			}
			CMD_OUTPUT[1].text="You can now connect to another server or reconnect as you have logged out.";
			CMD_OUTPUT[0].text=TEXT_CMD[3].text;
			loggedIn=false;
			connected=false;
			username="";
			userID="";
			TEXT_WRITE.text="/";
			textPos=1;
		}
	}
}
