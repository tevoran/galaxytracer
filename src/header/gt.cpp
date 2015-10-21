#include "gt.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


//config class
gt::config::config()//config constructor
{
	gt::config::readconfig();
}

void gt::config::readconfig() //reading the configfile
{
	std::cout << "currently reading access to: data/config\n";
	std::ifstream config_file;
	config_file.open("data/config");
	if(config_file.is_open()) //when file is readable
		{
			std::string in_line; //config info (1 line)
			//read until end of file
			while(config_file.eof()==false)
			{
				getline(config_file,in_line);
				std::cout << in_line << "\n";
				//checking for keywords
				//resx
				if(in_line.find("resx=")!=std::string::npos)
				{
					in_line.erase(0,sizeof("resx=")-1);
					resx=atoi(in_line.c_str());
				}
				//resy
				if(in_line.find("resy=")!=std::string::npos)
				{
					in_line.erase(0,sizeof("resy=")-1);
					resy=atoi(in_line.c_str());
				}
				//seed
				if(in_line.find("seed=")!=std::string::npos)
				{
					in_line.erase(0,sizeof("seed=")-1);
					seed=atoi(in_line.c_str());
				}
			}
		}
	else //if an error while reading occurs
		{
			std::cout << "error while reading data/config\n";
		}
	
	config_file.close();
}

int gt::config::getresx()
{
	return resx;
}

int gt::config::getresy()
{
	return resy;
}

long int gt::config::getseed()
{
	return seed;
}
