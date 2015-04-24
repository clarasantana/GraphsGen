#include <stdio.h>
#include <string.h>
#include "plotgraph.h"
#include "loadingjsonfile.h"
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
void show_graph(char str[])
{
	//loading .json file
	const char *format = return_format(str);
	const int width = graph_width(str);
	const int height = graph_height(str);
	const char *fileName = return_fileName(str);
	const char *title = return_name(str);		
	int *xPoints, *yPoints;
	int xyPointsAmount;
	xyPointsAmount = gets_json_data(str, &xPoints, &yPoints);
	int color[4] = {0,255,0,255};
	const int type = graph_type(str);

	//initializing cairo
	cairo_surface_t *surface;
	if (!(strcmp(format, "png")))
	{
		surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	}
	else if (!(strcmp(format, "pdf")))
	{
		surface = cairo_pdf_surface_create(fileName, width, height);
	}
	else
	{
		printf ("Software isn't compatible with format.\n");
	}	

	cairo_t *context = cairo_create(surface);

	//drawing the graph with .json file data
	//drawing dots
	int blue[4] = {255,0,0,255};

	draw_Backgroud(context, width, height);
	draw_Axis(context, width, height);
	show_title(context, width, height, title, color);
	 
	//Checking graph type	
	if(type == 0)
	{
		show_Points(context,xPoints,yPoints,color,2,width,height,xyPointsAmount);
	} else if(type == 1)
	{
		draw_lines(context,xPoints,yPoints,width,height,color,xyPointsAmount);
	} else if(type == 2) {
		draw_area_by_lines(context,xPoints,yPoints,width,height,color,xyPointsAmount);
	}
	
	//saving the drawing according to file type specified on .json
	if(!(strcmp(format,"png"))){
		cairo_surface_write_to_png(surface,fileName);
	} else if(!(strcmp(format,"pdf"))) {	
		cairo_show_page(context);
	}
	cairo_destroy(context);
	cairo_surface_destroy(surface);
}
