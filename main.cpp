#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

void balon (float ctrx,float ctry, float scala)
{
// bawah balon
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,RED);
    float balonx[100],balony[100];
    for (int i=1;i<100;i++)
    {
        balonx[0]=0;balony[0]=-4;
        balonx[i]=balonx[i-1]+1;
        balony[i]=balony[i-1]+1;
    }
    int i;
    for (i=0;i<3;i++)
    {
        line(balonx[i]*scala+ctrx,-1*balony[i]*scala+ctry,balonx[i+1]*scala+ctrx,-1*balony[i]*scala+ctry);
        line(balonx[i+1]*scala+ctrx,-1*balony[i]*scala+ctry,balonx[i+1]*scala+ctrx,-1*balony[i+1]*scala+ctry);
        line(-1*balonx[i]*scala+ctrx,-1*balony[i]*scala+ctry,-1*balonx[i+1]*scala+ctrx,-1*balony[i]*scala+ctry);
        line(-1*balonx[i+1]*scala+ctrx,-1*balony[i]*scala+ctry,-1*balonx[i+1]*scala+ctrx,-1*balony[i+1]*scala+ctry);
    }
// pinggir tegak balon
        float xt0,yt0,xt1,yt1;
        xt0=balonx[i];yt0=2-balony[i+1];
        xt1=balonx[i];yt1=-3-balony[i+1];
        line(xt0*scala+ctrx,yt0*scala+ctry,xt1*scala+ctrx,yt1*scala+ctry);
        line(-1*xt0*scala+ctrx,yt0*scala+ctry,-1*xt1*scala+ctrx,yt1*scala+ctry);
//atas balon
        float xa0,ya0,xa1,ya1,xa2,ya2;
        xa0=xt1;ya0=yt1;
        xa1=xt1-1;ya1=yt1-1;
        xa2=0;ya2=ya1;
        line(xa0*scala+ctrx,ya0*scala+ctry,xa1*scala+ctrx,ya1*scala+ctry);
        line(-1*xa0*scala+ctrx,ya0*scala+ctry,-1*xa1*scala+ctrx,ya1*scala+ctry);
        line(xa1*scala+ctrx,ya1*scala+ctry,xa2*scala+ctrx,ya2*scala+ctry);
        line(-1*xa1*scala+ctrx,ya1*scala+ctry,-1*xa2*scala+ctrx,ya2*scala+ctry);

//ekor balon
    float xe0,ye0,xe1,ye1,xe2,ye2;
    xe0=1;ye0=4;
    xe1=0;ye1=5;
    xe2=0;ye2=13;
    line(xe0*scala+ctrx,ye0*scala+ctry,xe1*scala+ctrx,ye1*scala+ctry);
    line(-1*xe0*scala+ctrx,ye0*scala+ctry,xe1*scala+ctrx,ye1*scala+ctry);
    line(xe1*scala+ctrx,ye1*scala+ctry,xe2*scala+ctrx,ye2*scala+ctry);

    floodfill(ctrx,ctry,BLACK);
}

