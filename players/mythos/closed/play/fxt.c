#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg){
  if(!present("fox")) {
    move_object(clone_object("/players/mythos/closed/play/fx.c"),
      this_object()); }
  if(!arg){
    set_light(4);
    short_desc=GRN+"Garden of War"+NORM;
    long_desc=
  "nothing.\n";
    dest_dir=({
    "/players/mythos/workroom.c","portal",
    });
  }
call_out("mover",5);
}


clean_up() { return 1; }
dest_inv() { return 1; }

mover() {
  move_object(clone_object("/players/mythos/closed/play/fx.c"),this_object());
return 1; }
