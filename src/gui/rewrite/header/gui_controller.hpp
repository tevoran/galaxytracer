#ifndef gui_controller_hpp
#define gui_controller_hpp

namespace gt
{
  namespace gui
  {
    //implemented as a singleton because just one instance is needed
    class controller
    {
    private:
      controller(){}; //private constructor
      controller(const gt::gui::controller&); //preventing wrong initialization
      controller & operator=(const gt::gui::controller&); //preventing wrong initialization
    public:
      static gt::gui::controller& init(); //init routine
    };
  }
}

#endif