void pesawatkanan(float xp1, float yp1, float scala)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    // badan pesawat
    float xb0,yb0,xb1,yb1;
    xb0=0;yb0=-0.5;
    xb1=-3;yb1=-0.5;
    line(xb0*scala+xp1,yb0*scala+yp1,xb1*scala+xp1,yb1*scala+yp1);
    line(xb0*scala+xp1,-1*yb0*scala+yp1,xb1*scala+xp1,-1*yb1*scala+yp1);

    //depan pesawat
    float xd0,yd0,xd1,yd1;
    xd0=xb1;yd0=yb1;
    xd1=xb1-1;yd1=0;
    line(xd0*scala+xp1,yd0*scala+yp1,xd1*scala+xp1,yd1*scala+yp1);
    line(xd0*scala+xp1,-1*yd0*scala+yp1,xd1*scala+xp1,yd1*scala+yp1);

    //sayap pesawat
    float xs0,ys0,xs1,ys1,xs2,ys2,xs3,ys3;
    xs0=0;ys0=-0.5;
    xs1=1;ys1=-2.5;
    xs2=1.5;ys2=ys1;
    xs3=xs1;ys3=ys0;
    line(xs0*scala+xp1,ys0*scala+yp1,xs1*scala+xp1,ys1*scala+yp1);
    line(xs1*scala+xp1,ys1*scala+yp1,xs2*scala+xp1,ys2*scala+yp1);
    line(xs2*scala+xp1,ys2*scala+yp1,xs3*scala+xp1,ys3*scala+yp1);

    // ekor pesawat
    float xe0,ye0,xe1,ye1,xe2,ye2;
    xe0=1;ye0=-0.5;
    xe1=2;ye1=ye0;
    xe2=0;ye2=0.5;
    line(xe0*scala+xp1,ye0*scala+yp1,xe1*scala+xp1,ye1*scala+yp1);
    line(xe1*scala+xp1,ye1*scala+yp1,xe2*scala+xp1,ye2*scala+yp1);

    floodfill(xp1,yp1,BLUE);
}

void pesawatkiri(float xp1, float yp1, float scala)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    // badan pesawat
    float xb0,yb0,xb1,yb1;
    xb0=0;yb0=-0.5;
    xb1=3;yb1=-0.5;
    line(xb0*scala+xp1,yb0*scala+yp1,xb1*scala+xp1,yb1*scala+yp1);
    line(xb0*scala+xp1,-1*yb0*scala+yp1,xb1*scala+xp1,-1*yb1*scala+yp1);

    //depan pesawat
    float xd0,yd0,xd1,yd1;
    xd0=xb1;yd0=yb1;
    xd1=xb1+1;yd1=0;
    line(xd0*scala+xp1,yd0*scala+yp1,xd1*scala+xp1,yd1*scala+yp1);
    line(xd0*scala+xp1,-1*yd0*scala+yp1,xd1*scala+xp1,yd1*scala+yp1);

    //sayap pesawat
    float xs0,ys0,xs1,ys1,xs2,ys2,xs3,ys3;
    xs0=0;ys0=-0.5;
    xs1=-1;ys1=-2.5;
    xs2=-1.5;ys2=ys1;
    xs3=xs1;ys3=ys0;
    line(xs0*scala+xp1,ys0*scala+yp1,xs1*scala+xp1,ys1*scala+yp1);
    line(xs1*scala+xp1,ys1*scala+yp1,xs2*scala+xp1,ys2*scala+yp1);
    line(xs2*scala+xp1,ys2*scala+yp1,xs3*scala+xp1,ys3*scala+yp1);

    // ekor pesawat
    float xe0,ye0,xe1,ye1,xe2,ye2;
    xe0=-1;ye0=-0.5;
    xe1=-2;ye1=ye0;
    xe2=0;ye2=0.5;
    line(xe0*scala+xp1,ye0*scala+yp1,xe1*scala+xp1,ye1*scala+yp1);
    line(xe1*scala+xp1,ye1*scala+yp1,xe2*scala+xp1,ye2*scala+yp1);

    floodfill(xp1,yp1,BLUE);
}

void awan (float x, float y, float scala)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    line (x*scala-47,y*scala,x*scala+47,y*scala);
    arc(x*scala-40,y*scala-20,80,275,22);
    arc(x*scala-18,y*scala-40,30,190,24);
    arc(x*scala+16,y*scala-40,320,150,20);
    arc(x*scala+40,y*scala-18,250,125,20);
    floodfill(x,y-5,WHITE);
}

void score (int z)
{
    settextstyle(3,0,1);
    setcolor(BLACK);
    char skor[999];
    sprintf(skor,"- SCORE = %d - ",z);
    outtextxy(200,0,skor);
}

