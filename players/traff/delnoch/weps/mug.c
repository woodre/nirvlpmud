/*  MUG.C - Carried by BARKEEP.C in TAVERN.C of Delnoch Keep.
    Changes as of 5-31-96:
    Color added
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wooden mug");
   set_alias("mug");
   set_short(HIY+"A Wooden Mug"+NORM);
   set_long(HIY+"A large, heavy, wooden mug, with a rope handel.\n"+NORM);
   set_read(HIG+"Olaf's wood products\n"+NORM);
   set_class(7);
   set_weight(1);
   set_value(100);

   set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s mug hits suprisingly hard!\n");
	write("You hit hard with your mug.\n");
  return 1;
    }
   return 0;
}
