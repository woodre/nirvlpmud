#include <ansi.h>

inherit "/room/room.c";

reset(arg)
{
  ::reset(arg);
  if(!present("klingon", this_object()) )
  {
    object klingon;
    klingon = clone_object("/players/rich/area/npc/klingon.c");
    move_object(klingon, this_object());
  }
  if(arg) return;
  set_short("Visitors' Lounge");
  set_long("  \
Welcome to the Visitors' Lounge on the NC-1701 Constellation Class\n\
Starship \"Enterprise\". The lounge is used as a reception area for\n\
visiting guests and dignitaries that come to tour and spend time on\n\
the ship. Often times there are heated discussions held between some\n\
of the guests whose opinions, customs and traditions conflict.\n");
  add_exit("players/rich/hall2.c", "west");
}
