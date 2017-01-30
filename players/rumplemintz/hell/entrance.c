#include "path.h"
inherit "room/room";

reset(arg) {
  EXISTS("cereberus",MON+"cerberus");
  if(arg) return;

  set_light(1);
/*
  set_inside(1);
*/
  short_desc="Entrance to the pits of hell";
  long_desc="You are at the Entrance to the Pits of Hell\n"
           +"Dare you jump?\n"
           +"WARNING!  THIS IS FOR LEVEL "+LEVHELL+" PLAYERS AND UP.\n";
  dest_dir=({
    "players/rumplemintz/workroom","back",
    PATH+"pit1","jump",
  });
}

init() {
  ::init();
  add_action("jump","jump");
}

jump() {
  if(!present("cerberus",this_object()))
    return 0;
  write("Cerberus snarls at your attempt to pass.\n");
  return 1;
}
