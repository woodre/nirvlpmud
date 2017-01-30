#include "std.h"

int door_is_open;
object gguard;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!gguard || !living(gguard)) {
  object shades;
  gguard = clone_object("obj/monster");
  call_other(gguard, "set_name", "Gate Guard");
  call_other(gguard, "set_alias","guard");
  call_other(gguard, "set_level",9);
  call_other(gguard, "set_hp",225);
  call_other(gguard, "set_wc",13);
  call_other(gguard, "set_ac",7);
/* was lvl 11,wc 8,ac 6 -Bp*/
  call_other(gguard, "set_al",200);
  call_other(gguard, "set_short","The Gate Guard to the Tennis Courts");
  call_other(gguard, "set_long",
    "A muscular young man, dressed in the green and gold Club uniform, \n" +
    "monitors the tennis courts.\n");
  move_object(gguard,this_object());
  shades = clone_object("obj/armor");
  call_other(shades, "set_name","Raybans");
  call_other(shades, "set_alias","sunglasses");
  call_other(shades, "set_short","A pair of expensive Rayban sunglasses");
  call_other(shades, "set_long",
    "Top of the line, Rayban sunglasses.  Shatterproof, waterproof, and\n" +
    "extremely comfortable.\n");
  call_other(shades, "set_ac",0);
  call_other(shades, "set_value",200);
  call_other(shades, "set_weight",0);
/*
  call_other(shades, "set_type","shades");
Chg'd for nirvana */
  call_other(shades, "set_type", "misc");
  transfer(shades,gguard);
  }
  door_is_open = 0;
}
 
#undef EXTRA_LONG
#define EXTRA_LONG\
  if(str == "door") {\
    if(door_is_open) {\
    write("The gate is open.\n");\
    return;\
    }\
  write("The gate is closed.\n");\
  return;\
  }
 
#if 0
#ifndef __LDMUD__ /* Rumplemintz */
#undef EXTRA_INIT
#define EXTRA_INIT\
  add_action("open"); add_verb("open");\
  add_action("north"); add_verb("north");\
#else
#undef EXTRA_INIT
#define EXTRA_INIT add_action("open","open"); add_action("north","north");
#endif
#endif

#undef EXTRA_INIT
#define EXTRA_INIT add_action("open","open"); add_action("north","north");
 
THREE_EXIT("players/aislinn/direct2", "east",
	   "players/aislinn/shady_path", "west",
	   "players/aislinn/courts_1n2", "north",
	   "Entrance to Tennis Courts",
   "This is the entrance to the Tennis Courts.  The fence that surrounds \n" +
   "the courts is well over 20 feet tall and cannot be scaled.  Looking\n" +
   "through the fence you see 8 grass courts, in absolutely pristine \n" +
   "condition.  The trees surrounding the area keep the temperature at\n" +
   "a comfortable level and serve as a wind break.\n" +
   "   \n", 1)
 
id(str) {
  return str == "gate";
}
 
open(str) {
  if(str && str != "gate")
    return 0;
  if(door_is_open)
    return 0;
door_is_open = 1;
write("Ok.\n");
say(call_other(this_player(), "query_name") + " opened the gate.\n");
return 1;
}
 
north() {
  if(!door_is_open) {
  write("The gate is closed.\n");
  return 1;
}
 
if(gguard && present (gguard,this_object())) {
  write("The guard says 'Members only!'\n");
  return 1;
}
call_other(this_player(),"move_player","north#players/aislinn/courts_1n2");
return 1;
}
 