void loading()
{
    int i=0,page=0;
    while (i<=299)
    {
        setactivepage(page);
        setvisualpage(1-page);

        cleardevice();
        delay(10);

        setbkcolor(LIGHTCYAN);
        setcolor(RED);
        rectangle(100,300,400,320);

        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        rectangle(101,301,101+i,319);
        if (i>0)
        {
            floodfill(100+i,310,BLUE);
        }
        i++;


        settextstyle(10,0,2);
        setcolor(BLACK);
        outtextxy(220,230,"TIPS");
        settextstyle(10,0,1);
        outtextxy(55,250,"Control your mouse to avoid bullets");
        outtextxy(130,270,"and reach high score!");

        settextstyle(10,0,4);
        setcolor(BLUE);
        outtextxy(165,330,"Loading...");

        page=1-page;
    }
    PlaySound(0,0,0);
    sleep(1);
}

void gameplay()
{
    retry:
    int page=0;
// skor
    int z=0;
// karakter balon
    float ctrx=250,ctry=350;
// awan
    int x_awan[4],y_awan[4]={-200,-400,-600,-800};
    for (int i=0;i<4;i++)
    {
        x_awan[i]=rand()%500;
    }
// pesawat
    int flag_r1[4],flag_r2[4],xpeluru_r[2][4],ypeluru_r[2][4];  // PESAWAT KANAN (RIGHT)
    int xpkanan[10],ypkanan[10],speed_r[10],scala_r[10];
    int flag_l1[4],flag_l2[4],xpeluru_l[2][4],ypeluru_l[2][4];  // PESAWAT KIRI (LEFT)
    int xpkiri[10],ypkiri[10],speed_l[10],scala_l[10];
    for (int i=0;i<2;i++) //FUNGSI RANDOM
    {
        xpkanan[i]=rand()%200+500;
        ypkanan[i]=rand()%60+45;
        speed_r[i]=rand()%5+3;
        scala_r[i]=rand()%5+10;

        xpkiri[i]=rand()%200-500;
        ypkiri[i]=rand()%60+45;
        speed_l[i]=rand()%5+3;
        scala_l[i]=rand()%5+10;
    }
// VARIABEL KONDISI MENEMBAK
    int R1[3],R2[3],L1[3],L2[3];
     R1[0]=rand()%140 + 10;
     R1[1]=rand()%200 + 150;
     R1[2]=rand()%140 + 350;
     R2[0]=rand()%140 + 10;
     R2[1]=rand()%200 + 150;
     R2[2]=rand()%140 + 350;
     L1[0]=rand()%140 + 10;
     L1[1]=rand()%200 + 150;
     L1[2]=rand()%140 + 350;
     L2[0]=rand()%140 + 10;
     L2[1]=rand()%200 + 150;
     L2[2]=rand()%140 + 350;

     //kondisi untuk pindah fungsi
     int x=0;

    PlaySound("Pou - Food Swap 30s.wav",NULL,SND_ASYNC|SND_LOOP);
     sleep(1);
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);

        setbkcolor(LIGHTCYAN);
        delay(20);
        cleardevice();
        line (0,145,500,145);
        line (1,145,1,600);
        line (499,145,499,600);

// awan
        for (int i=0;i<4;i++)
        {
            awan(x_awan[i],y_awan[i],1);
            y_awan[i]+=4;
            if (y_awan[i]>600)
            {
                x_awan[i]=rand()%500;
                y_awan[i]=-200;
            }
        }
//balon
        ctrx=mousex();
        ctry=mousey();
        if (ctrx>=475)
        {
            ctrx=475;
        }
        if (ctrx<=25)
        {
            ctrx=25;
        }
        if (ctry<=180)
        {
            ctry=180;
        }
        if (ctry>=550)
        {
            ctry=550;
        }
        balon(ctrx,ctry,8);

// score
        if (y_awan[0]>=0&&y_awan[0]<3||y_awan[1]>=0&&y_awan[1]<3||y_awan[2]>=0&&y_awan[2]<3||y_awan[3]>=0&&y_awan[3]<3)
        {
            z+=10;
        }
        score(z);

// pesawat kanan
        for (int i=0;i<2;i++)
        {
            xpkanan[i]=xpkanan[i]-speed_r[i];
            if (xpkanan[i]<-100)
            {
                xpkanan[i]=xpkanan[i]%200+700;
                ypkanan[i]=rand()%80+40;
                speed_r[i]=rand()%5+3;
                scala_r[i]=rand()%5+10;
            }
            pesawatkanan(xpkanan[i],ypkanan[i],scala_r[i]);
        }
// nembak
        if (ypeluru_r[0][0]>600)
        {
            R1[0]=rand()%140 + 10;
        }
        if (ypeluru_r[0][1]>600)
        {
            R1[1]=rand()%200 + 150;
        }
        if (ypeluru_r[0][2]>600)
        {
            R1[2]=rand()%140 + 360;
        }
    //
        if (ypeluru_r[1][0]>600)
        {
            R2[0]=rand()%140 + 10;
        }
        if (ypeluru_r[1][1]>600)
        {
            R2[1]=rand()%200 + 150;
        }
        if (ypeluru_r[1][2]>600)
        {
            R2[2]=rand()%140 + 360;
        }
// pesawat KANAN 1
        if (xpkanan[0]>R1[0]-5&&xpkanan[0]<R1[0]+5)
        {
            flag_r1[0]=1;
            xpeluru_r[0][0]=xpkanan[0];
            ypeluru_r[0][0]=ypkanan[0];
        }
        if (flag_r1[0]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[0][0],ypeluru_r[0][0],8);
            floodfill(xpeluru_r[0][0],ypeluru_r[0][0],BLUE);
        }
        ypeluru_r[0][0]+=10;
        if (xpkanan[0]>R1[1]-5&&xpkanan[0]<R1[1]+5)
        {
            flag_r1[1]=1;
            xpeluru_r[0][1]=xpkanan[0];
            ypeluru_r[0][1]=ypkanan[0];
        }
        if (flag_r1[1]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[0][1],ypeluru_r[0][1],8);
            floodfill(xpeluru_r[0][1],ypeluru_r[0][1],BLUE);
        }
        ypeluru_r[0][1]+=10;
        if (xpkanan[0]>R1[2]-5&&xpkanan[0]<R1[2]+5)
        {
            flag_r1[2]=1;
            xpeluru_r[0][2]=xpkanan[0];
            ypeluru_r[0][2]=ypkanan[0];
        }
        if (flag_r1[2]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[0][2],ypeluru_r[0][2],8);
            floodfill(xpeluru_r[0][2],ypeluru_r[0][2],BLUE);
        }
        ypeluru_r[0][2]+=10;
// pesawat KANAN 2
        if (xpkanan[1]>R2[0]-5&&xpkanan[1]<R2[0]+5)
        {
            flag_r2[0]=1;
            xpeluru_r[1][0]=xpkanan[1];
            ypeluru_r[1][0]=ypkanan[1];
        }
        if (flag_r2[0]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[1][0],ypeluru_r[1][0],8);
            floodfill(xpeluru_r[1][0],ypeluru_r[1][0],BLUE);
        }
        ypeluru_r[1][0]+=10;
        if (xpkanan[1]>R2[1]-5&&xpkanan[1]<R2[1]+5)
        {
            flag_r2[1]=1;
            xpeluru_r[1][1]=xpkanan[1];
            ypeluru_r[1][1]=ypkanan[1];
        }
        if (flag_r2[1]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[1][1],ypeluru_r[1][1],8);
            floodfill(xpeluru_r[1][1],ypeluru_r[1][1],BLUE);
        }
        ypeluru_r[1][1]+=10;
        if (xpkanan[1]>R2[2]-5&&xpkanan[1]<R2[2]+5)
        {
            flag_r2[2]=1;
            xpeluru_r[1][2]=xpkanan[1];
            ypeluru_r[1][2]=ypkanan[1];
        }
        if (flag_r2[2]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_r[1][2],ypeluru_r[1][2],8);
            floodfill(xpeluru_r[1][2],ypeluru_r[1][2],BLUE);
        }
        ypeluru_r[1][2]+=10;

