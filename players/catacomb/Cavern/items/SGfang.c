inherit "/obj/armor";
#include "/players/catacomb/misc/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("fang");
  set_short(HIB+"Shimmergloom's fang"+NORM);
  set_long(
	"  One of the shadow dragon's fangs hangs around one of its tendons.\n"+
	"The fang seems to consume the light around it forming a dark mist.\n");
  set_type("amulet");
  set_ac(2);
  set_params("other|mental", 1, 15, "mental_protect");
  set_weight(2);
  set_value(3000);
}
int 
mental_protect()
{
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
  if (random(10) == 3)
  tell_object(this_player(),
	"\nThe mist around the fang gives off an eerie glow.\n\n");
  return 0200;
}
query_save_flag()
{ 
  return 1;
}
