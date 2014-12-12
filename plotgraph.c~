#include <stdio.h>
#include "loadingjsonfile.h"
#include <cairo/cairo.h>
#define PI 3.14146

void draw_Backgroud(cairo_t *context, int width, int height)
{
	/*this function creates the background, which does have a 
	size widthxheight(read in .json file) and is on a 32-bit 
	color format*/
	cairo_save(context);
	cairo_rectangle(context, 0, 0, width, height);
	cairo_set_source_rgba(context, 255, 255, 255, 255);
	cairo_fill(context);
	cairo_restore(context);
}

void draw_Axis(cairo_t *context, int width, int height) 
{
	cairo_save(context);
    cairo_set_line_width (context, 2.0);
    cairo_set_source_rgb (context, 0, 0, 0);
  	//x axis
  	cairo_move_to(context, 0.05*width, 0.95*height);
	cairo_line_to(context, 0.95*width, 0.95*height);
	//arrow on x axis
	cairo_move_to(context, 0.95*width, 0.95*height);
	cairo_line_to(context, 0.93*width, 0.96*height);
	cairo_move_to(context, 0.95*width, 0.95*height);
	cairo_line_to(context, 0.93*width, 0.94*height);
	//y axis
	cairo_move_to(context, 0.05*width, 0.95*height);
	cairo_line_to(context, 0.05*width, 0.05*height);
	//arrow on y axis
	cairo_move_to(context, 0.05*width, 0.05*height);
	cairo_line_to(context, 0.04*width, 0.07*height);
	cairo_move_to(context, 0.05*width, 0.05*height);
	cairo_line_to(context, 0.06*width, 0.07*height);
	//showing the coordinates	
	cairo_select_font_face(context, "Helvetica", 
							CAIRO_FONT_SLANT_ITALIC, 
							CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(context, width/35);
	cairo_move_to(context, 0.95*width, 0.98*height);
	cairo_show_text(context, "x");
	cairo_set_font_size(context, width/30);
	cairo_move_to(context, 0.015*width, 0.07*height);
	cairo_show_text(context, "y");
	cairo_move_to(context, 0.02*width, 0.98*height);
	cairo_show_text(context, "0");
    cairo_stroke(context);
    cairo_restore(context);
}

void show_title(cairo_t *context, int width, int height,const char *title, int colors[])
{
	cairo_save(context);
	cairo_set_source_rgba(context, colors[0], colors[1], colors[2], colors[3]);
	cairo_select_font_face(context, "Helvetica", CAIRO_FONT_SLANT_NORMAL,
      						CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(context, width/25);
	cairo_move_to(context, width/2 - (width/8), height/10);
	cairo_show_text(context, title);
	cairo_restore(context);
}

double return_escalaX(int x[], int xyPointsAmount,int width) 
{
	int i, maior = x[0];
	for(i = 0; i < xyPointsAmount; i++) 
	{
		if(x[i] > maior)  {
			maior = x[i];
		}
	}
	if(maior == 0)
	{
		maior = 1;
	} 
	double escalaX = (width - (width * 0.05) * 2) / maior; 
	return escalaX;
}

double return_escalaY(int y[], int xyPointsAmount,int height) 
{
	int i, maior = y[0];
	for(i = 0; i < xyPointsAmount; i++) 
	{
		if(y[i] > maior)  {
			maior = y[i];
		}
	}
	if(maior == 0)
	{
		maior = 1;
	}
	double escalaY = (height - (height * 0.05) * 2) / maior; 
	return escalaY;
}

void plot_Point(cairo_t *context, int x, int y, int colors[], double scale)
{
	cairo_save(context);
	cairo_set_source_rgba(context, colors[0], colors[1], colors[2], colors[3]);
	cairo_set_line_width(context, 2.0);
	cairo_arc(context, x, y, scale, 0, 2*360);
	cairo_fill(context);
	cairo_restore(context);
}

void show_Points(cairo_t *context, int x[], int y[], int colors[], double scale,int width, int height,int xyPointsAmount)
{
	double escalaX = return_escalaX(x,xyPointsAmount,width);
	double escalaY = return_escalaY(y,xyPointsAmount,height);
	int i;
	for (i = 0; i < xyPointsAmount; i++)
	{
		if (x[i] != -1 && y[i] != -1)
		{
			plot_Point(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)), colors, scale);
		}
	} 
}

void draw_lines(cairo_t *context,int x[], int y[], int width, int height, int colors[],int xyPointsAmount) {
	double escalaX = return_escalaX(x,xyPointsAmount,width);
	double escalaY = return_escalaY(y,xyPointsAmount,height);
	int i;
	cairo_save(context);
	cairo_set_source_rgba(context,colors[0],colors[1],colors[2],colors[3]);
	for(i = 0; i < xyPointsAmount;i++ ) {
		if(i == 0) {
			cairo_move_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
		}
		if(x[i] != -1) {
		cairo_line_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
		}
	}
	cairo_stroke(context);	
	cairo_restore(context);
}

void draw_area_by_lines(cairo_t *context,int x[], int y[], int width, int height, int colors[],int xyPointsAmount) {
	double escalaX = return_escalaX(x,xyPointsAmount,width);
	double escalaY = return_escalaY(y,xyPointsAmount,height);
	int i;
	cairo_save(context);
	cairo_set_source_rgba(context,colors[0],colors[1],colors[2],colors[3]);
	for(i = 0; i < xyPointsAmount;i++ ) {
		if(i == 0) {
			//cairo_move_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
			cairo_move_to(context,( (0.05*width) + (x[i]*escalaX) ),(height - (height * 0.05)));
			cairo_line_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
		}
		if(x[i] != -1) {
		cairo_line_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
		} else if(i == xyPointsAmount - 1) {
			cairo_line_to(context,( (0.05*width) + (x[i]*escalaX) ),( (height - (height*0.05)) - (y[i]*escalaY)));
		}
	}
	cairo_close_path(context);
	cairo_fill(context);	
	cairo_restore(context);
}