// pesawat kiri
        for (int i=0;i<2;i++)
        {
            xpkiri[i]=xpkiri[i]+speed_l[i];
            if (xpkiri[i]>600)
            {
                xpkiri[i]=xpkiri[i]%200-700;
                ypkiri[i]=rand()%80+40;
                speed_l[i]=rand()%5+3;
                scala_l[i]=rand()%5+13;
            }
            pesawatkiri(xpkiri[i],ypkiri[i],scala_l[i]);
        }
// nembak
        if (ypeluru_l[0][0]>600)
        {
            L1[0]=rand()%140 + 10;
        }
        if (ypeluru_l[0][1]>600)
        {
            L1[1]=rand()%200 + 150;
        }
        if (ypeluru_l[0][2]>600)
        {
            L1[2]=rand()%140 + 360;
        }
    //
        if (ypeluru_l[1][0]>600)
        {
            L2[0]=rand()%140 + 10;
        }
        if (ypeluru_l[1][1]>600)
        {
            L2[1]=rand()%200 + 150;
        }
        if (ypeluru_l[1][2]>600)
        {
            L2[2]=rand()%140 + 360;
        }
// pesawat KIRI 1
        if (xpkiri[0]>L1[0]-5&&xpkiri[0]<L1[0]+5)
        {
            flag_l1[0]=1;
            xpeluru_l[0][0]=xpkiri[0];
            ypeluru_l[0][0]=ypkiri[0];
        }
        if (flag_l1[0]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[0][0],ypeluru_l[0][0],8);
            floodfill(xpeluru_l[0][0],ypeluru_l[0][0],BLUE);
        }
        ypeluru_l[0][0]+=10;
        if (xpkiri[0]>L1[1]-5&&xpkiri[0]<L1[1]+5)
        {
            flag_l1[1]=1;
            xpeluru_l[0][1]=xpkiri[0];
            ypeluru_l[0][1]=ypkiri[0];
        }
        if (flag_l1[1]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[0][1],ypeluru_l[0][1],8);
            floodfill(xpeluru_l[0][1],ypeluru_l[0][1],BLUE);
        }
        ypeluru_l[0][1]+=10;
        if (xpkiri[0]>L1[2]-5&&xpkiri[0]<L1[2]+5)
        {
            flag_l1[2]=1;
            xpeluru_l[0][2]=xpkiri[0];
            ypeluru_l[0][2]=ypkiri[0];
        }
        if (flag_l1[2]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[0][2],ypeluru_l[0][2],8);
            floodfill(xpeluru_l[0][2],ypeluru_l[0][2],BLUE);
        }
        ypeluru_l[0][2]+=10;
// pesawat KIRI 2
        if (xpkiri[1]>L2[0]-5&&xpkiri[1]<L2[0]+5)
        {
            flag_l2[0]=1;
            xpeluru_l[1][0]=xpkiri[1];
            ypeluru_l[1][0]=ypkiri[1];
        }
        if (flag_l2[0]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[1][0],ypeluru_l[1][0],8);
            floodfill(xpeluru_l[1][0],ypeluru_l[1][0],BLUE);
        }
        ypeluru_l[1][0]+=10;
        if (xpkiri[1]>L2[1]-5&&xpkiri[1]<L2[1]+5)
        {
            flag_l2[1]=1;
            xpeluru_l[1][1]=xpkiri[1];
            ypeluru_l[1][1]=ypkiri[1];
        }
        if (flag_l2[1]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[1][1],ypeluru_l[1][1],8);
            floodfill(xpeluru_l[1][1],ypeluru_l[1][1],BLUE);
        }
        ypeluru_l[1][1]+=10;
        if (xpkiri[1]>L2[2]-5&&xpkiri[1]<L2[2]+5)
        {
            flag_l2[2]=1;
            xpeluru_l[1][2]=xpkiri[1];
            ypeluru_l[1][2]=ypkiri[1];
        }
        if (flag_l2[2]==1)
        {
            setfillstyle(SOLID_FILL,BLUE);
            circle(xpeluru_l[1][2],ypeluru_l[1][2],8);
            floodfill(xpeluru_l[1][2],ypeluru_l[1][2],BLUE);
        }
        ypeluru_l[1][2]+=10;

