#include <ansi.h>
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

reset(arg){
::reset(arg);
  set_short(BLK+BOLD+"Sonic Boots"+NORM);
  set_long(
    "These boots are as black as night.  It is not so much the color that is\n"+
	"unnerving, but more the lack of color.  To the touch, the boots seem to\n"+
	"be almost alive because of a steady vibration that they produce.  It feels\n"+
	"eerily like a heartbeat.\n");
  set_ac(1);
  set_weight(1);
  set_value(1100);
  set_alias("boots");
  set_name("boots");
  set_type("boots");
}

wear( str ) {
  object invob;
  int found;
  
  int stealth;
  if(id(str) && this_player() && this_player()->is_player()){
    for(invob = first_inventory(this_player()); invob && !found; invob = next_inventory(invob))
    {
      if(invob->query_type() == type)
       found = invob->query_worn();
    }
    if(!found && !worn )
    {
      write("Your body is wracked by waves of intense vibrations.\n");
	  this_player()->hit_player(random(50)+25);
  	return ::wear(str);
    }
  }
  return ::wear(str);
}
do_special(owner){
  if(USER->query_attrib("int") > random(200) && ATT){
    ATT->hit_player(USER->query_attrib("int")/2,"magical");
    tell_object(USER,
      "You summon a sonic wave.\n"+
      "     "+HIR+"\tBlood gushes from "+ATT->query_name()+"'s ears."+NORM+"\n");
    tell_room(environment(USER),
    USER->query_name()+" fires a sonic wave of energy at "+ATT->query_name()+".\n", ({USER}));
    return 0;
  }
  return 0;
}	
