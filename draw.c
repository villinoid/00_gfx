#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	if(x0>x1) {
		draw_line(x1,y1,x0,y0,s,c);
		return;
	}
	int A=y1-y0;
	int B=x0-x1;
	int x=x0;
	int y=y0;
	if (y1>y0){
		if(-1*B>=A){
			int d=2*A+B;
			while (x<=x1){
				plot(s,c,x,y);
				if (d>0){
					y++;
					d+=2*B;
				}
				x++;
				d+=2*A;
			}
		}
		else{

			int d=A+2*B;
			while (y<=y1){
				plot(s,c,x,y);
				if (d<0){
					x++;
					d+=2*A;
				}
				y++;
				d+=2*B;
				
			}
		}	
	}
	else{
		if(B<=A){
			int d=2*A-B;
			while (x<=x1){
				plot(s,c,x,y);
				if (d<0){
					y--;
					d-=2*B;
				}
				x++;
				d+=2*A;
			}
		}
		else{

			int d=A-2*B;
			while (y>=y1){
				plot(s,c,x,y);
				if (d>0){
					x++;
					d+=2*A;
				}
				y--;
				d-=2*B;
				
			}
		}
	}		

		
}