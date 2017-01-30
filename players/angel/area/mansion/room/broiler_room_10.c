#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Broiler room";
  long_desc =
" \n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/entrance_10",       "up",
    "/players/angel/area/mansion/room/wash_room_02",      "wash",
    "/players/angel/area/mansion/room/billard_room_10",   "billard",
    "/players/angel/area/mansion/room/storage_room_10",   "storage",
  });
}

init(){ 
  ::init();
    this_player()->set_fight_area();
      }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }