#include "/players/jaraxle/define.h"


inherit "/obj/treasure.c";

reset(int arg) {
   
   if(arg) return;
   
   
   set_alias("ball");
   
  set_short(YEL+"("+RED+"%"+YEL+")"+NORM+" crystal ball");
   
   set_long("A small crystal ball that is amber in color.  The ball is\n"+
      "transparent enough to see through.  There are "+RED+"5"+NORM+" small stars\n"+
      "in the middle of the ball.\n");
   
}

id(str){ return str == "dbz_5" || str == "5" || str == "crystal" || str == "ball"; }
