#include "includesVoids.h"
void TEXTWRITE(){
	for(int n=0;n<=TEXT_WRITE.text.length();n++){//text writing;
		if(n<1){
			glLoadIdentity();
			glColor3f(1,1,1);
			glTranslatef(-1.775-.0125+(textPos*.0250),-.98,-1);
			glScalef(0.00025,0.00025,0);
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,'|');
		}
		if(n<TEXT_WRITE.text.length()){
			char m=TEXT_WRITE.text[n];
			glLoadIdentity();
			glColor3f(.5,.75,0);
			glTranslatef(-1.775+(n*.0250),-.98,-1);
			glScalef(0.00025,0.00025,0);
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,m);
		}
	}
	for(int n=0;n<25;n++){//text output;
		if(cmdMode==true){//text command output;
			for(int m=0;m<CMD_OUTPUT[n].text.length();m++){
				char o=CMD_OUTPUT[n].text[m];//TEXT_WRITE.text[m];
				glLoadIdentity();
				glColor3f(.5,.75,0);
				glTranslatef(-1.775+(m*.0250),-.93+(n*.05),-1);//+.05 from -.98 for y;
				glScalef(0.00025,0.00025,0);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,o);
			}
		}
		else{//text regular output;
			for(int m=0;m<TEXT_LIST[n].text.length();m++){
				char o=TEXT_LIST[n].text[m];//TEXT_WRITE.text[m];
				glLoadIdentity();
				glColor3f(.5,.75,0);
				glTranslatef(-1.775+(m*.0250),-.93+(n*.05),-1);
				glScalef(0.00025,0.00025,0);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,o);
			}
		}
	}
}
