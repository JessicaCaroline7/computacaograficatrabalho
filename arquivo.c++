#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLdouble move=0;
GLdouble direcao=1;
GLdouble mov=0;
GLdouble direc=1;

static void Init() 
{                                 
  GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};     // Define ponto de luz
  GLfloat mat_shininess[]= {50.0};                   // Define brilho da superfície
  GLfloat light_position[] = {50.0, 100.0, 100.0, 0.0}; // Define posição da fonte de luz
  glShadeModel(GL_SMOOTH);                           // Transições suaves nas bordas
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // Propriedades do material
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); // Propriedades do material
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);   // Define Luz
  glColorMaterial(GL_FRONT,GL_DIFFUSE);                // Define capacidade de cor

  glEnable(GL_COLOR_MATERIAL);		   // Habilita cor
  glEnable(GL_LIGHTING);		       // Habilita iluminação da superfície
  glEnable(GL_LIGHT0);			       // Habilita fonte de luz
  glEnable(GL_DEPTH_TEST); 		       // Habilita buffer de profundidade
}

static void Reshape(int width, int height) 
{         
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.00, 30.0); // Perspectiva
  gluLookAt(0.0, 2.5, 3.0, 0.0, -1.5, -1.0, 0.0, 1.0, 0.0); //Vizualização

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glLoadIdentity();
}

static void display() {
  static double x; // Declaração de variável
  x+=0.03; // Valor da variável x 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );  // Limpar cor e profundidade
  //Sol
  glPushMatrix();              		// Começa desenhar
    glRotatef( x,0.0,1.0,0.0);  	// Girar
    glColor3f(1.1, 0.96, 0.0);		// Cor Mostarda 1 0.86 0.35
    glutSolidSphere(0.25,30,20);		// Desenha esfera
    
    //Planeta 1
  glPushMatrix();
    glRotatef( 0.07,0.0,1.0,0.0);			  
    glTranslatef(0.5,0.0,-1.4);	  // Afasta da origem
    glColor3f(0.42,0.35,0.8);       // Planeta Azul Ardósia 
    glutSolidSphere(0.1,20,16);	  // Desenha planeta 1
   
   //Lua   
  glPushMatrix();			     
      glRotatef( x, 0.0, 1.0, 0.0);	     // Girar
      glTranslatef(0.3,0.0,0.0);	     // Mover através do ponto
      glColor3f(0.66,0.66,0.66);		 // Cor Cinza
      glutSolidSphere(0.025,10,6);	     // Desenha lua
      glPopMatrix();			        // Retornar ao anterior
      
  glPopMatrix();			// Retornar ao anterior
    
    //Planeta 2
  glPushMatrix();
      glRotatef( x,0.0,1.0,0.0);			  
      glTranslatef(-0.5,0.0,0.7);	  // Mover através do ponto
      glColor3f(0.48,0.63,0.36);	  // Cor aspargo 
      glutSolidSphere(0.15,20,16);	  // Desenha planeta 2
      glPopMatrix();			     // Retornar ao anterior
      
      //Planeta 3
  glPushMatrix();	
      glRotatef( x+0.02,0.0,1.0,0.0);		  
      glTranslatef(2.0,0.0,-1.0);	  // Mover através do ponto
      glColor3f(0.94,0.9,0.55);	  // Cor caqui
      glutSolidSphere(0.13,20,16);	  // Desenha planeta 2
      glPopMatrix();			     // Retornar ao anterior
      
      //Planeta 4
  glPushMatrix();	
      glRotatef( x+0.02,0.0,1.0,0.0);		  
      glTranslatef(1.0,-1.5,1.5);	  // Mover através do ponto
      glColor3f(0.89,0.15,0.21);	  // Cor Alizarim
      glutSolidSphere(0.13,20,16);	  // Desenha planeta 2
      
       //Lua   
  glPushMatrix();			     
      glRotatef( x, 0.0, 1.0, 0.0);	     // Girar
      glTranslatef(0.3,0.0,0.0);	     // Mover através do ponto
      glColor3f(1.0,0.89,0.89);		 // Cor rosa embaçado
      //glutSolidSphere(0.025,10,6);	     // Desenha lua
      glutSolidCone(0.025, 0.05, 10, 6);
      
      glPopMatrix();			        // Retornar ao anterior
      
  glPopMatrix();			// Retornar ao anterior
      
      //Planeta 5
  glPushMatrix();	
      glRotatef( x+0.04,0.0,1.0,0.0);		  
      glTranslatef(0.5,1.0,1.0);	  // Mover através do ponto
      glColor3f(0.87,0.63,0.87);	  // Cor Ameixa
      glutSolidSphere(0.13,20,16);	  // Desenha planeta 2
      glPopMatrix();
      
      //Planeta com anel
       glPushMatrix();
    glRotatef (x+0.08, 0.0, 1.0, 1.0);
    glTranslatef(-1.0, 1.0, 0.8); 
    glColor3f(0.82, 0.71, 0.55); //Cor canela
    glutSolidTorus(0.01, 0.07, 9, 20); //Anel
    glutSolidSphere(0.05, 20, 16); //Esfera
    glPopMatrix();
    
      //Planeta Anão
  glPushMatrix();	
      glRotatef( x+0.05,0.0,1.0,0.0);		  
      glTranslatef(0.5,0.3,0.7);	  // Mover através do ponto
      glColor3f(1.0,0.65,0.0);	  // Cor Laranja
      glutSolidSphere(0.04,5,3);	  // Desenha planeta 2
      
      glPopMatrix();
        
  glPopMatrix();		      // Retornar a base
  
  //cometas - pequenas esferas que simulam cometas, em movimento.
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-6.9, move+8.6, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.007, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.1, move+8.8, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.006, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.3, move+8.7, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.008, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.5, move+9.0, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.009, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.7, move+8.9, 0.7);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.006, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.8, move+8.6, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.009, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.6, move+8.8, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.008, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.4, move+8.7, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.006, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.2, move+9.0, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.007, 5, 3);
  glPopMatrix();
  glPushMatrix();
      glRotatef (mov+0.4, 0.0, 1.0, 1.0);
      glTranslatef(mov-7.0, move+8.9, 0.0);
      glColor3f(0.41, 0.41, 0.41); //Cor cinza
      glutSolidSphere(0.008, 5, 3);
  glPopMatrix();
  
  //Desenho de uma nave 
  glLoadIdentity(); //Iniciar o desenho
  glRotatef(0.05,0.0,0.0,0.5);
  glTranslatef(0.0,0.3,0.7);
  glPushMatrix();
  glBegin(GL_POLYGON); //Desenhar poligno
  
  glColor3f(0.75, 0.75, 0.75); //Cinza claro
  glVertex2f(move+1.90, move+1.91);
  glVertex2f(move+2.00, move+1.94);
  glColor3f(0.41, 0.41, 0.41); //Cinza escuro
  glVertex2f(move+1.90, move+1.89);
  glVertex2f(move+1.85, move+1.92);
  glColor3f(0.54, 0.17, 0.89); //Azul violeta 
  glVertex2f(move+1.90, move+1.94);
  glVertex2f(move+2.00, move+1.94);
  
  glEnd(); //Finalizar o desenho
  
  // Nave Inimiga
  glLoadIdentity(); //Iniciar o desenho
  glRotatef(0.05,0.0,0.0,0.5);
  glTranslatef(0.0,0.3,0.7);
  glPushMatrix();
  glBegin(GL_POLYGON); //Desenhar um poligno
  
  glColor3f(0.75, 0.75, 0.75); //cinza claro
  glVertex2f(move+2.23, move+2.18);
  glVertex2f(move+2.18, move+2.23);
  
  glColor3f(0.5, 0.5, 0.5); //cinza
  glVertex2f(move+2.18, move+2.26);
  glVertex2f(move+2.23, move+2.31); 
  glVertex2f(move+2.23, move+2.30);
  glVertex2f(move+2.23, move+2.23);
  glVertex2f(move+2.30, move+2.23);
  glVertex2f(move+2.26, move+2.26);
  
  glColor3f(0.75, 0.75, 0.75);//cinza claro
  glVertex2f(move+2.26, move+2.31);
  glVertex2f(move+2.29, move+2.26);

  glColor3f(0.55, 0.0, 0.0); //vermelho escuro
  glVertex2f(move+2.29, move+2.23);
  glVertex2f(move+2.26, move+2.13);
  glEnd(); //Finalizar o desenho
   
  glFlush();			      
  glutSwapBuffers();		      // Swap de buffers
  glutPostRedisplay();		      // Mostrar os resultados
}

void nave(int passo) // Função de movimento com tempo
{
  if(direcao==1)
  {
     move -= 0.1;
     if(move==1) 
     direcao = 0;
   }

  else
  {
    move += 0.1;
    if(move==+2) 
    direcao = 1;
  }
  glutPostRedisplay();
  glutTimerFunc(250,nave, 1);

}
void cometa(int passo) //Função de movimento com tempo
{
  if(direc==1)
  {
     mov += 0.1;
     if(mov==1) 
     direc = 0;
   }

  else
  {
    mov -= 0.1;
    if(mov==+2) 
    direc = 1;
  }
  glutPostRedisplay();
  glutTimerFunc(250,cometa, 1);

}

void keyboard(unsigned char key, int x, int y) //Função de tecla
{
  switch (key) 
  {
    case 27: //Tecla ESC
	  exit(0);
	break;
  }
}
int main(int argc, char** argv) 
{	
  glutInit(&argc,argv);  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); // Inicializa modos
  glutInitWindowSize( 950, 650); //Tamanho da janela
  glutInitWindowPosition( 50, 50); //Posição dentro da janela
  glutCreateWindow( "Espaço"); //Nome da janela
  Init();
  glClearColor(0.0,0.0,0.0,0.0); //Cor do fundo
  
  glutDisplayFunc(display); //Chama a função Display
  glutTimerFunc(250,cometa,1); //Chama a função de movimento
  glutTimerFunc(250,nave,1); //Chama a função de movimento
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(keyboard); //Chama a função de teclado
  glutMainLoop(); //Loop na Main
  return 0;
}
