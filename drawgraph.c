#include <stdio.h>
#include <string.h>
#include "plotgraph.h"
#include "loadingjsonfile.h"
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
void show_graph(char str[])
{
	/*
	const char *return_fileName(char str[]);
	const char *return_name(char str[]);
	const char *return_format(char str[]);
	const int graph_width(char str[]);
	const int graph_height(char str[]);
	const int graph_type(char str[]);
	const int graph_colors(char str[], int **colors);
	const int gets_json_data(char str[], int **reads_x, int **reads_y);
	void draw_Axis(cairo_t *context,int height,int width);
	void draw_Backgroud(cairo_t *context,int width,int height);
	*/
	//loading .json file

	const char *format = return_format(str);
	const int width = graph_width(str);
	const int height = graph_height(str);
	const char *fileName = return_fileName(str);
	int *xPoints, *yPoints;
	int xyPointsAmount;
	xyPointsAmount = gets_json_data(str, &xPoints, &yPoints);
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
	

	 draw_Backgroud(context, width, height);
	 draw_Axis(context, width, height);

	
	//rotina fim do mundo

	if(!(strcmp(format,"png"))){
		cairo_surface_write_to_png(surface,fileName);
	} else if(!(strcmp(format,"pdf"))) {	
		cairo_show_page(context);
	}
	cairo_destroy(context);
	cairo_surface_destroy(surface);
}
