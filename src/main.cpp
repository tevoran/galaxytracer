#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/gt.hpp"

int main()
{
    //reading configfile
        std::cout << "reading data/config\n";
    gt::config config_gt; //this reads data/config
        std::cout << "seed: " << config_gt.getseed() << "\n";

    //starting GUI
		std::cout << "starting GUI\n";
    gt::gui gui_gt(config_gt.getresx(),config_gt.getresy()); //this inits the GUI

	//mainloop
		std::cout << "entering main loop\n";
	float i=0;
	while(gui_gt.update())
	{
		gui_gt.drawpixel(0,(int)i);
		i=i+0.05;
	}
    return 0;
}
