#ifndef _gt_hpp
#define _gt_hpp

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
            bool render_interface; //the state of the renderinterface
		public:
			gui(); //constructor
			void gui_init(); //create the GUI
	};
}


#endif
