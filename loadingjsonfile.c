#include <stdio.h>
#include <jansson.h>
#include <stdlib.h>

json_t *openning_json(char str[]) 
{
	//loading the .json file
	json_t *root;
	json_error_t error;
	root = json_load_file(str, 0, &error);
	if(root == 0) 
	{
		printf("Erro ao ler o arquivo.\nLinha de erro: %d.\n", error.line);
		exit(1);
	}
	return root;
}
	
	//gets the .json file name
const char *return_fileName(char str[])
{	
	json_t *root = openning_json(str);
	json_t * jfileName = json_object_get(root, "fileName");
	const char * fileName = json_string_value(jfileName);
	return fileName;
}

	//gets the chart title
const char *return_name(char str[])
{	
	json_t *root = openning_json(str);
	json_t * jname = json_object_get(root, "name");
	const char * name = json_string_value(jname);
	return name;
}
	//gets the chart format(png or pdf)
const char *return_format(char str[])
{	
	json_t *root = openning_json(str);
	json_t * jFormat = json_object_get(root, "fileType");
	const char * format = json_string_value(jFormat);
	return format;
}

	//gets the chart width
const int graph_width(char str[])
{
	json_t *root = openning_json(str);
	json_t * jwidth = json_object_get(root, "width");
	const int width = json_integer_value(jwidth);
	return width;
}

	//gets the chart height
const int graph_height(char str[])
{
	json_t *root = openning_json(str);
	json_t * jheight = json_object_get(root, "height");
	const int height = json_integer_value(jheight);
	return height;
}

	//0 = dots, 1 = line, 2 = area
const int graph_type(char str[])
{
	json_t *root = openning_json(str);
	json_t * jtype = json_object_get(root, "type");
	const int type = json_integer_value(jtype);
	return type;
}

	//rgba (32-bit) color format
	//Estava sem retorno, mudei pra void
const int graph_colors(char str[], int **colors)
{
	json_t *root = openning_json(str);
	json_t *jColor = json_object_get(root, "color");
	int jColor_lenght = json_array_size(jColor);
	(*colors) = (int *) malloc(jColor_lenght * sizeof(int)); 
	int i;
	for (i = 0; i < jColor_lenght; i++)
	{
		json_t * jItem = json_array_get(jColor, i);
		const int item = json_integer_value(jItem);
		(*colors)[i] = item;
	}
	return jColor_lenght;
}
	//reading the dots coordinates in .json file
const int gets_json_data(char str[], int **reads_x, int **reads_y)
{
	json_t *root = openning_json(str);
	json_t *jPoints = json_object_get(root, "content");
	int contentLength = json_array_size(jPoints);
	(*reads_x) = (int *) malloc(contentLength *sizeof(int));
	(*reads_y) = (int *) malloc(contentLength *sizeof(int));
	int i;
	for (i = 0; i < json_array_size(jPoints); i++)
	{
		json_t * jPoint = json_array_get(jPoints, i);
		json_t *jX = json_object_get(jPoint, "x");
		const int x = json_integer_value(jX);
		json_t *jY = json_object_get(jPoint, "y");
		const int y = json_integer_value(jY);
		(*reads_x)[i] = x;
		(*reads_y)[i] = y; 
	}	
	return contentLength;
}
/*
const int gets_json_data(char str[], int **reads_x, int **reads_y) {
	json_t *root = openning_json(str);
	json_t *jPoints = json_object_get(root, "content");
	int jLenght = json_array_size(jPoints);
	(*get_x) = (int*) malloc(jLenght * sizeof(int));
	(*get_y) = (int*) malloc(jLenght * sizeof(int));
	for(int i = 0; i < json_array_size(jPoints); ++i){
		json_t * jPoint = json_array_get(jPoints, i);
		json_t *jX = json_object_get(jPoint, "x");
		const int x = json_integer_value(jX);
		json_t *jY = json_object_get(jPoint, "y");
		const int y = json_integer_value(jY);
		//Armazenar tudo isso;
		(*get_x)[i] = x;
		(*get_y)[i] = y;
	}
	return jLenght;
}*/