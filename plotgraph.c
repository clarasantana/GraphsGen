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

void plot_Point(cairo_t *context, int x, int y, int colors[], double scale)
{
	cairo_save(context);
	cairo_set_source_rgba(context, colors[0], colors[1], colors[2], colors[3]);
	cairo_set_line_width(context, 2.0);
	cairo_arc(context, x, y, scale, 0, 2*360);
	cairo_fill(context);
	cairo_restore(context);
}

void show_Points(cairo_t *context, int x, int y, int colors[], double scale)
{
	int i;
	for (i = 0; i < xyPointsAmount; i++)
	{
		if (x[i] != -1 && y[i] != -1)
		{
			plot_Point(context, (0.5*width + xPoints[i]), (height - 0.95*yPoints[i]) - [i], colors, scale);
		}
	} 
}
