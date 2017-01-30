
/* Sells for 1800 coins in shop */
/* Approved by Daranath, [8/10/02] */
#include "/players/jaraxle/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("lychee");
   add_alias("fruit");
   add_alias("lychee fruit");
   set_short(HIC+"Ly"+BLK+BOLD+"ch"+HIC+"ee"+NORM+" fruit");
   set_long("This fruit is grown in bunches, rather large\n"+
      "they are grown three to a bunch and sold as such.\n"+
      "The fruit is dry, and not very juicy at all.\n"+
      "You can either eat, or bite the fruit.\n");
   set_type("bites");
set_msg("You pluck a lychee from the bunch and swallow it whole.\n");
set_msg2(" plucks a lychee from the bunch and swallows it whole.\n");
   add_cmd("eat");
   add_cmd("bite");
   set_heal(75,0);
   set_charges(3);
   set_stuff(15);
   set_value(600);
   set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
   set_msg_precharges(""+HIC+"("+BLK+BOLD+"");
   set_msg_postcharges(""+NORM+HIC+")"+NORM+"");
   set_type_single("bite"); /* verte */
}
