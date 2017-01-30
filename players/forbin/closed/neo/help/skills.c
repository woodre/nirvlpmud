#include "../defs.h"

status help(object gob, object player)
{
	string title;
	
	title = "Skills";

	tell_object(player,"\n"+
    HELPLINE+
	  HELPTITLE+
	  HELPLINE+"\n"+
  	"  A great majority of the neo symbiotes'\n"+
	  "  powers are derived by a combination of\n"+
	  "  spelll points and dark matter.  It is\n"+
  	"  through the absorbtion of corpses that\n"+
	  "  a neo symbiote can build a reserve of\n"+
	  "  dark matter points.\n"+
	  "\n"+
  	"      Usage:  "+PGC+"absorb"+NORM+" -or- "+PGC+"absorb corpse"+NORM+"\n\n"
	  HELPLINE);
	return 1;
}