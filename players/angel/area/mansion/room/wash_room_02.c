#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Wash room";
  long_desc =
" \n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/broiler_room_10",  "broiler",
  });
}

init(){ 
  ::init();
    this_player()->set_fight_area();
      }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }