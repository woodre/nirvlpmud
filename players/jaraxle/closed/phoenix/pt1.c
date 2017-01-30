#include "/players/jaraxle/define.h"


inherit "/obj/treasure.c";

reset(int arg) {
   
   if(arg) return;
   
   set_alias("phoenix idol");
   set_short("Idol of the "+RED+"Phoenix"+NORM+" (head)");
   set_long("This is the head of the Idol of the Phoenix.  The\n"+
      "head is pristine in condition and tilted to the west.\n"+
      "The mouth is slightly open and the eyes are jewelled\n"+
      "with red rubies.\n");
}

id(str){ return str == "phoenix_pt1" || str == "phoenix idol" || str == "head" || str == "idol"; }
