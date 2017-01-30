#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("dover nut");
   add_alias("nut");
   set_short("Dover nut");
   set_long("This large nut picked from the oldest oaks\n"+
      "of the Tree-Top village has been used for\n"+
      "curing wounds throughout the years.\n");
   set_type("bites");
   set_type_single("bite");
   set_msg(HIW+"\t-= "+NORM+YEL+"You take a nibble from the Dover Nut."+HIW+" =-\n"+NORM);
   add_cmd("bite");
   set_heal(50,50);
   set_charges(3);
   set_msg_precharges(YEL+"["+NORM);
   set_msg_postcharges(YEL+"]"+NORM);
   set_stuff(7);
   set_value(600);
   set_msg_stuffed("You are too full to take another bite!\n");
   set_empty_msg(HIW+"\t~"+HIY+"You take the last bite."+HIW+"~\n"+NORM);
}
