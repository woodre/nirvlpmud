#include "../defs.h"

status main(string str, object gob, object player)
{
	string one, two;
	string *validcolors;
	
	validcolors = ({ "red", "bright red", "blue", "bright blue", 
	                 "yellow", "bright yellow", "green", "bright green", 
	                 "cyan", "bright cyan", "magenta", "bright magenta",
	                 "bright white", "bright black", });

  if((int)player->query_ghost()) return 0;
  
	if(!str)
	{
		tell_object(player,
		  "You may "+PGC+"'"+NORM+"set primary "+SGC+"<"+TGC+"choice"+SGC+">"+PGC+"'"+NORM+" or "+
		  PGC+"'"+NORM+"set secondary "+SGC+"<"+TGC+"choice"+SGC+">"+PGC+"'"+NORM+".\n");
		return 1;
	}
	
	else if(sscanf(str, "%s %s", one, two) == 2)             
  {
  	if(one == "primary")
  	{
      if(member_array(two, validcolors) < 0)
      {
        tell_object(player,
          "That is not a valid choice.  "+
          "Type "+PGC+"'"+SGC+"set color"+PGC+"'"+NORM+" for a list.\n");
        return 1;	
      }
      switch(two)
      {
      	case "red" :            gob->set_pgcol(NORM+RED); break;
      	case "bright red" :     gob->set_pgcol(NORM+HIR); break;
        case "blue" :           gob->set_pgcol(NORM+BLU); break;
        case "bright blue" :    gob->set_pgcol(NORM+HIB); break;
        case "yellow" :         gob->set_pgcol(NORM+YEL); break;
        case "bright yellow" :  gob->set_pgcol(NORM+HIY); break;
        case "green" :          gob->set_pgcol(NORM+GRN); break;
        case "bright green" :   gob->set_pgcol(NORM+HIG); break;
        case "cyan" :           gob->set_pgcol(NORM+CYN); break;
        case "bright cyan" :    gob->set_pgcol(NORM+HIC); break;
        case "magenta" :        gob->set_pgcol(NORM+MAG); break;
        case "bright magenta" : gob->set_pgcol(NORM+HIM); break;
        case "bright white" :   gob->set_pgcol(NORM+HIW); break; 
        case "bright black" :   gob->set_pgcol(NORM+HIK); break;
      }
      gob->save_gob();
      tell_object(player,
        "You have set your primary guild color to "+PGC+two+NORM+".\n");
      return 1; 
  	}
  	if(one == "secondary")
  	{
      if(member_array(two, validcolors) < 0)
      {
        tell_object(player,
          "That is not a valid choice.  "+
          "Type "+PGC+"'"+SGC+"set secondary"+PGC+"'"+NORM+" for a list.\n");
        return 1;	
      }
      switch(two)
      {
      	case "red" :            gob->set_sgcol(NORM+RED); break;
      	case "bright red" :     gob->set_sgcol(NORM+HIR); break;
        case "blue" :           gob->set_sgcol(NORM+BLU); break;
        case "bright blue" :    gob->set_sgcol(NORM+HIB); break;
        case "yellow" :         gob->set_sgcol(NORM+YEL); break;
        case "bright yellow" :  gob->set_sgcol(NORM+HIY); break;
        case "green" :          gob->set_sgcol(NORM+GRN); break;
        case "bright green" :   gob->set_sgcol(NORM+HIG); break;
        case "cyan" :           gob->set_sgcol(NORM+CYN); break;
        case "bright cyan" :    gob->set_sgcol(NORM+HIC); break;
        case "magenta" :        gob->set_sgcol(NORM+MAG); break;
        case "bright magenta" : gob->set_sgcol(NORM+HIM); break;
        case "bright white" :   gob->set_sgcol(NORM+HIW); break; 
        case "bright black" :   gob->set_sgcol(NORM+HIK); break;
      }
      gob->save_gob();
      tell_object(player,
        "You have set your secondary guild color to "+SGC+two+NORM+".\n");
      return 1; 
  	}	
  }
  else if(sscanf(str, "%s", one) == 1)
  {
    if(one == "color" || one == "primary" || one == "secondary")
    {
    	tell_object(player,
    	  "\nValid choices for guild colors are:\n"+NORM+
    	  RED+"   Red               "+HIR+"Bright Red      \n"+NORM+
    	  BLU+"   Blue              "+HIB+"Bright Blue     \n"+NORM+
    	  YEL+"   Yellow            "+HIY+"Bright Yellow   \n"+NORM+
    	  GRN+"   Green             "+HIG+"Bright Green    \n"+NORM+
    	  CYN+"   Cyan              "+HIC+"Bright Cyan     \n"+NORM+
    	  MAG+"   Magenta           "+HIM+"Bright Magenta  \n"+NORM+
    	  HIW+"   Bright White      "+HIK+"Bright Black    \n"+NORM+
    	  "Set your guild color by typing:  \n"+
    	  "     "+PGC+"'"+NORM+"set primary "+SGC+"<"+TGC+"choice"+SGC+">"+PGC+"'"+NORM+"\n"+
    	  "     "+PGC+"'"+NORM+"set secondary "+SGC+"<"+TGC+"choice"+SGC+">"+PGC+"'"+NORM+".\n");
    	return 1;
    }
  }
}
