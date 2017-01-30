#define FINAL 741070800
inherit "room/room";

reset(arg) {
    if (arg) return;

    short_desc = "Foggy Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a foggy room.  There is a mist here that highly resembles\n"
        + "a thick cloud of dust.  Breathing is difficult, but possible.  The walls\n"
        + "are rough and seem to have been made in a hurry.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_c4", "south",
#if 0
         "players/grimm/mguild", "west",
#else
         "players/guilds/dopplegangers/room/mystic_entrance", "west",
#endif
         "players/grimm/rooms/haphaz_d4", "southeast",
         "players/grimm/rooms/haphaz_d3", "east",
        });
}

query_light() {
    return -1;
}

init() {
  ::init();
  add_action("west","west",1);
}

west() {
  if(FINAL>time()) {
    write("That direction is blocked for now...try again Friday at Midnight.\n");
    return 1;
}
#if 0
  this_player()->move_player("west#players/grimm/mguild");
#else
  this_player()->move_player("west#players/guilds/dopplegangers/room/mystic_entrance");
#endif
  return 1;
}
