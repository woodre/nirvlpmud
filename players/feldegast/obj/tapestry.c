#include "/players/feldegast/defines.h"

inherit "/obj/treasure";

object room;
reset(arg) {
  set_id("tapestry");
  set_short("A tapestry");
  set_long(
"This is a vivid tapestry with a complex red border around\n"+
"the image of a beautiful woman in a purple dress standing\n"+
"by a window with a view of a sun setting over a mountain.\n"
  );
  set_weight(3);
  set_value(6000);
  set_read("Although you can make out ancient runes worked into the borders,\n"+
           "you cannot decipher their meaning.\n");
}
init() {
  ::init();
  add_action("cmd_enter","enter");
}
cmd_enter(str) {
  if(str=="tapestry") {
    if(environment()->is_player()) {
      write("You cannot enter the tapestry while you're holding it!\n");
      return 1;
    }
    if(environment()->realm()=="NT") {
      write("You cannot enter the tapestry for some reason.\n");
      return 1;
    }
    if(!room) {
      room=clone_object("/players/feldegast/realm/tapestry_room");
      room->set_tapestry(this_object());
    }
    write("You step into the tapestry.\n");
    say(TPN+" steps into the tapestry.\n");
    move_object(TP,room);
    return 1;
  }
  notify_fail("Enter what?\n");
}
