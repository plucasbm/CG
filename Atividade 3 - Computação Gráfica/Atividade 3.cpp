/*
Equipe: 
	Igor Vinícius de Carvalho Trapiá
	Marcos Filipe Caravalho Costa
	Paulo Lucas Barros Matos
	
		*****Atividade 3 - Labirinto*****
*/

#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>

char texto[30], ganhou[30];
float Xr = 470.0, Yr = 0.0, altura = 30.0, largura = 30.0, incremento = 5.0f;
int Vidas = 3, button, state,mousex,mousey;
bool check=true;
float quad=1.0,fund=1.0, borda=0.0;

// ------------------------------------------------------------------------------------------Funções de Texto-----------------------------------------------------------------------------------
void DesenhaTexto(void *font, char *string){
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

void DesenhaTextoStroke(void *font, char *string){
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}

// Definição das condições das teclas especiais
void TeclasEspeciais(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT:
            Xr+=incremento;
            break;

        case GLUT_KEY_LEFT:
            Xr-=incremento;
        break;

        case GLUT_KEY_UP:
            Yr+=incremento;
            break;

        case GLUT_KEY_DOWN:
            Yr-=incremento;
        break;

        default:
         break;
    }
    glutPostRedisplay();



	
// ------------------------------------------------------------------------------------------------Limite da Tela--------------------------------------------------------------------------------------------
if(Xr<0){
	Xr=0;// Se a posição do boneco for menor que 0, o boneco continua na posição 0.
}
if(Xr+altura>500){
	Xr=470.0;
}
if(Yr<0){
	Yr=0;
}
if(Yr+largura>500){
	Yr=470.0;
}

//---------------------------------------------------------------------Somente Colisões Horizontais------------------------------------------------------------------------------------------------
// Primeira Linha de Colisão Horizontal

if((Xr+largura>=90 && Xr <=500) && (Yr+altura>=45 && Yr<=45)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;
	}

// Segunda Linha de Colisão Horizontal
if((Xr+largura>=0 && Xr <=350) && (Yr+altura>=90 && Yr<=90)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;
	}

// Terceira linha de Colisão Horizontal

if(((Xr+largura>=0 && Xr <=100) || (Xr+largura>=145 && Xr <=330) || (Xr+largura>=375 && Xr <=500)) && (Yr+altura>=135 && Yr<=135)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;
	}

// Quarta Linha de Colisão Horizontal
if(((Xr+largura>=50 && Xr<=300) || (Xr+largura>=353 && Xr<=455)) && (Yr+altura>=180 && Yr<=180)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}

//Quinta Linha de Colisão Horizontal
if(((Xr+largura>=0 && Xr<=50) || (Xr+largura>=140 && Xr <=240) || (Xr+largura>=355 && Xr<=455)) && (Yr+altura>=290 && Yr<=290)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;
	}
	
	
//Sexta Linha de Colisão Horinzonal

if(((Xr+largura>=45 && Xr<=230) || (Xr+largura>=330 && Xr<=500)) && (Yr+altura>=380 && Yr<=380)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Sétima Linha de Colisão Horizontal
if((Xr+largura>=230 && Xr<=455)  && (Yr+altura>=425 && Yr<=425)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
//Oitava Linha de Colisão Horizontal
if(((Xr+largura>=0 && Xr<=230) || (Xr+largura>=290 && Xr<=500)) && (Yr+altura>=470 && Yr<=470)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
//Nona Colisão Horizontal
if((Xr+largura>=300 && Xr<=405) && (Yr+altura>=290 && Yr<=290)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Décima Colisão Horizontal
if((Xr+largura>=400 && Xr<=500) && (Yr+altura>=230 && Yr<=230)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	

	
//------------------------------------------------------------------------------Somente Colisões Verticais--------------------------------------------------------------------------------------------------

//Primeira Colisão Vertical

if((Xr+largura>=95 && Xr<=95)  && (Yr+altura>=225 && Yr<=335)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}

//Segunda Colisão Vertical
if((Xr+largura>=190 && Xr<=190)  && (Yr+altura>=225 && Yr<=290)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Terceira Colisão Vertical
if((Xr+largura>=405 && Xr<=405)  && (Yr+altura>=290 && Yr<=335)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Quarta Colisão Vertical
if((Xr+largura>=300 && Xr<=300)  && (Yr+altura>=180 && Yr<=335)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Quinta Colisão Vertical
if((Xr+largura>=230 && Xr<=230)  && (Yr+altura>=380 && Yr<=427)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Sexta Colisão Vertical
if((Xr+largura>=150 && Xr<=150)  && (Yr+altura>=425 && Yr<=470)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
	
// Setima colisão Vertical
if((Xr+largura>=355 && Xr<=355)  && (Yr+altura>=180 && Yr<=290)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}
// oitava Colisão Vertical
if((Xr+largura>=190 && Xr<=190)  && (Yr+altura>=335 && Yr<=380)){

	Xr = 470.0;
	Yr = 0.0;
	Vidas -= 1;

	}

}

void desenhos(void)
{
	glClearColor(fund, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


//Personagem

	glColor3f(0.0f, 0.0f, quad);
	glBegin(GL_QUADS);
		glVertex2f(Xr,Yr+altura);
		glVertex2f(Xr+largura, Yr+altura);       
		glVertex2f(Xr+largura, Yr);       
		glVertex2f(Xr,Yr);
	glEnd();
	glColor3f(borda, 0.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(Xr,Yr+altura);
		glVertex2f(Xr+largura, Yr+altura);       
		glVertex2f(Xr+largura, Yr);       
		glVertex2f(Xr,Yr);
	glEnd();
	
//Objeto de Chegada
glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2f(230,500);
		glVertex2f(290, 500);       
		glVertex2f(290, 470);       
		glVertex2f(230, 470);
	glEnd();
//Linhas  do Labirinto de Baixo para Cima
glLineWidth(3.0);
// Linha H1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(500, 45);
		glVertex2i(90, 45);
	glEnd();
	
// Linha H2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(0, 90);
		glVertex2i(350, 90);
	glEnd();
	
// Linha H3.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(0, 135);
		glVertex2i(100, 135);
	glEnd();
	
//Linha H3.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(145, 135);
		glVertex2i(330, 135);
	glEnd();
	
// Linha H3.3
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(375, 135);
		glVertex2i(500, 135);
	glEnd();
	
// Linha H4.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(50, 180);
		glVertex2i(300, 180);
	glEnd();
	
//Linha H4.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(353, 180);
		glVertex2i(455, 180);
	glEnd();
	
//Linha H5.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(140, 290);
		glVertex2i(240, 290);
	glEnd();
	
//Linha H5.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(0, 290);
		glVertex2i(50, 290);
	glEnd();
	
// Linha H5.3
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(355, 290);
		glVertex2i(455, 290);
	glEnd();

//Linha H6.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(45, 380);
		glVertex2i(230, 380);
	glEnd();
	
//Linha H6.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(330, 380);
		glVertex2i(500, 380);
	glEnd();
	
//Linha H7
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(230, 425);
		glVertex2i(455, 425);
	glEnd();
	
//Linha H8.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(0, 470);
		glVertex2i(230, 470);
	glEnd();
	
//Linha H8.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(290, 470);
		glVertex2i(500, 470);
	glEnd();

//Linha V1.0
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(95, 225);
		glVertex2i(95, 335);
	glEnd();
	
//Linha V1.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(190, 290);
		glVertex2i(190, 225);
	glEnd();
	
	
//Linha V1.2
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(405, 290);
		glVertex2i(405, 335);
	glEnd();
	
//Linha V 1.3
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(300, 180);
		glVertex2i(300, 335);
	glEnd();
	
//Linha V2.0
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(230, 427);
		glVertex2i(230, 380);
	glEnd();
	
//Linha V2.1
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(150, 470);
		glVertex2i(150, 425);
	glEnd();
// Linha H	
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(300, 290);
		glVertex2i(405, 290);
	glEnd();
	
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(400, 230);
		glVertex2i(500, 230);
	glEnd();

// Linha V

glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(355, 290);
		glVertex2i(355, 180);
	glEnd();
	
glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(190, 335);
		glVertex2i(190, 380);
	glEnd();
	
	
//Texto
glColor3f(0,0,0);
	
	glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    if(Vidas > 0){
    	sprintf(texto, "Vidas: %d", Vidas);
	}else{
		sprintf(texto, "Vidas: %d", 0);
	}
    
    glTranslatef(4.0f, 485.0f,0.0f);
    glRasterPos2f(0,0);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,texto);
    glPopMatrix();
    
// Textos que aparecem na tela quando o jogador vence ou perde o jogo.    
if((Xr+largura>=230 && Xr<=320) && Yr==445){

	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);
	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,1);
    glRasterPos2f(160,250); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"PARABENS, VOCE VENCEU!");
	glColor3f(0,0,0);
    glRasterPos2f(70,230); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"Jogar Novamente ? (aperte qualquer seta))");
	// Exibe o desenha na janela
	glutSwapBuffers();
	Xr=470.0;
	Yr=0.0;
	Vidas=3;	
}
else if(Vidas==0) // Texto fim de jogo
{
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(1,0,0);
    glRasterPos2f(125,250); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"FIM DE JOGO, VOCE PERDEU!");
	glColor3f(0,0,0);
    glRasterPos2f(70,230); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"Tentar Novamente ? (aperte qualquer seta)");
	// Exibe o desenha na janela
	glutSwapBuffers();
	Xr=470.0;
	Yr=0.0;	
	Vidas=3;	
}
	 
glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

//funcao que muda de cor ao clicar com o botao esquerdo do mouse
void mouse(int button, int state, int mousex, int mousey)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && check==false) 
	{	
		fund=1.0;
		quad=1.0;
		borda = 0.0;
		check=true;
		
	}	
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && check==true)
	{	
		fund=0.5;
		quad=0.1;
		borda= 1.0;
		check=false;	
	}
	glutPostRedisplay();
}


void Inicializa (void)
{   
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	
}

int main(int argc,char **argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50); 
	glutInitWindowSize(500,500); 
	glutCreateWindow("Labirinto");
	glutDisplayFunc(desenhos);
	glutKeyboardFunc (Teclado);
	glutSpecialFunc(TeclasEspeciais);
	glutMouseFunc(mouse);
	Inicializa();
	glutMainLoop();
	return 0;
}
