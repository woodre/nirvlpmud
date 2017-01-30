inherit "/obj/weapon.c";
#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()->query_name()
#define ATN attacker->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("spear");
  set_short("A long spear");
  set_long(
 "  The long shaft provides excellent reach to those skilled in its use.\n"+
 "At the end an intricately carved spike, complete with barbs for snaring \n"+
 "enemies, is made from a strange metal.\n" );
  set_type("polearm");
  set_class(16);
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object()); 
}
  mixed
  weapon_hit(object attacker) 
  {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random(25) > 20) {
     write("       You impale "+ATN+" with the spear hooking the barbs.\n");
     write("          You quickly withdraw the spear from "+ATN+".\n");
     write("      "+RED+"B  L  O  O  D"+NORM+" gushes out the wound.\n");
     say(TPN+" impales"+ATN+", B  L  O  O  D gushes from the wound.\n");
     return 3; 
    }
    return 0;
  }

  
