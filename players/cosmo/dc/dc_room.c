/*
CAUTION: ** WORK IN PROGRESS **
My standard room for the DC area. This inherits ~/myroom, which
in turn inherits /room/room.
*/

#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/myroom";

/* Type of monster to be generated */
string mon_type;

set_room_type(str) {
  no_castle_flag = 0;
  mon_type = "";
  switch(str) {
    case "path":
      set_light(query_light());
      if(!smell_msg) smell_msg = "The air smells hot and stale.";
      if(!sound_msg) sound_msg = "Lots of commotion can be heard in the "+
                                 "distance.";
    break;
    case "street":
      set_light(query_light());
      if(!smell_msg) smell_msg = "You cough violently from the pollution.";
      if(!sound_msg) sound_msg = "You are amazed by the constant sounds "+
                                 "of the city.";
      mon_type = "cop";
    break;
    case "building":
      set_light(1);
      if(!smell_msg) smell_msg = "You take in a deep breath of the "+
                                 "freshly scented air.";
      if(!sound_msg) sound_msg = "You hear quiet whispering from "+
                                 "tourists in other rooms.";
      mon_type = "guard";
    break;
    default:
      set_light(query_light());
      if(!smell_msg) smell_msg = "You smell nothing.";
      if(!sound_msg) sound_msg = "You hear nothing.";
    break;  
  }
  return 1;
}

init() {
  ::init();
  if(mon_type!="" && random(2) && !present(mon_type))
    call_out("get_mon",5);
}

get_mon() {
string fname;
object mob;
  fname = DCMON+mon_type+".c";
  if(fname->query_mon()) {
    mob = call_other(fname, "make_mon", random(3));
    move_object(mob, TO);
    tell_room(TO, fname->random_room_msg());
  }
  return 1;
}
