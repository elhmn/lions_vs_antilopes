#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "error.h"
#include "load_map.h"

static char	**get_map(std::string s_map, int w, int h)
{
	char		**map;
	const char	*tmp;
	int			i;

	i = -1;
	map = NULL;
	tmp = s_map.c_str();
	if (!(map = (char**)malloc(sizeof(char*) * h + 1)))
		ERROR("BAD ALLOC");
	map[h] = NULL;
	while (++i < h)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * w + 1)))
			ERROR("BAD ALLOC");
 		if (!tmp || !*tmp || i * w > s_map.length())
 			ERROR("MAP WRONG SIZE");
 		map[i][w] = '\0';
		memcpy(map[i], tmp + i * w, w);
	}
	return (map);
}

void			load_map(const char *filePath, char ***map, int *w, int *h)
{
	std::ifstream	file;
	std::string		buf;
	std::string		mapTmp;

	mapTmp = "";
	if (!filePath)
		ERROR("filePath set to NULL");
	file.exceptions(std::ifstream::badbit);
	try
	{
		file.open(filePath);
		if (file.is_open())
		{
			if (std::getline(file, buf))
				*w = atoi(buf.c_str());
			if (std::getline(file, buf))
				*h = atoi(buf.c_str());
			if (w <= 0 || h <= 0)
				ERROR("Map wrong format");
			while (std::getline(file, buf))
				mapTmp += buf;
			*map = get_map(mapTmp, *w, *h);
		}
		else
			ERROR((std::string(filePath) + " not opened").c_str());
	}
	catch (const std::ifstream::failure& e)
	{
		ERROR("Exception opening/reading/closing file");
	}
	file.close();
}
