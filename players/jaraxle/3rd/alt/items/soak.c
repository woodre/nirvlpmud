#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("spil");
   add_alias("pill");
   add_alias("spill");
   add_alias("pill pack");
   set_short(BOLD+"pill pack"+NORM);
   set_long("A small pack of pills made of a thin plastic material.\n"+
      "There is a swirling "+HIC+"blueish chemical"+NORM+" inside and\n"+
      "a label that reads ["+HIC+"spill"+NORM+"].\n");
   set_type("pills");
   set_type_single("pill");
   add_cmd("swallow");
   set_heal(50,50);
   set_charges(3);
   set_msg_precharges(HIC+"("+NORM);
   set_msg_postcharges(HIC+")"+NORM);
   set_soak(7);
   set_value(600);
   set_msg_soaked(HIR+"You try to swallow a pill but spit it back up!\n"+NORM);
   set_msg(CYN+"You swallow one of the pills from the pack\n"+NORM);
   set_empty_msg(HIC+"You swallow the last pill in the pack.\n"+NORM);
}
