/* This file was automatically generated.  Do not edit! */
#include <cairo/cairo.h>
void draw_Axis(cairo_t *context,int widht,int height);
void draw_Backgroud(cairo_t *context,int width,int height);
void show_title(cairo_t *context, int width, int height, const char *title, int colors[]);
void plot_Point(cairo_t *context, int x, int y, int colors[],double scale);
void show_Points(cairo_t *context, int x[], int y[], int colors[], double scale,int width, int height,int xyPointsAmount);
double return_escalaX(int x[], int xyPointsAmount,int width);
double return_escalaY(int y[], int xyPointsAmount,int height);
void draw_lines(cairo_t *context,int x[], int y[], int width, int height, int colors[],int xyPointsAmount);
void draw_area_by_lines(cairo_t *context,int x[], int y[], int width, int height, int colors[],int xyPointsAmount);
