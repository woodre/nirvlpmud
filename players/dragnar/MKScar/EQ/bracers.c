#include <ansi.h>
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

reset(arg){
::reset(arg);
  set_short("A pair of"+HIB+" Bracers"+NORM+".");
  set_long(
    "These bracers are made to be worn from just below the elbow down to your\n" +
    "hands.  This pair has a special extension that protects your hands as well.\n"+
	"The craftsmanship of the armor is exceptional, but they have a magical feel\n"+
	"to them that is unmistakable.  That must be the reason for the intense\n"+
	"color, and the reason they feel increadibly cold to the touch.\n");
  set_ac(1);
  set_weight(1);
  set_value(1100);
  set_alias("bracers");
  set_name("bracers");
  set_type("ring");
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
      write("You gasp for breath as the cold of the bracers freezes your skin.\n");
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
      "You rotate your wrist and fire a magical ball of ice.\n"+
      "     "+HIB+"\tA frozen trail of vapor explodes upon "+ATT->query_name()+"."+NORM+"\n");
    tell_room(environment(USER),
    USER->query_name()+" fires a ball of ice at "+ATT->query_name()+".\n", ({USER}));
    return 0;
  }
  return 0;
}	
