/*
 * Doppleganger guild hall
 */

inherit "room/room";

int peeps;

void reset(int arg) {
  object board;

  if (arg)
    return;
  if (!present("poker machine"))
    move_object(clone_object("/players/grimm/closed/obj/poker"), this_object());
  if (!present("Guild Board")) {
    board = clone_object("/obj/ill_board");
    board->set_name("Guild Board");
    board->set_data_dir("players/guilds/dopplegangers/log/");
    move_object(board, this_object());
    board->restore_board();
  }

  set_light(1);
  short_desc = "Doppleganger's Guild Party Room";
  long_desc =
"This is the Doppleganger's Party Room.  You are obviously in the guild \n" +
"so this is the place for you to mingle with everybody and spend some \n" +
"time away from the scum of the mud, since only the chosen can enter \n" +
"this room.\n";
  dest_dir = ({
    "players/guilds/dopplegangers/room/info_room", "west",
    "players/guilds/dopplegangers/room/guild_entrance", "east",
    "room/church", "church",
    "room/shop", "shop",
    "players/guilds/dopplegangers/room/guild_entrance", "guild",
    "room/adv_guild", "adventurers",
    "room/pub2", "pub",
  });
}

void init() {
  ::init();
  if ((string)this_player()->query_guild_name() != "doppleganger" &&
      (int)this_player()->query_level() < 20) {
    write("\n\nYOU ARE NOT A DOPPLEGANGER!\n");
    write("Only the chosen will be allowed to enter here!\n");
    say(this_player()->query_name() + " tried to enter but gets kicked!\n");
    move_object(this_player(), "players/guilds/dopplegangers/room/entrance");
    write("You must join our guild before entering there.\n");
    return;
  }
  add_action("list", "list");
  add_action("south", "south");  /* Hidden GC exit */

  peeps++;
  while(remove_call_out("heal_em") != -1);
  call_out("heal_em", 2, this_player());

}

void heal_em(object ob) {
  if (!ob || !present(ob, this_object())) return;
/*
  if (ob->query_hp() == ob->query_mhp()) {
    tell_object(ob, "Your wounds have been fully healed.\n");
    return;
  }
*/
  ob->heal_self(3 + random(3));
  call_out("heal_em", 2, ob);
}

mixed exit(object ob) {
  if (ob->is_player()) {
    peeps--;
    if (peeps <= 0)
      while(remove_call_out("heal_em") != -1);
  }
  return ::exit(ob);
}


int south() {
  if ((string)this_player()->query_guild_name() == "doppleganger") {
    if (this_player()->query_guild_rank() < 10) {
      write("You are not a Doppleganger guild commander.\n");
      return 1;
    }
    this_player()->move_player("into hiding#/players/guilds/dopplegangers/room/gc_room");
    return 1;
  }
  return 0;
}

int list() {
  call_other("/players/guilds/dopplegangers/room/gc_room", "XXX");
  call_other("/players/guilds/dopplegangers/room/gc_room", "list");
  return 1;
}
