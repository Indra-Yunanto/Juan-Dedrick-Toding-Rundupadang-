#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
void init(void);
void tampil(void);
void keyboard(unsigned,char,int,int);
void ukuran(int,int);
void mouse(int button,int state,int x,int y);
void mouseMotion(int x,int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;

void bangunan(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int
z1,float z2,float z3){
    glColor3f(1,1,0.6); //sisi depan
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x3,y3,z2);
    glVertex3d(x4,y4,z2);

    glColor3f(0.8,0.8,0.4);//sisi kanan
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z1);
    glVertex3d(x3,y3,z1);
    glVertex3d(x3,y3,z2);

    glColor3f(1,1,0.6);//sisi belakang
    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x3,y3,z1);
    glVertex3d(x4,y4,z1);

    glColor3f(0.8,0.8,0.4);//sisi kiri
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y1,z1);
    glVertex3d(x4,y4,z1);
    glVertex3d(x4,y4,z2);

    glColor3f(0.7,0.7,0.7);//sisi bawah
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y1,z1);

    glColor3f(0.3,0.3,0.3);//sisi atas
    glVertex3d(x3,y3,z2);
    glVertex3d(x4,y4,z2);
    glVertex3d(x4,y4,z1);
    glVertex3d(x3,y3,z1);
}

