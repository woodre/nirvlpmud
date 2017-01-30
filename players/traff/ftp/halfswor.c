/*  HALFSWORD.C - Carried by TRAINER.C in PANTRY.C of Delnoch Keep
    This sword has a special that hits for 5 against HALFLINGS,
    or 1 against players.
    Changes as of 5-31-96:
    Color added
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("sword");
   set_alias("blade");
   set_short(WHT+"A sword"+NORM);
   set_long(BOLD+
   "A small sword, yet as you hold it you get a feeling of power\n"+
   "When you think of the Halflings you have heard of, you can feel\n"+
   "the blade pulse in your hand.\n"+NORM);
   set_read(RED+"Halfling's Bane"+WHT+" - Forged by Azkar\n"+NORM);
   set_class(16);
   set_weight(2);
   set_value(1000);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(call_other(attacker,"id","halfling")) {
    say(this_player()->query_name()+"'s blade rips deeply into the Halfling.\n");
    write("Your blade seems to lust for the halfling's blood!\n");
  return 5;
  }
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s sword hits suprisingly hard!\n");
	write("You hit hard with your sword.\n");
  return 1;
    }
   return 0;
}
