/*  HAYHOOK.C - Carried by FARMER.C in TAVERN.C of Delnoch Keep.
    Has a special that does 1 extra damage.
    Changes as of 5-31-96:
    Color added
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("hayhook");
  set_alias("hook");
  set_short("A "+YEL+"Hayhook"+NORM);
  set_long(YEL+
"A common hayhook, that might be found on any farm.  You notice that\n"+
"this one has a VERY sharp point!\n"+NORM);
  set_class(8);
  set_weight(1);
  set_value(30);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  int W;
  W = random(33);
  if(W>22) {
  say(capitalize(this_player()->query_name())+" rips chuncks of flesh from his foe with the hook.\n");
  write("You hear your opponent scream as the hook connects!\n");
  return 1;
    }
   return;
}
