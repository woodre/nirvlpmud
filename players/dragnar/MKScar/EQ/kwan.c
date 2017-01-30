#include <ansi.h>
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

reset(arg){
::reset(arg);
  set_short(HIY+"Mooduck Kwan"+NORM);
  set_long(
    "This mooduck kwan has been slightly modified from the traditional design.\n"+
	"It is made without sleeves, to provide easier movement.  It also has a non-\n"+
	"traditional bright yellow color that is almost blinding.  The black\n"+
	"stripe that runs down the middle of the armor is rather unusual as well.\n"+
	"It seems to radiate some kind of energy, and it makes you hunger for blood.\n");
  set_ac(2);
  set_weight(1);
  set_value(1400);
  set_alias("mooduck");
  set_name("kwan");
  set_type("armor");
}

do_special(owner){
  if(USER->query_attrib("wil") > random(150) && ATT){
    ATT->hit_player(USER->query_attrib("wil")/2,"magical");
    tell_object(USER,
      "The energy from your Mooduck Kwan explodes and a spear flies from your hand.\n"+
      "     "+HIY+"\tThe spear impales "+ATT->query_name()+" in the chest."+NORM+"\n");
    tell_room(environment(USER),
    USER->query_name()+" fires a spear and impales "+ATT->query_name()+" in the chest.\n", ({USER}));
    return 0;
  }
  return 0;
}	
