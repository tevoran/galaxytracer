#ifndef _gt_hpp
#define _gt_hpp

#include <SFML/Graphics.hpp>

namespace gt
{
	//configuration class
    class config
    {
        private:
        	int resx;
        	int resy;
			bool live;
        	long int seed;
        public:
        	config(); //constructor
        	void readconfig(); //read the config file data/config
        	int getresx(); //getting the x-resolution
        	int getresy(); //getting the y-resolution
        	long int getseed(); //getting the seed
			bool getlive(); //getting the live-value
    };

	//GUI class
	class gui
	{
		private:
			sf::RenderWindow* window; //the sfml window object
            bool render_interface; //the state of the renderinterface
		public:
			gui(int resx, int resy); //constructor for creating the gui
			bool update(); //the update for each frame
			void drawpixel(int x,int y/*,int r,int g, int b*/); //draw a pixel
	};
}


#endif
