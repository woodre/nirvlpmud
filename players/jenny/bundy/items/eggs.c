#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("cockroach eggs");
   set_alias("eggs");
   
   set_short("cockroach eggs");
   
   set_long(
      "These are the eggs of a cockroach.  They look pretty gross.\n"+
      "It is unclear what to do with these.  Most sane people would\n"+
      "not even touch them.\n");
   
   set_weight(1);
   set_value(64+random(20));
   set_dest_flag(1);
}
