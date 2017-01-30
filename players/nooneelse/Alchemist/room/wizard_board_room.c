/*
  alchemist_wizard_board_room.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

init() {
  ::init();

  add_action("south", "south");
  check_membership(this_player());
}

south() {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return;
  this_player()->move_player("south#"+ALCHEMIST_PROHIBIT);
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc =
    "The ALchemist Guild's Bulletin Board Room\n";
  no_castle_flag=1;
  long_desc =
    "You can leave messages here on our private board.\n";
  dest_dir =
    ({
      ALCHEMIST_CENTRAL, "north",
    });
  if (!present("board", this_object())) {
    move_object(clone_object("/players/nooneelse/Alchemist/obj/wizard_board"), this_object());
  }
}

realm() { return "NT"; }
