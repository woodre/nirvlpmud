
/* Sells for 1200 coins in shop */
/* Approved by Daranath, [8/10/02] */
#include "/players/jaraxle/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("roht");
   add_alias("fruit");
   add_alias("roht fruit");
   set_short(RED+"Ro"+BLK+BOLD+"h"+NORM+RED+"t"+NORM+" fruit");
   set_long("This is a small red fruit that is almost rotton.\n"+
      "These fruit are a favorite of the pesants of\n"+
      "Tree-Top Village.\n"+
      "You can either eat, or bite the fruit.\n");
   set_type("bites");
   set_msg("You take a bite out of the fruit.\n"+
      "The juice is tart and smells funny.\n");
   set_msg2(" takes a bite of "+RED+"Ro"+BOLD+BLK+"h"+NORM+RED+"t"+NORM+" fruit.\n");
   add_cmd("eat");
   add_cmd("bite");
   set_heal(50,50);
   set_charges(3);
   set_soak(10);
   set_stuff(10);
   set_value(400);
  /* changed value from 900 to 400, more money from sale than to buy! */
   set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
   set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
   set_msg_precharges(""+RED+"("+BLK+BOLD+"");
   set_msg_postcharges(""+NORM+RED+")"+NORM+"");
   set_type_single("bite"); /* verte */
}
