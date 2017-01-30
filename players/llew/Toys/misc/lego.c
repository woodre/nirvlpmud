#include "/players/llew/closed/ansi.h"

inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("lego");
   set_alias("block");
   switch(random(6)+1) {
      case 1: set_short("A "+HIR+"red lego block"+NORM); break;
      case 2: set_short("A "+HIB+"blue lego block"+NORM); break;
      case 3: set_short("A "+GRN+"green lego block"+NORM); break;
      case 4: set_short("A "+HIY+"yellow lego block"+NORM); break;
      case 5: set_short("A "+HIW+"white lego block"+NORM); break;
      case 6: set_short("A "+HIM+"purple lego block"+NORM); break;
   }
   set_long("The block is rectangular with "+((random(4)+1)*2)+" segments.\n");
   set_value(101+random(100));
   set_weight(1);
   set_dest_flag(1);
}
