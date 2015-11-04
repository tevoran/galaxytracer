#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#define pi 3.1415
#define xmax 800
#define ymax 800

int main()
{
  //generating parameters
  float a=3,a2=3,a3=1,a4=1,a5=1;
  float b=0.100,b2=5,b3=500,b4=1000,b5=10000;
  float c=0,c2=2,c3=0,c4=0,c5=0;
  float r0=300,r;
  int spherex=xmax/2,spherey=ymax/2;
  
  sf::RenderWindow window(sf::VideoMode(xmax,ymax),"sphererenderer");
  window.clear();
  sf::RectangleShape line;

  //generating variables
  int x=0,y=0;
  float phi;
  int xtmp,ytmp;
  bool donehalf=false;
  //main loop
while(1)
  {
    b=b+0.001;
    b2=b2-0.001;
    a=a+0.000001;
    x=0;
    y=0;
    donehalf=false;
    while(1)
      {
	//for each direction that is possible on the screen
	xtmp=x-spherex;
	ytmp=y-spherey;
	phi=atan2(ytmp,xtmp);
	if(x<xmax and y==0 and donehalf==false)
	  {
	    x++;
	    if(x==xmax)
	      {
		x=0;
		y=ymax;
	      }
	  }
	if(x<=xmax and y==ymax and donehalf==false)
	  {
	    x++;
	    if(x==xmax)
	      {
		donehalf=true;
		x=0;
		y=0;
	      }
	  }
	if(x==0 and y<ymax and donehalf==true)
	  {
	    y++;
	    if(y==ymax)
	      {
		x=xmax;
		y=0;
	      }
	  }
	if(x==xmax and y<ymax and donehalf==true)
	  {
	    y++;
	    if(y==ymax)
	      {
		break;
	      }
	  }
	//generate and draw
	r=r0+a*sin(b*phi+c)+a2*sin(b2*phi+c2)+a3*sin(b3*phi+c3)+a4*sin(b4*phi+c4)+a5*sin(b5*phi+c5);
	line.setSize(sf::Vector2f(r,1));
	line.setRotation(phi*360/(2*pi));
	line.setPosition(spherex,spherey);
	window.draw(line);
      }
    //the sfml event loop
    window.display();
    window.clear();
    sf::Event event;
    while(window.pollEvent(event))
      {
	if(event.type==sf::Event::Closed) //if the window is closed
	  {
	    window.close();
	    break;
	  }
      }
  }
 return 0;
}
