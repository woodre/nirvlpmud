#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_id("n51gn");
  set_alias("sign");
  set_long("\n"+BOLD+
	   "        %~~~~~~~~~~~~~~~~~~~%\n"+
	   "        |                   |\n"+
	   "        |   School of the   |\n"+
	   "        |    Apprentices    |\n"+
	   "        |                   |\n"+
            "        | "+NORM+"n, 3w, enter hall"+BOLD+" |\n"+
	   "        |                   |\n"+
           "        %~~~~~~~~~~~~~~~~~~~%\n\n"+
      NORM+" Don't forget to raise your attributes here!\n");
  set_read(format("\n" + BOLD + "        %~~~~~~~~~~~~~~~~~~~%\n        |                   |\n        |   School of the   |\n        |    Apprentices    |\n        |                   |\n        | " + NORM + "n, 3w, enter hall" + BOLD + " |\n        |                   |\n        %~~~~~~~~~~~~~~~~~~~%\n\n" + NORM + " Don't forget to raise your attributes here!\n"));
}

short() 
{ 
  if(!this_player()) return;
  if(this_player()->query_level() < 8 || 
     this_player()->query_level() > 20) 
    {
      return HIR + "A large sign for new players"+NORM;
    } 
}

get() { return 0; }
