#include "/players/feldegast/defines.h"

inherit "/room/room";

object tapestry;

reset(arg) {
  if(arg) return;
  if(!present("vedira")) {
    object vedira;
    vedira=clone_object("/players/feldegast/mon/vedira");
    move_object(vedira,this_object());
  }
  short_desc="Tapestry";
  long_desc=
"    This is an odd looking room that appears to only have\n"+
"furnishings on one side, near a window looking out on a\n"+
"mountain that looks like a huge stone fist.  A chest sits\n"+
"under a sidetable on the 'left' side of the room.\n";
  set_light(1);
  items=({
  });
}
realm() {
  return "NT";
}
set_tapestry(ob) {
  tapestry=ob;
}
init() {
  ::init();
  add_action("cmd_leave","leave");
  add_action("cmd_leave","exit");
  add_action("cmd_leave","out");
  add_action("cmd_leave","back");
}
cmd_leave() {
  if(!environment(tapestry)) {
    write("You can't leave!\n");
    return 1;
  }
  if(environment(tapestry)->realm()=="NT") {
    write("You can't leave the tapestry for some reason.\n");
    return 1;
  }
  if(environment(tapestry)->is_player() ||
     environment(tapestry)->is_npc()) {
    write("You cannot leave the tapestry until "+environment(tapestry)->query_name()+" drops it.\n");
    return 1;
  }
  write("You step out of the tapestry.\n");
  move_object(TP,environment(tapestry));
  say(TPN+" steps out of the tapestry.\n");
  command("look",this_player());
  return 1;
}
