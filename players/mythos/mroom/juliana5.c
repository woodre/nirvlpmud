#include "/players/mythos/closed/ansi.h"
inherit "room/room";
object ob, ob2;
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle3.c"),this_object()); }
  if(!present("dancer")) {
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
    move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); 
    }
  if(!arg) {
  set_light(1);
    short_desc = "<<Juliana's Tokyo- Stage>> ";
    long_desc =
    BLU+"                    STAGE FLOOR\n\n"+NORM+
        "You step up onto the dance stage, where some people are\n"+
        "doing moves that astound you.  The lights are flashing and\n"+
        "the music beats into you like a giant heartbeat....\n"+
        "Let go of yourself and dance!\n";
  items = ({
    "floor","Head back down to the main floor",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana3.c","floor",
  });
} }

init() {
  ::init();
  if(!present("dancer")) {
    ob = clone_object("/players/mythos/mmon/dance.c");
    if(random(5) == 0) { ob->set_aggressive(1); }
    move_object(ob,this_object()); 
    ob2 = clone_object("/players/mythos/mmon/dance.c");
    if(random(7) == 0) { ob2->set_aggressive(1); }
    move_object(ob2,this_object());
    move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
    move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); 
    }
 }
