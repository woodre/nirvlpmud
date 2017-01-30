/* cleanup object for hide-in-shadows */
inherit "obj/monster";
#include "../DEFS.h"


reset(arg)
{
  if(!present("_drivers_seat_")) {
    move_object(clone_object(OBJDIR + "/seat.c"),
    this_object()); 
  }
  do_check();
  if(arg) return 0;
  ::reset(arg);
  set_name("ninjashadows_that_you_cannot_identify");
  set_alias("_hide_in_shadows_vehicle_");
  set_level(10);
  enable_commands();
  set_heart_beat(1);
  set_can_kill(0);
  set_aggressive(0);
   set_ep(0);
   set_no_exp_value();
}

void do_check() {
  if(!present("_drivers_seat_")) {
    destruct(this_object());
    return; 
  }
  call_out("do_check", 10);
}

void catch_tell(string str) {
  tell_room(this_object(), str);
}

string short() { return "The Shadows"; }

string realm() { return "NT"; }

int query_invis() {
  return 19;
}


heart_beat(){
 ::heart_beat();
 heal_self(1000);
 }