// kena tembakan

        if ((xpeluru_r[0][0] >=ctrx-3*8 && xpeluru_r[0][0] <=ctrx+3*8 && ypeluru_r[0][0] >=ctry-2*8 && ypeluru_r[0][0] <=ctry+3*8) ||
            (xpeluru_r[0][1] >=ctrx-3*8 && xpeluru_r[0][1] <=ctrx+3*8 && ypeluru_r[0][1] >=ctry-2*8 && ypeluru_r[0][1] <=ctry+3*8) ||
            (xpeluru_r[0][2] >=ctrx-3*8 && xpeluru_r[0][2] <=ctrx+3*8 && ypeluru_r[0][2] >=ctry-2*8 && ypeluru_r[0][2] <=ctry+3*8) ||
            (xpeluru_r[1][0] >=ctrx-3*8 && xpeluru_r[1][0] <=ctrx+3*8 && ypeluru_r[1][0] >=ctry-2*8 && ypeluru_r[1][0] <=ctry+3*8) ||
            (xpeluru_r[1][1] >=ctrx-3*8 && xpeluru_r[1][1] <=ctrx+3*8 && ypeluru_r[1][1] >=ctry-2*8 && ypeluru_r[1][1] <=ctry+3*8) ||
            (xpeluru_r[1][2] >=ctrx-3*8 && xpeluru_r[1][2] <=ctrx+3*8 && ypeluru_r[1][2] >=ctry-2*8 && ypeluru_r[1][2] <=ctry+3*8) ||
            (xpeluru_l[0][0] >=ctrx-3*8 && xpeluru_l[0][0] <=ctrx+3*8 && ypeluru_l[0][0] >=ctry-2*8 && ypeluru_l[0][0] <=ctry+3*8) ||
            (xpeluru_l[0][1] >=ctrx-3*8 && xpeluru_l[0][1] <=ctrx+3*8 && ypeluru_l[0][1] >=ctry-2*8 && ypeluru_l[0][1] <=ctry+3*8) ||
            (xpeluru_l[0][2] >=ctrx-3*8 && xpeluru_l[0][2] <=ctrx+3*8 && ypeluru_l[0][2] >=ctry-2*8 && ypeluru_l[0][2] <=ctry+3*8) ||
            (xpeluru_l[1][0] >=ctrx-3*8 && xpeluru_l[1][0] <=ctrx+3*8 && ypeluru_l[1][0] >=ctry-2*8 && ypeluru_l[1][0] <=ctry+3*8) ||
            (xpeluru_l[1][1] >=ctrx-3*8 && xpeluru_l[1][1] <=ctrx+3*8 && ypeluru_l[1][1] >=ctry-2*8 && ypeluru_l[1][1] <=ctry+3*8) ||
            (xpeluru_l[1][2] >=ctrx-3*8 && xpeluru_l[1][2] <=ctrx+3*8 && ypeluru_l[1][2] >=ctry-2*8 && ypeluru_l[1][2] <=ctry+3*8)
            )
        {
        PlaySound("Pou - Game Over.wav",NULL,SND_ASYNC);
            sleep(1);
            while (1)
            {
                setactivepage(page);
                setvisualpage(1-page);

                cleardevice();
                delay(20);
                ctrx=mousex();
                ctry=mousey();

                setbkcolor(LIGHTCYAN);

                settextstyle(10,0,4);
                setcolor(BLUE);
                char skor[999];
                sprintf(skor,"%d",z);
                outtextxy(120,220,"Your Score is");
                outtextxy(220,250,skor);

                settextstyle(10,0,3);
                setcolor(WHITE);
                outtextxy(210,310,"Retry");
                outtextxy(160,350,"Back to Menu");

            /*  setcolor(WHITE);
                rectangle(210,310,280,330);
                rectangle(160,350,330,370);*/

                if (ctrx >= 210 && ctrx <=280 && ctry >=310 && ctry <=330)
                {
                    settextstyle(10,0,3);
                    setcolor(RED);
                    outtextxy(210,310,"Retry");

                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        for (int i=0;i<2;i++)
                        {
                            for (int j=0;j<3;j++)
                            {
                                ypeluru_r[i][j]=700;
                                ypeluru_l[i][j]=700;
                            }
                        }
                        goto retry;
                    }
                }

                if (ctrx >= 160 && ctrx <=330 && ctry >=350 && ctry <=370)
                {
                    settextstyle(10,0,3);
                    setcolor(RED);
                    outtextxy(160,350,"Back to Menu");

                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        x=1;
                        sleep(1);
                        break;
                    }
                }
                page=1-page;
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
        }

        page=1-page;

        if (x==1)
        {
            break;
        }
    }
}

