/*  Changed to new heal format 7/29/02 - Eurale  */
/*  Cost:  -14 soak @ 20/per = 280 * 5 drinks = 1400  */

/* Multiplied cost @ shop * 2 per new detox rules.
- Jaraxle [jan 4 '04 ] */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("maalox");
   add_alias("tablets");
   add_alias("tablet");
   set_short(HIM+"maalox tablets"+NORM);
   set_long(
      "Five pink, round tablets of maalox to sooth the upset stomach.  The directions\n"+
      "on the side say:  'Use as directed.  Chew tablets as needed for relief.'\n");
   
   add_cmd("chew");
   set_type("tablets");
   set_type_single("tablet");
   set_msg(
      HIM+"You chew up the chalky tablet and feel instantly better.\n"+NORM);
   set_msg2(
      " chews up a small, pink tablet.\n");

   /*
   set_heal(0,0);
   Noted out due to detox rule changes [jan 4 '04] - Jaraxle */
/*
   set_heal(-7+(-7/3), 0);
*/
   set_heal(-10, 0);
   /* Changed to update to rules [jan 4 '04] - Jaraxle */

   set_charges(5);
   set_msg_precharges("");
   set_msg_postcharges("");
   set_soak(-7);  /*  intox  soak  stuff  */
   set_stuff(-7);
   set_value(150);
   set_empty_msg(
      HIM+"You chew up the LAST tablet and feel much better.\n"+NORM);
}

query_save_flag() { return 1; }
