#include "/players/softly/closed/ansi.h"

reset(arg)  
{
  if(arg) return;
}

init() 
{ 
  add_action("wnfo", "wnfo"); 
}


wnfo() 
{ 
  write_file("/players/softly/softly.nfo",
	     ("\n\n"+
	      "                     "+HIG+"~"+NORM+BOLD+"*"+HIG+"~ "+HIM+"Softly's World "+HIG+"~"+NORM+BOLD+"*"+HIG+"~\n\n"+NORM+
	      "\tAll Realms have attractions for all level players.\n"+
	      "\t  The most appropriate levels are stated below.\n\n"+BOLD+
	      "     Winter\n"+HIW+
	      "\tSkate on an enchanted winter pond then warm yourself\n"+
	      "\t with a cup of hot chocolate and eat some marshmallows.\n"+
	      "\t Aggressive ermine roam the woods and a white wolf that\n"+
	      "\t was once a young woman guards her former home.\n"+
	      "\t For low levels with a few high level attractions.\n\n"+NORM+
	      "     "+RED+"R"+NORM+BOLD+"ocky "+NORM+RED+"P"+NORM+BOLD+"oint\n"+NORM+
	      "\tNearly deserted today, Rocky Point was once the home to\n"+
	      "\t an essential lighthouse.  The mystery deepens if you\n"+
	      "\t search the deserted area.  Take care in the lighthouse\n"+
	      "\t itself though.  Ghosts of ancient pirates roam there.\n"+
	      "\t  For mid to high levels, with something for everyone.\n\n"+YEL+
	      "     Town of Algiers (pop. 621) \n"+NORM+
	      "\tA dusty town hides south of the forest.  Beyond the church\n"+
	      "\t and fortune teller lie shops to delight and surprise.  The\n"+
	      "\t variety shop is stocked with toys while the used clothing\n"+
	      "\t store has new stock daily.  An herb shop oddly enough sells\n"+
	      "\t voodoo dolls.  And if you happen upon the cock fights, look\n"+
	      "\t for Fish so that you can place a wager.\n"+
	      "\t There is truly something for everyone in Algiers.\n\n"+BOLD+
	      "\t From the Village "+HIG+"Green"+NORM+BOLD+": 6w,3s,4w,2s,e then explore"+NORM+"\n\n"));
	     return 1;
	     }
  
  
