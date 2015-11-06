#ifndef _gt_hpp
#define _gt_hpp

#include <SFML/Graphics.hpp>
#include <string>


namespace gt
{
  //configuration class
  //implemented as singleton, because just one instance is needed
  //each new instance gets the same location in the memory
  class config
  {
  private:
    int resx;
    int resy;
    bool live;
    long int seed;
    config();//private constructor
    config(const gt::config&);
    config & operator=(const gt::config&);
  public:
    static gt::config& init(); //this starts the class
    void readconfig(); //read the config file data/config
    void writeconfig(); //write the config back to the config file
    //getfunctions
    int getresx(){return resx;}; //getting the x-resolution
    int getresy(){return resy;}; //getting the y-resolution
    long int getseed(){return seed;}; //getting the seed
    bool getlive(){return live;}; //getting the live-value

    //setfunctions
    void setresx(int resx_in){resx=resx_in;}; //setting resx
    void setresy(int resy_in){resy=resy_in;}; //setting resx
    void setseed(long int seed_in){seed=seed_in;}; //setting resx
    void setlive(bool live_in){live=live_in;}; //setting resx
  };
}


#endif
