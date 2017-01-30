/*
  alchemist_player_board_room.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

object board;
string str, new_title, male_title_str, fem_title_str, neut_title_str, my_gender;
int i, player_level;

init() {
  ::init();

  check_membership(this_player());
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
      ALCHEMIST_CENTRAL, "east",
    });
  if (!present("board", this_object())) {
    move_object(clone_object("players/nooneelse/Alchemist/obj/player_board"),
                this_object());
  }
}

realm() { return "NT"; }
