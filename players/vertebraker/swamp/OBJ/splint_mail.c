#include "../define.h"

inherit ARMOUR;

reset(arg) {
   if(arg) return;
   ::reset();
   set_name("splintmail");
   set_alias("wooden splintmail");
   set_short(YEL+"wooden splintmail"+NORM);
   set_long(
      "  A suit of wooden splintmail that covers your legs and body\n"+
      "with a thick wooden casing.  Iron latches cover the joints\n"+
      "but still allow flexibility with small leather straps that\n"+
      "hold the armor together.\n");
   set_type("armor");
   set_value(800+random(200));
   set_weight(4);
   set_ac(3); }

do_special(owner) {
   if(!random(8)) {
      tell_object(owner, "Your splintmail takes the brunt of the attack.\n");
      return 1; } }
