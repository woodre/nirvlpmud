#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("fpil");
   add_alias("pill");
   add_alias("fpill");
   add_alias("pill pack");
   set_short(BOLD+"pill pack"+NORM);
   set_long("A small pack of pills made of a thin plastic material.\n"+
      "There is a swirling "+HIY+"yellowish chemical"+NORM+" inside and\n"+
      "a label that reads ["+HIY+"fpill"+NORM+"].\n");
   set_type("pills");
   set_type_single("pill");
   add_cmd("swallow");
   set_heal(50,50);
   set_charges(3);
   set_msg_precharges(HIY+"("+NORM);
   set_msg_postcharges(HIY+")"+NORM);
   set_stuff(7);
   set_value(600);
   set_msg_soaked(HIR+"You try to swallow a pill but spit it back up!\n"+NORM);
   set_msg(YEL+"You swallow one of the pills from the pack\n"+NORM);
   set_empty_msg(HIY+"You swallow the last pill in the pack.\n"+NORM);
}
