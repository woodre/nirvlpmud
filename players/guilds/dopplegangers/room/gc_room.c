/*
 * Doppleganger Guild Commander room
 */

inherit "room/room";

void reset(status arg) {
  if (arg)
    return;
  set_light(1);
  if (!present("box"))
    move_object(clone_object("players/grimm/closed/obj/badge_stuff/vbox"),
                this_object());
  if (!present("cboard"))
    move_object(clone_object("players/guilds/dopplegangers/obj/cboard"),
                this_object());
  short_desc = "Commander's Hideout";
  long_desc = "This is a hideout for Doppleganger Guild Commanders only.\n";
  dest_dir = ({
    "players/guilds/dopplegangers/room/guild", "guild",
    "players/guilds/dopplegangers/room/guildhall", "north",
    "room/shop", "shop",
    "room/church", "church",
    "room/adv_guild", "adventurers",
    "room/pub2", "pub",
  });
}

void init() {
  ::init();
  add_action("list", "list");
}

int list() {
  write("Current Guild Hierarchy:\n");
  write("  Guild Master:      Grimm\n");
  write("  Guild XO:          Rumplemintz\n");
  write("  Guild Wizzies:     None\n");
  write("  Guild Senior:      Rump\n");
  write("  Guild Commanders:  None\n");
  return 1;
}
