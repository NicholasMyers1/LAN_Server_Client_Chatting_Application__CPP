#include "includesVoids.h"
void mousemoveunpressed(int x, int y){
	;
}//end void;
void mouseclick(int button,int state,int x,int y){
	;
;}//end void;
void skeyd (int key,int x,int y){
	if(key==GLUT_KEY_LEFT){
		if(textPos>0){
			textPos-=1;
		}
	}
	if(key==GLUT_KEY_RIGHT){
		if(textPos<TEXT_WRITE.text.length()){
			textPos+=1;
		}
	}
}//end void;
void keyPressed(unsigned char key,int x,int y){//glutKeyboardFunc(keyPressed);
	if(key==(int)8){//BACKSPACE;
		if(textPos>0){
			TEXT_WRITE.text.erase(textPos-1,1);
			textPos-=1;
		}
	}
	else if(key==(int)127){//DELETE;
		if(textPos<TEXT_WRITE.text.length()){
			TEXT_WRITE.text.erase(textPos,1);
		}
	}
	else if(key==(int)27){//ESCAPE;
		if(loggedIn==true){
			TEXT_WRITE.text="";
			textPos=0;
			if(cmdMode==true){
				cmdMode=false;
			}
		}
	}
	else if(key==(int)9){//TAB;
		;
	}
	else if(key==(int)13){//ENTER;
		if(TEXT_WRITE.text[0]=='/'||loggedIn==false){
			cmdMode=true;
			COMMANDS();
			TEXT_WRITE.text="/";
			textPos=1;
		}
		else{//if loggedin=true and a command was not sent:
			int count=0;
			bool spaceOrNull=true;
			for(int n=0;n<TEXT_WRITE.text.length();n++){
				if(TEXT_WRITE.text[n]==' '&&spaceOrNull==true||TEXT_WRITE.text[n]=='\0'&&spaceOrNull==true){
					count+=1;
				}
				else{
					spaceOrNull=false;
					break;
				}
			}
			if(TEXT_WRITE.text[0]=='\0'){
				spaceOrNull=true;;
			}
			else{
				TEXT_WRITE.text.erase(0,count);
			}
			if(spaceOrNull==false){
				string connectAll=userID+" "+username+": "+TEXT_WRITE.text;
				for(int n=0;n<connectAll.length();n++){
					sendbuf[n]=connectAll[n];
				}
//				SERVER();
			}
//			cout<<sendbuf<<"\n\n\n\n\n";
			cmdMode=false;
			textPos=0;
			TEXT_WRITE.text="";
		}
	}
	else if(TEXT_WRITE.text.length()<100){//ANYTHING ELSE;
		string dta;dta=key;
		TEXT_WRITE.text.insert(textPos,dta);
		textPos+=1;
	}
}//end void;
