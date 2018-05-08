#include "includesVoids.h"
void COMMANDS(){//ONLY IF ENTER WAS PRESSED AND '/' WAS THE FIRST CHARACTER IN THE ENTERED STRING;
	string subCmds[50];//this means every part of the commnand: ex: /help or /login user pass ...
	int subCmdCounter=0;
	for(int n=0;n<25;n++){
		CMD_OUTPUT[n].text="";
	}
	for(int n=0;n<TEXT_WRITE.text.length();n++){
		if(TEXT_WRITE.text[n]!=' '){
			subCmds[subCmdCounter]+=TEXT_WRITE.text[n];
		}
		else{
			subCmdCounter+=1;
		}
	}
	if(subCmds[0]=="/connect"){
		string holder_="";
		if(connected==false){
			if((int)subCmds[1][0]>=(int)48&&(int)subCmds[1][0]<(int)58&&subCmds[1][1]=='\0'){//0-9 in saved ips;
				for(int n=0;n<ipSave[(int)subCmds[1][0]-48].length();n++){
//					cout<<ipSave[(int)subCmds[1][0]-48][n]<<"|";
					if(ipSave[(int)subCmds[1][0]-48][n]!=' '){
						holder_+=ipSave[(int)subCmds[1][0]-48][n];
					}
					else{//cout<<"space";
						n=ipSave[(int)subCmds[1][0]-48].length();
					}
				}
//				cout<<"holder:"<<holder_;
				IP_=holder_.c_str();//the user entered ip address;
				keepIP_=holder_;
			}
			else{
				IP_=subCmds[1].c_str();//the user entered ip address;
				keepIP_=subCmds[1];//the below is basically an else if because it is only for if a user enters 0-9 to connect to a saved ip;				
			}
//			cout<<"test";
			if(subCmds[1]!=""||subCmds[1]!="\0"){
				SERVER();//from here, attempt the connection;
			}
			else{
				for(int n=1;n<11;n++){
					CMD_OUTPUT[n].text=(n+47);
					CMD_OUTPUT[n].text+=": "+ipSave[n-1];
				}
				CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;
			}
		}
		else{//if logged in, don't allow the ip to change;
			CMD_OUTPUT[0].text="Already connected. To leave the server, logout.";//??????????????
		}
	}
	else if(subCmds[0]=="/ips"){
		int loc=0;
		if(connected==false){
			if(subCmds[1]!=""||subCmds[1]!="\0"){//add the ip;
				if(subCmds[1]=="add"&&subCmds[2]!=""||subCmds[1]=="add"&&subCmds[2]!="\0"){//add the ip to the ip file;
					for(int n=0;n<10;n++){
						if(ipSave[n]==""){
							ipSave[n]=subCmds[2];
							loc=n;
							n=10;
						}
						if(n==9){//all ipslots filled up;
							for(int n=3;n<13;n++){
								CMD_OUTPUT[n].text=(n+45);
								CMD_OUTPUT[n].text+=": "+ipSave[n-3];
							}
							CMD_OUTPUT[2].text="You attempted to add an ip, but all of the slots are filled up. Delete one first.";
							CMD_OUTPUT[1].text=TEXT_CMD[2/*7*/].text;
							CMD_OUTPUT[0].text="Delete ipNumInList ex: /ips delete 0 (The '0' or number(0-9) coorelates the ip to the slot number.)";
						}
					}
					for(int n=3;n<50;n++){
						if(subCmds[n]!=""||subCmds[n]!="\0"){
							ipSave[loc]+=" "+subCmds[n];
						}
					}
					write_.open("_IPS.cfg");//write_<<writeMe;
					for(int n=0;n<10;n++){
						if(ipSave[n]!=""){
							write_<<ipSave[n]+"\n";
						}
						else{
							write_<<"\n";
						}
					}write_.close();
					if(CMD_OUTPUT[0].text!="Delete ipNumInList ex: /ips delete 0 (The '0' or number(0-9) coorelates the ip to the slot number.)"){
						CMD_OUTPUT[0].text="You have successfully saved the ip address of ";//+ipSave[loc]+" for future access.";	
						for(int n=0;n<ipSave[loc].length();n++){
							if(ipSave[loc][n]!=' '){
								CMD_OUTPUT[0].text+=ipSave[loc][n];
							}
							else{//cout<<"space";
								n=ipSave[loc].length();
							}
						}CMD_OUTPUT[0].text+=" for future access.";
					}
				}
				else if(subCmds[1]=="delete"&&subCmds[2]!=""&&(int)subCmds[2][0]>=(int)48&&(int)subCmds[2][0]<(int)58&&subCmds[2][1]=='\0'
				||		subCmds[1]=="delete"&&subCmds[2]!="\0"&&(int)subCmds[2][0]>=(int)48&&(int)subCmds[2][0]<(int)58&&subCmds[2][1]=='\0'){//delete the ip;//update the ip file;
					CMD_OUTPUT[0].text="You have successfully deleted the ip address of ";
					for(int n=0;n<ipSave[(int)subCmds[2][0]-48].length();n++){
						if(ipSave[(int)subCmds[2][0]-48][n]!=' '){
							CMD_OUTPUT[0].text+=ipSave[(int)subCmds[2][0]-48][n];
						}
						else{//cout<<"space";
							n=ipSave[(int)subCmds[2][0]-48].length();
						}
					}
					CMD_OUTPUT[0].text+=" from slot: ";CMD_OUTPUT[0].text+=(char)((subCmds[2][0]));
					ipSave[(int)subCmds[2][0]-48]="";
//					cout<<"test working delete";
					write_.open("_IPS.cfg");//write_<<writeMe;
					for(int n=0;n<10;n++){
						if(ipSave[n]!=""){
							write_<<ipSave[n]+"\n";
						}
						else{
							write_<<"\n";
						}
					}write_.close();
				}
				else{
					for(int n=4;n<14;n++){
						CMD_OUTPUT[n].text=(n+44);
						CMD_OUTPUT[n].text+=": "+ipSave[n-4];
					}
					CMD_OUTPUT[3].text="You entered an incorrect ips command.";
					CMD_OUTPUT[2].text=TEXT_CMD[2/*7*/].text;
					CMD_OUTPUT[1].text="Add an ip and a description ex: /ips add 192.168.1.111 'this is my friends server'";
					CMD_OUTPUT[0].text="Delete ipNumInList ex: /ips delete 0 (The '0' or number(0-9) coorelates the ip to the slot number.)";
				}
			}
			else{
				for(int n=3;n<13;n++){
					CMD_OUTPUT[n].text=(n+45);
					CMD_OUTPUT[n].text+=": "+ipSave[n-3];
				}
				CMD_OUTPUT[2].text=TEXT_CMD[2/*7*/].text;
				CMD_OUTPUT[1].text="Add an ip and a description ex: /ips add 192.168.1.111 'this is my friends server'";
				CMD_OUTPUT[0].text="Delete ipNumInList ex: /ips delete 0 (The '0' or number(0-9) coorelates the ip to the slot number.)";
			}
		}
		else{
			CMD_OUTPUT[0].text="Already connected. To edit the ips, logout.";//??????????????
		}
	}
	else if(subCmds[0]=="/login"){
		if(loggedIn==false&&connected==false){
			for(int n=2;n<12;n++){
				CMD_OUTPUT[n].text=(n+46);
				CMD_OUTPUT[n].text+=": "+ipSave[n-2];
			}
			CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;
			CMD_OUTPUT[1].text="Please connect to a server before logging in.";
		}
		else if(loggedIn==false&&connected==true){
			if(subCmds[1]=="\0"&&subCmds[2]=="\0"||subCmds[1]==""&&subCmds[2]==""){
				CMD_OUTPUT[0].text=TEXT_CMD[5/*3*/].text;
			}
			else{
				for(int n=0;n<TEXT_WRITE.text.length();n++){
					sendbuf[n]=TEXT_WRITE.text[n];
				}
				username=subCmds[1];
//				cout<<"login";
			}
		}
		else if(loggedIn==true){
			CMD_OUTPUT[0].text="Already logged in.";
		}
	}
	else if(subCmds[0]=="/logout"){//no need for a /logout help command;
		if(loggedIn==true&&connected==true){
			
			
			string connectAll=userID+" "+username+": "+subCmds[0];
			for(int n=0;n<connectAll.length();n++){
				sendbuf[n]=connectAll[n];
			}			
		}
		else if(loggedIn==false&&connected==false){
			for(int n=2;n<12;n++){
				CMD_OUTPUT[n].text=(n+46);
				CMD_OUTPUT[n].text+=": "+ipSave[n-2];
			}
			CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;
			CMD_OUTPUT[1].text="Please connect to a server before logging out.";
		}
		else if(loggedIn==false&&connected==true){
			for(int n=3;n<13;n++){
				CMD_OUTPUT[n].text=(n+45);
				CMD_OUTPUT[n].text+=": "+ipSave[n-3];
			}
			CMD_OUTPUT[2].text="You were not logged in, but you were disconnected from the server.";//make a disconnect command?;
			CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;
			CMD_OUTPUT[1].text="Please connect to a server before logging in.";
			loggedIn=false;
			connected=false;
		}
	}
	else if(subCmds[0]=="/create"){
		if(loggedIn==false&&connected==false){
			for(int n=2;n<12;n++){
				CMD_OUTPUT[n].text=(n+46);
				CMD_OUTPUT[n].text+=": "+ipSave[n-2];
			}
			CMD_OUTPUT[0].text=TEXT_CMD[3/*2*/].text;
			CMD_OUTPUT[1].text="Please connect to a server before creating an account.";
		}
		else if(loggedIn==false&&connected==true){
			if(subCmds[1]=="\0"&&subCmds[2]=="\0"&&subCmds[3]=="\0"||subCmds[1]==""&&subCmds[2]==""&&subCmds[3]==""){
				CMD_OUTPUT[0].text=TEXT_CMD[4/*5*/].text;
			}
			else{
				if(subCmds[2]==subCmds[3]&&subCmds[1]!=subCmds[2]){
					for(int n=0;n<TEXT_WRITE.text.length();n++){
						sendbuf[n]=TEXT_WRITE.text[n];
					}
				}
				username=subCmds[1];
//				cout<<"create";
			}
		}
		else if(loggedIn==true){
			CMD_OUTPUT[0].text="Already logged in.";
		}
	}
	else if(subCmds[0]=="/exit"){
		CMD_OUTPUT[0].text=TEXT_CMD[1/*6*/].text;
		exit(0);
	}
	else if(subCmds[0]=="/help"){
		int cmdCount=0;
		int cmdList=0;
		string search_="";
		bool searchFound=false;
		if(subCmds[1]==""||subCmds[1]=="\0"){
			CMD_OUTPUT[0/*1*/].text=TEXT_CMD[0/*1*/].text;//bottom layer+1;
		}
		//fix the below for anything 01 etc, does not show up;
		else if((int)subCmds[1][0]>=(int)48&&(int)subCmds[1][0]<(int)58&&(int)subCmds[1].length()<2
		||		(int)subCmds[1][0]>=(int)48&&(int)subCmds[1][0]<(int)58&&(int)subCmds[1][1]>=(int)48&&(int)subCmds[1][1]<(int)58&&(int)subCmds[1].length()<3&&subCmds[1][0]!='0'){
			if(subCmds[1][0]>=(int)53&&subCmds[1][1]>=(int)48){//greater than 49 range is from 0 to 49 to get the 50 pages for the 1000 commands;
//				cout<<"greater than 49 range is from 0 to 49 to get the 50 pages for the 1000 commands\n";
				CMD_OUTPUT[1].text=TEXT_CMD[0/*1*/].text;//bottom layer+1;
				CMD_OUTPUT[0].text="Your search for a command was not found.";//bottom layer+1;	
			}
			else{
				cmdCount=atoi(subCmds[1].c_str());//page number converted to an integer;
//				cout<<cmdCount;
				CMD_OUTPUT[20].text="Command page: "+subCmds[1];
				for(int n=19;n>-1;n--){
					CMD_OUTPUT[n].text=TEXT_CMD[(cmdCount*20)+cmdList].text;
					cmdList+=1;
				}
			}
		}
		else{
			for(int n=0;n<1000;n++){
				for(int m=1;m<TEXT_CMD[n].text.length();m++){
					if(TEXT_CMD[n].text[m]!=' '){
						search_+=TEXT_CMD[n].text[m];
						cmdList+=1;
					}
					else{
						m=TEXT_CMD[n].text.length();
					}
				}
				if(cmdList==subCmds[1].length()&&search_==subCmds[1]){
					CMD_OUTPUT[0].text=TEXT_CMD[n].text;
					n=1000;//command is true and found;
				}
				else{
					for(int o=0;o<subCmds[1].length();o++){
						if(subCmds[1][o]==search_[o]){
							searchFound=true;
						}
						else{
							searchFound=false;
							o=subCmds[1].length();
						}
					}
					if(searchFound==true){
						if(CMD_OUTPUT[0].text==""){
							CMD_OUTPUT[0].text+="/"+search_;
						}
						else{
							CMD_OUTPUT[0].text+=" /"+search_;
						}
					}
				}
				searchFound=false;
				cmdList=0;
				search_="";
			}
			if(CMD_OUTPUT[0].text==""){
				CMD_OUTPUT[0].text="Your search for the command of: "+subCmds[1]+" produced no results.";
			}
			else{
				CMD_OUTPUT[1].text="Your search for the command of: "+subCmds[1]+" produced the following results: ";
			}
		}
	}
	else if(subCmds[0]=="/online"){
		if(connected==true&&loggedIn==true){
			CMD_OUTPUT[24].text="Here are the current users online: ";
			string connectAll=userID+" "+username+": "+subCmds[0];
			for(int n=0;n<connectAll.length();n++){
				sendbuf[n]=connectAll[n];
			}
		}
		else{
			CMD_OUTPUT[0].text=TEXT_CMD[0].text;
			CMD_OUTPUT[1].text="Please connect to a server and login before viewing the online list.";
		}
	}
	else if(subCmds[0][0]=='/'){
		CMD_OUTPUT[0].text=TEXT_CMD[0/*1*/].text;//bottom layer+1;
	}
	else if(connected==false){
		CMD_OUTPUT[0].text=TEXT_CMD[0/*1*/].text;//bottom layer+1;
	}
	else{
		//STUFF FOR NOT SENDING A COMMAND;
	}
}
