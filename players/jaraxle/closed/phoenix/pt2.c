#include "/players/jaraxle/define.h"


inherit "/obj/treasure.c";

reset(int arg) {
   
   if(arg) return;
   
   set_alias("phoenix idol");
   set_short("Idol of the "+RED+"Phoenix"+NORM+" (body)");
   set_long("This is the body of the Idol of the Phoenix.  The\n"+
      "body is tinted red with two large wings\n"+
      "wrapped down on each side.\n");
}

id(str){ return str == "phoenix_pt2" || str == "phoenix idol" || str == "body" || str == "idol"; }
