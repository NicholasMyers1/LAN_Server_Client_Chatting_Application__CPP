#include "includesVoids.h"
void INIT(){
	//SERVER INFO:
		read_.open("_IPS.cfg");
		if(!read_){//if the file is non-existent:
			read_.close();
			write_.open("_IPS.cfg");//write_<<writeMe;
			write_.close();
		}read_.close();
		read_.open("_IPS.cfg");
		while(!read_.eof()&&readCounter<10){
			getline(read_,readMe);
			for(int n=0;n<readMe.length();n++){
				ipSave[readCounter]+=readMe[n];//read the entire ip line;
				if(readMe[n]=='\0'){
					ipSave[readCounter]="";
				}
			}readCounter+=1;
		}read_.close();readCounter=0;
	//TEXT:
		TEXT_WRITE.text="/";
		textPos=1;
		cmdMode=true;
		//TXT CMDS:		
			TEXT_CMD[0].text="/help Search through commands for help. ex: /help 0 to list page 1 of commands or /help c to get any command that starts with c";
			TEXT_CMD[1].text="/exit Closes the window.";//fix this;
			TEXT_CMD[2].text="/ips List, add, or delete up to ten IP's";
			TEXT_CMD[3].text="/connect (Connect to an ip) ex: /connect 192.168.1.111 or connect 0,1,2...";
			TEXT_CMD[4].text="/create ex: /create user pass pass";
			TEXT_CMD[5].text="/login ex: /login user pass after connecting to the server.";
			TEXT_CMD[6].text="/logout Logs you out and disconnects you from the server.";
			TEXT_CMD[7].text="/online This lists the users currently online.";
	for(int n=2;n<12;n++){
		CMD_OUTPUT[n].text=(n+46);
		CMD_OUTPUT[n].text+=": "+ipSave[n-2];
	}
	CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;//bottom layer;
	CMD_OUTPUT[1].text=TEXT_CMD[0/*1*/].text;//bottom layer+1;
}
