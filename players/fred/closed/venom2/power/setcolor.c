#include "../defs.h"

status main(string str, object PO, object User)
{
  string color;
  if(GHOST) return 0;

  if(!str)
  {
    TOU "The following is your list of options:\n\n");
    TOU "red      = "+RED+"sample"+NORM+"\n"+
        "bred     = "+HIR+"sample"+NORM+"\n"+
        "blue     = "+BLU+"sample"+NORM+"\n"+
        "bblue    = "+HIB+"sample"+NORM+"\n"+
        "grey     = "+HIK+"sample"+NORM+"\n"+
        "yellow   = "+YEL+"sample"+NORM+"\n"+
        "byellow  = "+HIY+"sample"+NORM+"\n"+
        "magenta  = "+MAG+"sample"+NORM+"\n"+
        "bmagenta = "+HIM+"sample"+NORM+"\n"+
        "cyan     = "+CYN+"sample"+NORM+"\n"+
        "bcyan    = "+HIC+"sample"+NORM+"\n"+
        "green    = "+GRN+"sample"+NORM+"\n"+
        "bgreen   = "+HIG+"sample"+NORM+"\n");
    return 1;
  }
  if(member_array(str, COLORS) == -1)
  {
    TOU "That color isn't an option.\n");
    return 1;
  }
  if(str == "red")           color = RED;
  else if(str == "bred")     color = HIR;
  else if(str == "blue")     color = BLU;
  else if(str == "bblue")    color = HIB;
  else if(str == "grey")     color = HIK;
  else if(str == "yellow")   color = YEL;
  else if(str == "byellow")  color = HIY;
  else if(str == "magenta")  color = MAG;
  else if(str == "bmagenta") color = HIM;
  else if(str == "cyan")     color = CYN;
  else if(str == "bcyan")    color = HIC;
  else if(str == "green")    color = GRN;
  else if(str == "bgreen")   color = HIG;
  
  TOU "You have chosen "+color+str+NORM+" as your new color.\n");
  PO->set_color(color);
  return 1;
}
