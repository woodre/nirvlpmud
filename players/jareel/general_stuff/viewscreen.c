#include "/players/jareel/define.h"
inherit "obj/treasure.c";

id(str) { return str == "screen" ||  str == "view" || str == "view screen" || str == "viewscreen" || str == "podium"; }

reset(arg){

      if(arg) return;
      no_clean = 1;
      set_short(BOLD+"View Screen"+NORM);
      set_alias("screen");
      set_long("\n"+BOLD+
        "----------------------------------------------------------------------------------.\n"+
        ""+BLU+"  The Hall of Legends is a shrine to the elite players of nirvana.  Players\n"+
	"  may be immortalized in the hall for one of two reasons, when a player reaches\n"+
	"  the level of +100 or if he gains 2000 player killing points.  Once a player\n"+
	"  has reached one of the above goals he gains a room in the hall of Legends.\n"+
	"  If the player so wishes he can purchase the rights to personalize his room\n"+
	"  and help in the creation process of a creature made in his image."+NORM+BOLD+"\n"+
	"----------------------------------------------------------------------------------.\n"+
	"\n\n"+NORM);
      set_read("\n"+BOLD+
	"----------------------------------------------------------------------------------.\n"+
	""+BLU+"  The Hall of Legends is a shrine to the elite players of nirvana.  Players\n"+
	"  may be immortalized in the hall for one of two reasons, when a player reaches\n"+
	"  the level of +100 or if he gains 2000 player killing points.  Once a player\n"+
	"  has reached one of the above goals he gains a room in the hall of Legends.\n"+
	"  If the player so wishes he can purchase the rights to personalize his room\n"+
	"  and help in the creation process of a creature made in his image."+NORM+BOLD+"\n"+
	"----------------------------------------------------------------------------------.\n"+
	"\n\n"+NORM);
     }

      get() { return 0;
     }

