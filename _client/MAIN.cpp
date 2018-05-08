#include "includesVoids.h"
void mainV(){
	TEXTWRITE();
	getTime=GetTickCount();
			//static int mmm=0;
			//cout<<"count: "<<mmm<<" gt-ct: "<<(getTime-connectTime)<<"\t";
			//mmm+=1;
	if(connected==true&&getTime-connectTime>=175){//200?
		SERVER();
			//mmm=0;
	}
;}//end void;
void display(void){
	glLoadIdentity();
		glEnable(GL_TEXTURE_3D);
		glEnable(GL_NORMALIZE);
		glEnable(GL_POLYGON_OFFSET_FILL);
		glEnable(GL_COLOR_MATERIAL); 
		glEnable(GL_BLEND);glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glClearColor(0,0,0,1);
			glDepthFunc(GL_GEQUAL);glClearDepth(0);
    	mainV();
	    glutSwapBuffers();
		//glutFullScreen();
}//end void;
void reshape(GLint w, GLint h){
	glMatrixMode(GL_PROJECTION);//regular view;
		glLoadIdentity();
		glViewport(0,0,w,h);
		gluPerspective(90.f,(GLfloat)w/(GLfloat)h,0.0f,1.0f); 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}//end void;
int main(int argc,char **argv){												//main and set window properties;
	INIT();
	srand(time(NULL));
    glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/1.25,glutGet(GLUT_SCREEN_HEIGHT)/1.25);
    	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-glutGet(GLUT_SCREEN_WIDTH)/1.25)/2,(glutGet(GLUT_SCREEN_HEIGHT)-glutGet(GLUT_SCREEN_HEIGHT)/1.25)/2);
		glutCreateWindow("");
    glutPassiveMotionFunc(mousemoveunpressed);
    glutDisplayFunc(display);glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(skeyd);
    glutMouseFunc(mouseclick);
    glutMainLoop();
    return 0;
}
