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
         "players/grimm/rooms/haphaz_a12", "north",
/*
         "players/grimm/bguild", "west",
*/
         "players/guilds/dopplegangers/room/barbarian_entrance", "west",
         "players/grimm/rooms/haphaz_b12", "northeast",
        });
}

query_light() {
    return -1;
}

/*
init() {
  ::init();
  add_action("west","west");
}

west() {
  if(FINAL>time()) {
    write("That way is blocked for right now...try again at Midnight on Friday.\n");
    return 1;
  }
  this_player()->move_player("west#/players/grimm/bguild");
  return 1;
}
*/
