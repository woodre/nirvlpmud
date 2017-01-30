
/* Sells for 1800 coins in shop */
/* Approved by Daranath, [8/10/02] */
#include "/players/jaraxle/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("kool");
   add_alias("fruit");
   add_alias("kool fruit");
   set_short(HIR+"K"+HIW+"oo"+HIR+"l"+NORM+" fruit");
   set_long("This is a bright red fruit with a dark, blood\n"+
      "red center.  This fruit is the juciest of all\n"+
      "fruits from the Tree-Top Village.\n"+
      "You can either eat, or bite the fruit.\n");
   set_type("bites");
set_msg("You bite the fruit and drink out the sweet juice.\n");
set_msg2("  bites the "+HIR+"K"+HIW+"oo"+HIR+"l"+NORM+" fruit and drinks out the sweet juice.\n");
   add_cmd("eat");
   add_cmd("bite");
   set_heal(0,75);
   set_charges(3);
   set_soak(15);
   set_value(600);
   set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
   set_msg_precharges(""+HIR+"("+HIW+"");
   set_msg_postcharges(""+NORM+HIR+")"+NORM+"");
   set_type_single("bite"); /* verte */
    set_empty_msg("You finish the last bite of the Kool fruit.\n");
}

