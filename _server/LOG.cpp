#include "includesVoids.h"
void LOG(){
	int count_=0;
	/*	
	(-1)=SERVER START
	(0)=NOBODY CONNECTED
	(1)=FAIL CREATE
	(2)=FAIL LOGIN
	(3)=SUCCESS CREATE AND LOGGEDIN
	(4)=SUCCESS LOGIN
	(5)=MESSAGE CAME IN
	(6)=A USER LOGGED OUT
	(7)=UNAUTHORIZED CONNECTION
	(8)=A COMMAND CAME IN
		(9)=do nothing;
	*/
	/*check the ip address and match it with the loggedin ip address if fail log (7)???????????????????????*/
	cout<<"logval<<"<<logValue<<"\n";
	if(logValue!=0&&logValue!=-1&&logValue!=9){//if not 0, someone is connected;
		write_.open("_LOG.log",ios::app);
		if(logValue==1){//fail create;
			// connected at: "+"ADDTIMEDATEHERE"+" and failed to create an account with the name of: "+"ADDNAMEHERE";
			logStr="(1) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=" and failed to create an account with the name of: ";
			logStr+=logVariable;
		}
		else if(logValue==2){//fail login;
			logStr="(2) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=" and failed to login with the name of: ";
			logStr+=logVariable;
		}
		else if(logValue==3){//success create and now logged in;
			logStr="(3) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=" and successfully created an account and logged in with the name of: ";
			logStr+=logVariable;
		}
		else if(logValue==4){//success login;
			//logStr+="(4) The IP of: ";//+/*Hostname*/"ADDIPHERE"+" connected at: "+"ADDTIMEDATEHERE"+" and successfully logged in with the name of: "+"ADDNAMEHERE";
			logStr="(4) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=" and successfully logged in with the name of: ";
			logStr+=logVariable;
		}
		else if(logValue==5){//typical message received from client;
			logStr="(5) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=": with the message of: ";
			logStr+=logVariable;
		}
		else if(logValue==6){//a user logged out;
			logStr="(6) The IP of: ";logStr+=Hostname;logStr+=" successfully logged out at: ";logStr+="ADDTIMEDATEHERE";logStr+=": with the name of: ";
			logStr+=logVariable;
		}
		else if(logValue==7){//unauthorized on server;
			logStr="(7) /**//**//**//**/ An unauthorized connection from the IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=": with the message of: ";
			logStr+=logVariable;logStr+="/**//**//**//**/";
		}
		else if(logValue==8){//a command was sent in;
			logStr="(8) The IP of: ";logStr+=Hostname;logStr+=" connected at: ";logStr+="ADDTIMEDATEHERE";logStr+=": with the command of: ";
			logStr+=logVariable;
		}
		//???????????????logStr+="\n";
		write_<<logStr;
		write_<<"\n";
		write_.close();
	}
	else if(logValue==-1){//server started;
		write_.open("_LOG.log",ios::app);
		logStr="(-1) ----------------------The server has successfully started: ----------------------";logStr+=" at the time of: ";logStr+="ADDTIMEDATEHERE";logStr+=" with the IP of: ";
		logStr+=Address;
		//???????????????logStr+="\n";
		write_<<logStr;
		write_<<"\n";
		logValue=0;
		write_.close();
	}
	else if(logValue==0){
		write_.open("_LOG.log",ios::app);
		logStr="(0) ----------------------Nobody is connected to the server at this time: ----------------------";logStr+=" at the time of: ";logStr+="ADDTIMEDATEHERE";logStr+=" with the IP of: ";
		logStr+=Address;//+"ADDTIMEDATAHERE";
		//???????????????logStr+="\n";
		write_<<logStr;
		write_<<"\n";
		write_.close();
	}
	else if(logValue==9){
		logStr="";
		cout<<"NULL DO NOT WRITE TO LOG FILE";
	}
	logStr="";
	logVariable="";
}
