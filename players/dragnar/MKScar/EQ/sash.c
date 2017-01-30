#include <ansi.h>
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

reset(arg){
::reset(arg);
  set_short(HIR+"Sash of Fire"+NORM);
  set_long(
    "It is the color of a bed of coals.  It even feels hot to the touch.  It was\n"+
	"made to be worn around the head to keep your vision clear during battle.\n"+
	"It doesn't seem like a formidable piece of armor, but something magical\n"+
	"about its heat makes you think it could still be useful to you.\n");
  set_ac(0);
  set_weight(1);
  set_value(1400);
  set_alias("sash");
  set_name("sash of fire");
  set_type("misc");
}

do_special(owner){
  if(USER->query_attrib("mag") > random(150) && ATT){
    ATT->hit_player(USER->query_attrib("mag")/2,"magical");
    tell_object(USER,
      "The heat from your sash erupts and a fireball flies from your hands.\n"+
      "     "+RED+"\tThe fireball engulfs "+ATT->query_name()+" in a ball of flames."+NORM+"\n");
    tell_room(environment(USER),
    USER->query_name()+" fires a fireball and engulfs "+ATT->query_name()+" in a ball of flames.\n", ({USER}));
    return 0;
  }
  return 0;
}	
