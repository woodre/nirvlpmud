#include "../def.h"

status main(string str, object gob, object player)
{
	string one, two;
	string *validcolors;
	
	validcolors = ({ "red", "yellow", "green", "blue", "cyan", "magenta", });
	
	if(!str)
	{
		tell_object(player,
		  "You may 'set color <choice>'\n");
		return 1;
	}
	
	else if(sscanf(str, "%s %s", one, two) == 2)                   /**5**/
  {
  	if(one == "color")
  	{
      if(member_array(two, validcolors) < 0)
      {
        tell_object(player,
          "That is not a valid choice.  Type 'set color' for a list.\n");
        return 1;	
      }
      switch(two)
      {
      	case "red" :     gob->set_guild_color(NORM+RED); break;
        case "yellow" :  gob->set_guild_color(NORM+YEL); break;
        case "green" :   gob->set_guild_color(NORM+GRN); break;
        case "blue" :    gob->set_guild_color(NORM+BLU); break;
        case "cyan" :    gob->set_guild_color(NORM+CYN); break;
        case "magenta" : gob->set_guild_color(NORM+MAG); break;
      }
      gob->save_gob();
      tell_object(player,
        "You have set your guild color to "+PGC+two+NORM+".\n");
      return 1; 
  	}
  }
  else if(sscanf(str, "%s", one) == 1)
  {
    if(one == "color")
    {
    	tell_object(player,
    	  "\nValid choices for guild colors are:\n"+NORM+
    	  "     "+RED+"Red\t["+BOLD+"*"+NORM+RED+"]\n"+NORM+
    	  "     "+YEL+"Yellow\t["+BOLD+"*"+NORM+YEL+"]\n"+NORM+
    	  "     "+GRN+"Green\t["+BOLD+"*"+NORM+GRN+"]\n"+NORM+
    	  "     "+BLU+"Blue\t["+BOLD+"*"+NORM+BLU+"]\n"+NORM+
    	  "     "+CYN+"Cyan\t["+BOLD+"*"+NORM+CYN+"]\n"+NORM+
    	  "     "+MAG+"Magenta\t["+BOLD+"*"+NORM+MAG+"]\n"+NORM+
    	  "Set your guild color by typing:  'set color <choice>'\n");
    	return 1;
    }
  }
}
