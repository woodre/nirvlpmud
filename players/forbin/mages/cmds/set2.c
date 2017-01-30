#include "../def.h"

status main(string str, object gob, object player)
{
	string one, two;
	string *validcolors;
	
	validcolors = ({ "red", "bright red", "yellow", "bright yellow", "green", "bright green",
		               "blue", "bright blue", "cyan", "bright cyan", "magenta", "bright magenta",
		               "bright black", "bright white", });
	
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
      	case "red" :            PO->set_guild_color(NORM+RED); break;
      	case "bright red" :     PO->set_guild_color(NORM+HIR); break;
        case "yellow" :         PO->set_guild_color(NORM+YEL); break;
        case "bright yellow" :  PO->set_guild_color(NORM+HIY); break;
        case "green" :          PO->set_guild_color(NORM+GRN); break;
        case "bright green" :   PO->set_guild_color(NORM+HIG); break;
        case "blue" :           PO->set_guild_color(NORM+BLU); break;
        case "bright blue" :    PO->set_guild_color(NORM+HIB); break;
        case "cyan" :           PO->set_guild_color(NORM+CYN); break;
        case "bright cyan" :    PO->set_guild_color(NORM+HIC); break;
        case "magenta" :        PO->set_guild_color(NORM+MAG); break;
        case "bright magenta" : PO->set_guild_color(NORM+HIM); break;
        case "bright black" :   PO->set_guild_color(NORM+HIK); break;
        case "bright white" :   PO->set_guild_color(NORM+HIW); break;
        	
      }
      PO->save_PO();
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
    	  "\t "+NORM+RED+"Red            ["+NORM+HIR+"||||||||||"+NORM+RED+"]\n"+NORM+
    	  "\t "+NORM+HIR+"Bright Red     ["+NORM+RED+"||||||||||"+NORM+HIR+"]\n"+NORM+
    	  "\t "+NORM+YEL+"Yellow				 ["+NORM+HIY+"||||||||||"+NORM+YEL+"]\n"+NORM+
    	  "\t "+NORM+HIY+"Bright Yellow  ["+NORM+YEL+"||||||||||"+NORM+HIY+"]\n"+NORM+
    	  "Set your guild color by typing:  'set color <choice>'\n");
    	return 1;
    }
  }
}
