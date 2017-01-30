/*
 * Recoded entrance so that wandering objects don't bug on exits in original
 * -- Rumplemintz
 */

inherit "room/room";

void reset(status arg) {
  if (!present("wally"))
    move_object(clone_object("players/grimm/newbie/monsters/wally"),
                this_object());
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  short_desc = "Then entrance way";
  long_desc =
"This is the entrance to Grimm's world.  To the south you can see a newbie\n" +
"area.  To the west is the best guild on the mud (grin).  To the east is\n" +
"Omar's Novelty Shop, although it looks abandoned. North is the mud's main\n" +
"road, and down is a vast cavern area.\n";
  dest_dir = ({
    "players/guilds/dopplegangers/room/guild_entrance", "west",
    "players/grimm/newbie/rooms/room1", "south",
#if 0
    "players/grimm/novelty", "east",
#endif
    "room/vill_green", "north",
    "players/grimm/rooms/enter1", "down"
  });
}

void init() {
  ::init();
  add_action("newbie_check", "south");
  add_action("shop_closed", "east");
}

int newbie_check() {
  if ((int)this_player()->query_level() > 5 &&
      (int)this_player()->query_level() < 20) {
    write("\n\n" +
"The salesman jumps in front of you and starts rambling again.\n" +
"The salesman says: Whoa, Whoa, Whoa, Kimosabe! That is for people that\n" +
                   "are under level 6!\n" +
"The salesman says: You should try going DOWN from here!\n" +
"The salesman says: That is much more suited to YOUR needs.\n");
    return 1;
  }
  return 0;  /* Allow it */
}

int shop_closed() {
  write("You notice the doors are locked shut.\n" +
        "There is a note tacked on the door that reads:\n" +
        "\"MOVED TO THE TREEHOUSE MALL\"\n");
  return 1;
}

