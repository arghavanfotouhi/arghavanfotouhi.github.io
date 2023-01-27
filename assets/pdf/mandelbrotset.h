#ifndef __MANDELBROTSET_H__
#define __MANDELBROTSET_H__

#include"defs.h"
#include<math.h>


int maxIter=128;
// double minx=-2.5,maxx= 1;
// double miny=-1, maxy=1;
// int  width=960 , height =540 ;
int get_mbs_iter(double x, double y)
{
    
    double re=0 , im=0 ;
    int t =0;
    for( int iter=0 ;iter <= maxIter; iter++)  
        {
            t=iter+100;
            double tempr=re*re - im* im +x;
            im =2* re*im +y;
            re=tempr; 
            if (re * re + im* im > 3*3)
                 break;
        } 
        return t; 
}

void hsv_to_rgb(int hue, int min, int max, COLORINDEX* p)
{
    // TODO
    
}

void UpdateImageData(ImageState* state)
{
    
    
    state -> bmFileData.bmHeader.colorIdx[0].r=66;
    state -> bmFileData.bmHeader.colorIdx[0].g= 30;
    state -> bmFileData.bmHeader.colorIdx[0].b= 15;

    state -> bmFileData.bmHeader.colorIdx[1].b=25;
    state -> bmFileData.bmHeader.colorIdx[1].r= 7;
    state -> bmFileData.bmHeader.colorIdx[1].g= 26;

    state -> bmFileData.bmHeader.colorIdx[2].b=9;
    state -> bmFileData.bmHeader.colorIdx[2].r= 1;
    state -> bmFileData.bmHeader.colorIdx[2].g= 47;

    state -> bmFileData.bmHeader.colorIdx[3].b=4;
    state -> bmFileData.bmHeader.colorIdx[3].r= 4;
    state -> bmFileData.bmHeader.colorIdx[3].g= 73;

    state -> bmFileData.bmHeader.colorIdx[4].b=15;
    state -> bmFileData.bmHeader.colorIdx[4].r= 66;
    state -> bmFileData.bmHeader.colorIdx[4].g= 30;

    state -> bmFileData.bmHeader.colorIdx[5].b=12;
    state -> bmFileData.bmHeader.colorIdx[5].r= 44;
    state -> bmFileData.bmHeader.colorIdx[5].g= 138;

    state -> bmFileData.bmHeader.colorIdx[6].b=24;
    state -> bmFileData.bmHeader.colorIdx[6].r= 82;
    state -> bmFileData.bmHeader.colorIdx[6].g= 177;

    state -> bmFileData.bmHeader.colorIdx[7].b=57;
    state -> bmFileData.bmHeader.colorIdx[7].r= 125;
    state -> bmFileData.bmHeader.colorIdx[7].g= 209;
    
    state -> bmFileData.bmHeader.colorIdx[8].b=134;
    state -> bmFileData.bmHeader.colorIdx[8].r= 181;
    state -> bmFileData.bmHeader.colorIdx[8].g= 229;

    state -> bmFileData.bmHeader.colorIdx[9].b=211;
    state -> bmFileData.bmHeader.colorIdx[9].r= 236;
    state -> bmFileData.bmHeader.colorIdx[9].g= 248;

  
    state -> bmFileData.bmHeader.colorIdx[10].b=211;
    state -> bmFileData.bmHeader.colorIdx[10].r= 236;
    state -> bmFileData.bmHeader.colorIdx[10].g= 248;

    state -> bmFileData.bmHeader.colorIdx[11].b=248;
    state -> bmFileData.bmHeader.colorIdx[11].r= 201;
    state -> bmFileData.bmHeader.colorIdx[11].g= 95;
    
    state -> bmFileData.bmHeader.colorIdx[12].b=255;
    state -> bmFileData.bmHeader.colorIdx[12].r= 170;
    state -> bmFileData.bmHeader.colorIdx[12].g= 0;

    state -> bmFileData.bmHeader.colorIdx[13].b=204;
    state -> bmFileData.bmHeader.colorIdx[13].r= 128;
    state -> bmFileData.bmHeader.colorIdx[13].g= 0;

    state -> bmFileData.bmHeader.colorIdx[14].b=153;
    state -> bmFileData.bmHeader.colorIdx[14].r= 87;
    state -> bmFileData.bmHeader.colorIdx[14].g= 0;

    state -> bmFileData.bmHeader.colorIdx[15].b=106;
    state -> bmFileData.bmHeader.colorIdx[15].r= 52;
    state -> bmFileData.bmHeader.colorIdx[15].g= 3;

    
    
    for(int x=0; x<state->width; x++)
        for(int y=0; y<state->height; y++)
        {
            // x,y => dx,dy
            // dx,dy => rx, ry
            double cr= state->minx + (state->maxx - state->minx) * x / state->width;
            double ci = state->miny + (state->maxy -state-> miny) * y/ state->height;
            double  rx = cr * cos(state->angle) + ci * sin(state->angle);
            double ry = -cr * sin(state->angle) + ci * cos(state->angle);
 
            int iter = get_mbs_iter(rx, ry);
            int u=iter%16;
            if (u==0)
            {
                 state -> bmFileData.bmData[x + y * state->width]=0;
            }
             if (u==1)
            {
                 state -> bmFileData.bmData[x + y * state->width]=1;
            }
             if (u==2)
            {
                 state -> bmFileData.bmData[x + y * state->width]=2;
            }
             if (u==3)
            {
                 state -> bmFileData.bmData[x + y * state->width]=3;
            }
             if (u==4)
            {
                 state -> bmFileData.bmData[x + y * state->width]=4;
            }
              if (u==5)
            {
                 state -> bmFileData.bmData[x + y * state->width]=5;
            }
              if (u==6)
            {
                 state -> bmFileData.bmData[x + y *state-> width]=6;
            }
              if (u==7)
            {
                 state -> bmFileData.bmData[x + y * state->width]=7;
            }
              if (u==8)
            {
                 state -> bmFileData.bmData[x + y * state->width]=8;
            }
                if (u==9)
            {
                 state -> bmFileData.bmData[x + y * state->width]=9;
            }
                if (u==10 )
            {
                 state -> bmFileData.bmData[x + y * state->width]=10;
            }
                if (u==11)
            {
                 state -> bmFileData.bmData[x + y * state->width]=11;
            }
                if (u==12)
            {
                 state -> bmFileData.bmData[x + y * state->width]=12;
            }
                if (u==13)
            {
                 state -> bmFileData.bmData[x + y * state->width]=13;
            }
                if (u==14)
            {
                 state -> bmFileData.bmData[x + y * state->width]=14;
            }
                if (u==15)
            {
                 state -> bmFileData.bmData[x + y * state->width]=15;
            }
                if (u==16)
            {
                 state -> bmFileData.bmData[x + y * state->width]=16;
            }
            // state->bmFileData.bmData[y * state->width + x] = iter;
        }
    // for(int i=0; i<256; i++)
    // {
    //     int hue = (int) ((i / 255)/360);
    //     hsv_to_rgb(hue, 100, 100, &(state->bmFileData.bmHeader.colorIdx[i]));
    // }
}

void ChangeCenter(ImageState* state, double newcx, double newcy, int steps)
{
    
    double a=(newcx - (state->cx) )/steps;
    double b= (newcy - (state->cy))/steps;
    for(int i=0;i<steps; i++)
    {
        
        state->maxx+=a;
        state->minx+=a;
        state->maxy+=b;
        state->miny+=b;
        

        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

void ChangeZoom(ImageState* state, double zoom, int steps)
{
    
    double a = state->maxx/zoom;
    double b = state->maxy/zoom;
    double c = state->minx/zoom;
    double d = state->miny/zoom;
    double l1=(a - state->maxx) / steps;
    double l2=(b - state->maxy) / steps;
    double l3=(c - state->minx) / steps;
    double l4=(d- state->miny) / steps;
    for(int i=0; i<steps; i++)
    {
        
        state->maxx+=l1;
        state->maxy+=l2;
        state->minx+=l3;
        state->miny+=l4;
        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

void ChangeRotation(ImageState* state, double angle, int steps)
{
    
    angle = angle * M_PI/180;
    double angle_step = angle / steps;
    for(int i=0; i<steps; i++)
    {
        state->angle += angle_step;
        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

void Hold(ImageState* state, int steps)
{
    
    for(int i=0; i<steps; i++)
    {
        
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

#endif