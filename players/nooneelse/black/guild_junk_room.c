/*
 guild_junk_room.c
*/

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

init() {
  ::init();

  check_membership(this_player());
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Vampire Guild's Junk room");
  no_castle_flag=1;
  long_desc=
    "This is a clean, well lit room.  Anyone with more money than they need\n"+
    "& a kind heart can leave extra equipment here for lower level players\n"+
    "or those down on their luck.  If anything is here, feel free to take\n"+
    "it.  (Please don't take it if you don't need it though. :)\n";
  dest_dir=
    ({
  "players/eurale/Vamp/RMS/wing_room.c","east",
    });
}

realm() { return "NT"; }

is_castle() { return 1; }

clean_up() { return 0; }
