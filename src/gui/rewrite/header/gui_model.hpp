#ifndef gui_model_hpp
#define gui_model_hpp

#include "gui.hpp"

namespace gt
{
  namespace gui
  {
    //guiModel implemented as singleton because just one instance is needed
    class guiModel
    {
    private:      
      guiModel(){}; //empty private constructor
      guiModel(const gt::gui::guiModel&); //preventing wrong initialization
      guiModel & operator=(const gt::gui::guiModel&); //preventing wrong initialization
    public:
      static gt::gui::guiModel& init(); //this "constructor" inits the model with just one instance
    };
  }
}

#endif
