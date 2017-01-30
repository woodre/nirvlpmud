#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("phoenix ashes");
   set_short("A pile of ashes");
   set_long("A dark black mound of ashes.\n");
   set_weight(1);
   set_value(1+random(10));
}

void long(string arg)
{
   ::long(arg);
   if(this_player()->query_attrib("int") > random(40))
      return (write("You may be able to search the ashes.\n"));
}

id(str){ return str == "ashes" || str == "mound" || str == "pile of ashes" || str == "pile"; }

init() {
   
   ::init();
   
   add_action("cmd_search","search");
   
}


cmd_search(str) {
   if(!str){ notify_fail("Search what?\n"); return 0; }
   if(!id(str)) return (notify_fail("You may search " + short_desc + ".\n"), 0);
   write("You search the ashes and find a "+RED+"Phoenix"+NORM+" tear.\n");
   write("\tThe ashes blow away.\n");
   MOCO("/players/jaraxle/closed/phoenix/heals/tear.c"), TP);
   MOCO("/players/jaraxle/closed/phoenix/heals/tear.c"), TP);
   destruct(TO);
   return 1; }
