#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Entrance";
  long_desc =
" \n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/hall_10",          "up",
    "/players/angel/area/mansion/room/broiler_room_10",  "down",
    "/players/angel/area/mansion/room/office_10",        "office",
    "/players/angel/area/mansion/room/living_room_10",   "living",
    "/players/angel/area/mansion/room/bed_room_10",      "bed",
  });
}

init(){ 
  ::init();
    this_player()->set_fight_area();
      }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }