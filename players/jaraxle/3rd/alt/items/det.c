#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("spil");
   add_alias("pill");
   add_alias("pill pack");
   set_short(BOLD+"pill pack"+NORM);
   set_long("A small pack of pills made of a thin plastic material.\n"+
      "There is a swirling "+HIM+"purple chemical"+NORM+" inside and\n"+
      "a label that reads ["+HIM+"spil"+NORM+"].\n");
   set_type("pills");
   set_type_single("pill");
   add_cmd("swallow");
   set_heal(0,0);
   set_charges(5);
   set_msg_precharges(HIM+"("+NORM);
   set_msg_postcharges(HIM+")"+NORM);
   set_soak(-7);
   set_stuff(-7);
   set_value(200);
   set_msg_soaked(HIR+"You try to swallow a pill but spit it back up!\n"+NORM);
   set_msg(MAG+"You swallow one of the pills from the pack\n"+NORM);
   set_empty_msg(HIM+"You swallow the last pill in the pack.\n"+NORM);
}
