#include "/players/feldegast/closed/ansi.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("quest gem");
  set_alias("gem");
  set_short("Gem of Hunting");
  set_long(
    "This gem has been enchanted to warm or cool depending upon\n"+
    "its proximity to the hiding places of the missing items of\n"+
    "Morgoth.\n"
  );
  set_weight(1);
  set_value(50);
}

string get_temp() {
  object room;
  int temp;
  if(environment())
  if(living(environment()))
    room=environment(environment());
  else
    room=environment();
  if(!room) return "cold";
  temp = (int)room->query_temp();
  if(creator(room) != "morgoth")
    return HIB+"freezing"+NORM;
  switch(temp) {
    case 0: return HIC+"cold"+NORM; break;
    case 1: return RED+"warm"+NORM; break;
    case 2: return HIR+"HOT"+NORM; break;
    default: return "void"; break;
  }
}
  
string short() {
  return short_desc+" ("+get_temp()+")";
}

void long() {
  write(long_desc);
  write("The gem is "+get_temp()+".\n");
}