void credit ()
{
    int page=0;
    float ctrx,ctry;

    clearmouseclick(WM_LBUTTONDOWN);
    while (1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        delay(20);

        ctrx=mousex();
        ctry=mousey();

        setbkcolor(LIGHTCYAN);
        setcolor(RED);
        settextstyle(10,0,4);
        outtextxy(150,100,"Game Title");
        outtextxy(150,200,"Created By:");
        setcolor(BLUE);
        settextstyle(10,0,3);
        outtextxy(155,150,"GO BALLOON !!");
        outtextxy(100,250,"Ridho Walid Al Maulidi");
        outtextxy(180,300,"5024201036");
        outtextxy(115,350,"Pemrograman Lanjut A");

        setcolor(WHITE);
        settextstyle(10,0,4);
        outtextxy(15,550,"Back");

        setcolor(LIGHTCYAN);
        rectangle(15,555,87,570);
        if (ctrx >= 15 && ctrx <=87 && ctry >=555 && ctry <=570)
        {
            setcolor(RED);
            outtextxy(15,550,"Back");
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                break;
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
        }
        page =1-page;
    }
}

void menu ()
{
    menu:
    int page=0;
    float ctrx,ctry;

    PlaySound("BanG Dream - Menu Theme.wav",NULL,SND_ASYNC|SND_LOOP);
    sleep(1);
    while (1)
    {
        setactivepage(page);
        setvisualpage(1-page);

        cleardevice();
        delay(20);

        setbkcolor(LIGHTCYAN);

        ctrx=mousex();
        ctry=mousey();

        setcolor(BLUE);
        settextstyle(10,0,7);
        outtextxy(70,100,"GO");
        outtextxy(100,150,"BALLOON!!");

        settextstyle(10,0,4);
        setcolor(WHITE);
        outtextxy(210,340,"Play");
        outtextxy(195,380,"Credit");
        outtextxy(210,420,"Quit");

   /*     setcolor(LIGHTCYAN);
        rectangle(210,340,285,360);
        rectangle(200,380,310,400);
        rectangle(210,420,280,440);  */

        if (ctrx >= 210 && ctrx <=285 && ctry >=340 && ctry <=360)
        {
            settextstyle(10,0,4);
            setcolor(RED);
            outtextxy(210,340,"Play");
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                loading();
                gameplay();
                goto menu;
            }
        }
        if (ctrx >= 195 && ctrx <=310 && ctry >=380 && ctry <=400)
        {
            settextstyle(10,0,4);
            setcolor(RED);
            outtextxy(195,380,"Credit");
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                credit();
            }
        }
        if (ctrx >= 210 && ctrx <=280 && ctry >=420 && ctry <=440)
        {
            settextstyle(10,0,4);
            setcolor(RED);
            outtextxy(210,420,"Quit");
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                break;
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
        }

        page=1-page;
    }
}

int main ()
{
    initwindow(500,600,"GO,BALLOON!!");
    menu();
    return 0;
}
