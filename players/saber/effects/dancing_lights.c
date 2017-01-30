inherit "obj/treasure";
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int chance;

reset(arg)  {
  if(arg) return;
    set_id("dancing_lights");
    set_weight(100);
call_out("dance",15);
call_out("bye_bye",150 + random(100));
}

bye_bye() {
if(!environment(this_object())) return 1;
  tell_room(environment(this_object()),
    "\nThe dancing balls of "+HIR+"-fire-"+NORM+" fade away.\n\n");
  remove_call_out("dance");
  destruct(this_object());
  return 1;
}

dance()  {
  chance = random(4);
  
  if(chance == 0)  {
    tell_room(environment(this_object()),
    "\nThe dancing balls of "+HIR+"-fire-"+NORM+" whirl about the room.\n\n");
        }
  if(chance == 1)  {
    tell_room(environment(this_object()),
    "\nSpheres of "+HIR+"-fire-"+NORM+" spin about the chamber.\n\n");
        }
  if(chance == 2)  {
    tell_room(environment(this_object()),
    "\nWhirling balls of "+HIR+"-fire-"+NORM+" shimmer through the air.\n\n");
        }
  if(chance == 3)  {
    tell_room(environment(this_object()),
    "\nSmall spheres of "+HIR+"-fire-"+NORM+" explode all around you.\n\n");
        }
  call_out("dance",random(35));
  return 1;
        }        
        
get()  { return 1; }
drop() { return 1; }