void atap(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int
y4,float z1,float z2,float z3){
    glColor3f(0.7,0.7,0.7);//belakang
    glVertex3d(x4,y4,z1);
    glVertex3d(x3,y3,z1);
    glVertex3d(x3,y1,z3);
    glVertex3d(x4,y1,z3);

    glColor3f(0.58,0.58,0.58);//depan
    glVertex3d(x3,y3,z2);
    glVertex3d(x4,y4,z2);
    glVertex3d(x4,y1,z3);
    glVertex3d(x3,y1,z3);
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void tutupatap(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int
y4,float z1,float z2,float z3){

    glColor3f(0.5,0.5,0.55);//kiri
    glVertex3d(x4,y4,z2);
    glVertex3d(x4,y4,z1);
    glVertex3d(x4,y1,z3);

    glColor3f(0.5,0.5,0.55);//kanan
    glVertex3d(x3,y3,z1);
    glVertex3d(x3,y3,z2);
    glVertex3d(x3,y1,z3);


}
void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    //alas bawah
    glColor3f(0,1,0);
    glVertex3d(-20,-2,20);
    glVertex3d(20,-2,20);
    glVertex3d(20,-2,-20);
    glVertex3d(-20,-2,-20);

    //Rumah
    bangunan(-8,-2,8,-2,8,2,-8,2,-5,3,0);//rumah
    bangunan(2,-2,8,-2,8,2,2,2,-9,4,0);//kamar kotak depan
    atap(-3,5,0,0,8,2,-8,2,-5.5,4.5,0);
    atap(-5,4,0,0,8,2,-8,2,-10,4.5,0);

    glColor3f(0.7,0.7,0.7);//plafon depan
    glVertex3d(8,1.8,-3);
    glVertex3d(-8,1.8,-3);
    glVertex3d(-8,1.8,4.5);
    glVertex3d(8,1.8,4.5);//
    glVertex3d(8,1.8,4.5);
    glVertex3d(-8,1.8,4.5);
    glVertex3d(-8,2,4.5);
    glVertex3d(8,2,4.5);

    glColor3f(0.58,0.58,0.58);//plafon belakang
    glVertex3d(8,1.8,-5.5);
    glVertex3d(-8,1.8,-5.5);
    glVertex3d(-8,1.8,4.5);
    glVertex3d(8,1.8,4.5);
    glVertex3d(8,1.8,-5.5);
    glVertex3d(-8,1.8,-5.5);
    glVertex3d(-8,2,-5.5);
    glVertex3d(8,2,-5.5);


    glColor3f(1,1,1);
    glVertex3d(5.5,-1,4.1);//jendela kamar
    glVertex3d(6.5,-1,4.1);
    glVertex3d(6.5,1.3,4.1);
    glVertex3d(5.5,1.3,4.1);

    glColor3f(1,1,1);
    glVertex3d(3.5,-1,4.1);//jendela kamar2
    glVertex3d(4.5,-1,4.1);
    glVertex3d(4.5,1.3,4.1);
    glVertex3d(3.5,1.3,4.1);

    glColor3f(1,1,1);
    glVertex3d(5.5,-1,-9.1);//jendela kamarbelakang
    glVertex3d(6.5,-1,-9.1);
    glVertex3d(6.5,1.3,-9.1);
    glVertex3d(5.5,1.3,-9.1);

    glColor3f(1,1,1);
    glVertex3d(1.9,-1,-8.1);//jendela kamarbelakang sebelah kiri
    glVertex3d(1.9,-1,-7.1);
    glVertex3d(1.9,1.3,-7.1);
    glVertex3d(1.9,1.3,-8.1);

    glColor3f(1,1,1);
    glVertex3d(3.5,-1,-9.1);//jendela kamarbelakang2
    glVertex3d(4.5,-1,-9.1);
    glVertex3d(4.5,1.3,-9.1);
    glVertex3d(3.5,1.3,-9.1);

    glColor3f(0.55, 0.40, 0.2);
    glVertex3d(-1.5,-2,3.05);//pintu depan
    glVertex3d(1.5,-2,3.05);
    glVertex3d(1.5,1.3,3.05);
    glVertex3d(-1.5,1.3,3.05);

    glColor3f(0.55, 0.40, 0.2);
    glVertex3d(-1.5,-2,-5.05);//pintu belakang
    glVertex3d(1.5,-2,-5.05);
    glVertex3d(1.5,1,-5.05);
    glVertex3d(-1.5,1,-5.05);

    glColor3f(1,1,1);
    glVertex3d(-6.5,-1,3.05);//jendela depan
    glVertex3d(-2.5,-1,3.05);
    glVertex3d(-2.5,1.3,3.05);
    glVertex3d(-6.5,1.3,3.05);

    glColor3f(1,1,1);
    glVertex3d(-8.1,-1,0.05);//jendela kiri
    glVertex3d(-8.1,-1,-4.05);
    glVertex3d(-8.1,1.3,-4.05);
    glVertex3d(-8.1,1.3,0.05);

    glColor3f(1,1,1);
    glVertex3d(8.1,-1,0.05);//jendela kanan
    glVertex3d(8.1,-1,-4.05);
    glVertex3d(8.1,1.3,-4.05);
    glVertex3d(8.1,1.3,0.05);

    glVertex3d(-4.5,-1,-5.05);//jendela belakang
    glVertex3d(-2.5,-1,-5.05);
    glVertex3d(-2.5,1,-5.05);
    glVertex3d(-4.5,1,-5.05);

    glEnd();

    glBegin(GL_TRIANGLES);//atap
    tutupatap(-3,5,0,0,8,2,-8,2,-5.5,4.5,0);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(8,1.8,4.5);
    glVertex3d(-8,1.8,4.5);
    glVertex3d(-8,1.8,-5.5);
    glVertex3d(8,1.8,-5.5);
    glEnd();

    //gagang pintu
    glPushMatrix();
    glTranslatef(-1,-0.5,3.05);
    glColor3f(0,0,0);
    glutWireSphere(0.1,200,10);
    glPopMatrix();

    //gagang pintu blkg
    glPushMatrix();
    glTranslatef(-1,-0.5,-5);
    glColor3f(0,0,0);
    glutWireSphere(0.1,200,10);
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(5.5,-1,4.1);//bingkai jendela kamar depan
    glVertex3d(6.5,-1,4.1);
    glVertex3d(6.5,1.3,4.1);
    glVertex3d(5.5,1.3,4.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(3.5,-1,4.1);//bingkai jendela kamar depan2
    glVertex3d(4.5,-1,4.1);
    glVertex3d(4.5,1.3,4.1);
    glVertex3d(3.5,1.3,4.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(5.5,-1,-9.1);//bingkai jendela kamar belakang
    glVertex3d(6.5,-1,-9.1);
    glVertex3d(6.5,1.3,-9.1);
    glVertex3d(5.5,1.3,-9.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(1.9,-1,-8.1);//bingkai jendela kamarbelakang sebelah kiri
    glVertex3d(1.9,-1,-7.1);
    glVertex3d(1.9,1.3,-7.1);
    glVertex3d(1.9,1.3,-8.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(3.5,-1,-9.1);//bingkai jendela kamar belakang2
    glVertex3d(4.5,-1,-9.1);
    glVertex3d(4.5,1.3,-9.1);
    glVertex3d(3.5,1.3,-9.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(-4.5,-1,-5.05);//bingkai jendela belakang
    glVertex3d(-2.5,-1,-5.05);
    glVertex3d(-2.5,1,-5.05);
    glVertex3d(-4.5,1,-5.05);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(-6.5,-1,3.05);//bingkai jendela depan
    glVertex3d(-2.5,-1,3.05);
    glVertex3d(-2.5,1.3,3.05);
    glVertex3d(-6.5,1.3,3.05);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(-8.1,-1,0.05);//bingkai jendela kiri
    glVertex3d(-8.1,-1,-4.05);
    glVertex3d(-8.1,1.3,-4.05);
    glVertex3d(-8.1,1.3,0.05);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(8.1,-1,0.05);//bingkai jendela kanan
    glVertex3d(8.1,-1,-4.05);
    glVertex3d(8.1,1.3,-4.05);
    glVertex3d(8.1,1.3,0.05);
    glEnd();


//kulkas
//kulkasdepan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-2,2.5);
    glVertex3f(-7.5,1,2.5);
    glVertex3f(-5.5,1,2.5);
    glVertex3f(-5.5,-2,2.5);
    glEnd();

    //kulkasbelakang
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-2,0.5);
    glVertex3f(-7.5,1,0.5);
    glVertex3f(-5.5,1,0.5);
    glVertex3f(-5.5,-2,0.5);
    glEnd();

    //kulkaskanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-5.5,1,2.5);
    glVertex3f(-5.5,-2,2.5);
    glVertex3f(-5.5,-2,0.5);
    glVertex3f(-5.5,1,0.5);
    glEnd();

    //kulkaskiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,1,2.5);
    glVertex3f(-7.5,-2,2.5);
    glVertex3f(-7.5,-2,0.5);
    glVertex3f(-7.5,1,0.5);
    glEnd();

    //kulkasatas
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,1,2.5);
    glVertex3f(-5.5,1,2.5);
    glVertex3f(-5.5,1,0.5);
    glVertex3f(-7.5,1,0.5);
    glEnd();

    //kulkasbawah
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-2,2.5);
    glVertex3f(-5.5,-2,2.5);
    glVertex3f(-5.5,-2,0.5);
    glVertex3f(-7.5,-2,0.5);
    glEnd();

//meja kecil
//mejadepan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(3.2,-2,-7.5);
    glVertex3f(3.2,-0.8,-7.5);
    glVertex3f(2.2,-0.8,-7.5);
    glVertex3f(2.2,-2,-7.5);
    glEnd();

    //mejabelakang
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(3.2,-2,-8.5);
    glVertex3f(3.2,-0.8,-8.5);
    glVertex3f(2.2,-0.8,-8.5);
    glVertex3f(2.2,-2,-8.5);
    glEnd();

    //mejakanan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(3.2,-0.8,-7.5);
    glVertex3f(3.2,-2,-7.5);
    glVertex3f(3.2,-2,-8.5);
    glVertex3f(3.2,-0.8,-8.5);
    glEnd();

    //mejakiri
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(2.2,-0.8,-7.5);
    glVertex3f(2.2,-2,-7.5);
    glVertex3f(2.2,-2,-8.5);
    glVertex3f(2.2,-0.8,-8.5);
    glEnd();

    //mejaatas
    glBegin(GL_QUADS);
    glColor3f(1,1.4,1.2);
    glVertex3f(3.2,-1,-7.5);
    glVertex3f(2.2,-1,-7.5);
    glVertex3f(2.2,-1,-8.5);
    glVertex3f(3.2,-1,-8.5);
    glEnd();

    //mejabawah
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(3.2,-2,-7.5);
    glVertex3f(2.2,-2,-7.5);
    glVertex3f(2.2,-2,-8.5);
    glVertex3f(3.2,-2,-8.5);
    glEnd();

//sofa
//sofadepan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(6.5,-2,-7.5);
    glVertex3f(6.5,-1,-7.5);
    glVertex3f(3.5,-1,-7.5);
    glVertex3f(3.5,-2,-7.5);
    glEnd();

    //sofabelakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(6.5,-2,-8.5);
    glVertex3f(6.5,0,-8.5);
    glVertex3f(3.5,0,-8.5);
    glVertex3f(3.5,-2,-8.5);
    glEnd();

    //sofakanan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(6.5,-0.7,-7.5);
    glVertex3f(6.5,-2,-7.5);
    glVertex3f(6.5,-2,-8.5);
    glVertex3f(6.5,-0.7,-8.5);
    glEnd();

    //sofakiri
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(3.5,-0.7,-7.5);
    glVertex3f(3.5,-2,-7.5);
    glVertex3f(3.5,-2,-8.5);
    glVertex3f(3.5,-0.7,-8.5);
    glEnd();

    //sofaatas
    glBegin(GL_QUADS);
    glColor3f(1,1.4,1.2);
    glVertex3f(6.5,-1,-7.5);
    glVertex3f(3.5,-1,-7.5);
    glVertex3f(3.5,-1,-8.5);
    glVertex3f(6.5,-1,-8.5);
    glEnd();

    //sofabawah
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(6.5,-2,-7.5);
    glVertex3f(3.5,-2,-7.5);
    glVertex3f(3.5,-2,-8.5);
    glVertex3f(6.5,-2,-8.5);
    glEnd();


//kasur
//kasurdepan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(6.5,-2,3.5);
    glVertex3f(6.5,0.5,3.5);
    glVertex3f(3.5,0.5,3.5);
    glVertex3f(3.5,-2,3.5);
    glEnd();

    //kasurbelakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(6.5,-2,-1.5);
    glVertex3f(6.5,0,-1.5);
    glVertex3f(3.5,0,-1.5);
    glVertex3f(3.5,-2,-1.5);
    glEnd();

    //kasurkanan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(6.5,-0.7,3.5);
    glVertex3f(6.5,-2,3.5);
    glVertex3f(6.5,-2,-1.5);
    glVertex3f(6.5,-0.7,-1.5);
    glEnd();

    //kasurkiri
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(3.5,-0.7,3.5);
    glVertex3f(3.5,-2,3.5);
    glVertex3f(3.5,-2,-1.5);
    glVertex3f(3.5,-0.7,-1.5);
    glEnd();

    //kasuratas
    glBegin(GL_QUADS);
    glColor3f(1,1.4,1.2);
    glVertex3f(6.5,-0.7,3.5);
    glVertex3f(3.5,-0.7,3.5);
    glVertex3f(3.5,-0.7,-1.5);
    glVertex3f(6.5,-0.7,-1.5);
    glEnd();

    //kasurbawah
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(6.5,-2,3.5);
    glVertex3f(3.5,-2,3.5);
    glVertex3f(3.5,-2,-1.5);
    glVertex3f(6.5,-2,-1.5);
    glEnd();

    //gagang pintu kulkas
    glPushMatrix();
    glTranslatef(-5.5,0,2.05);
    glColor3f(0,0,0);
    glutWireSphere(0.1,200,10);
    glPopMatrix();

//mejapanjang
//mejadepan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(-7.5,-2,0.5);
    glVertex3f(-7.5,-0.5,0.5);
    glVertex3f(-5.5,-0.5,0.5);
    glVertex3f(-5.5,-2,0.5);
    glEnd();

    //mejabelakang
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(-7.5,-2,-4.5);
    glVertex3f(-7.5,-0.5,-4.5);
    glVertex3f(-5.5,-0.5,-4.5);
    glVertex3f(-5.5,-2,-4.5);
    glEnd();

    //mejakanan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(-5.5,-0.5,0.5);
    glVertex3f(-5.5,-2,0.5);
    glVertex3f(-5.5,-2,-4.5);
    glVertex3f(-5.5,-0.5,-4.5);
    glEnd();

    //mejakiri
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(-7.5,-0.5,0.5);
    glVertex3f(-7.5,-2,0.5);
    glVertex3f(-7.5,-2,-4.5);
    glVertex3f(-7.5,-0.5,-4.5);
    glEnd();

    //mejaatas
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0.2);
    glVertex3f(-7.5,-0.5,0.5);
    glVertex3f(-4.5,-0.5,0.5);
    glVertex3f(-4.5,-0.5,-4.5);
    glVertex3f(-7.5,-0.5,-4.5);
    glEnd();

    //mejabawah
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0);
    glVertex3f(-7.5,-2,0.5);
    glVertex3f(-5.5,-2,0.5);
    glVertex3f(-5.5,-2,-4.5);
    glVertex3f(-7.5,-2,-4.5);
    glEnd();

    glutSwapBuffers();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot,1,0,0);
    glRotatef(yrot,0,1,0);
    glPushMatrix;
   if(mouseDown)
   {
       yrot = x - xdiff;
       xrot = y + ydiff;

       glutPostRedisplay();
   }
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {

    case'w'://maju (zoom in)
    case'W':
        glTranslatef(0.0,0.0,3.0);
        break;

    case 'a'://ke-kiri
    case 'A':
        glTranslatef(3.0,0.0,0.0);
        break;

    case 's': //mundur (zoom out)
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;

    case 'd'://kanan
    case 'D':
        glTranslatef(-3.0,0.0,0.0);
        break;

    case '7'://ke-atas
        glTranslatef(0.0,3.0,0.0);
        break;

    case '9'://ke-bawah
        glTranslatef(0.0,-3.0,0.0);
        break;

    case '2'://miring ke-bawah
        glRotatef(2.0,1.0,0.0,0.0);
        break;

    case '8'://miring ke-atas
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6'://putar ke-kanan
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4'://putar ke-kiri
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1'://miring ke-kiri
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3'://miring ke-kanan
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5'://membuat onjek yang terlihat di bagian depan layar tak terlihat (melihat isi dari objek 3d)
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();


}
void ukuran (int lebar,int tinggi)
{
    if (tinggi ==0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0, lebar / tinggi, 50.0, 500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
int main (int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Juan Dedrick Toding Rundupadang 672018353");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

