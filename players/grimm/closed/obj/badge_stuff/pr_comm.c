inherit "room/room";

object ob;
int count;

void reset(int arg) {
  if (arg)
    return;
  count = 0;
  set_light(1);
/*
  if (!present("tester"))
    move_object(clone_object("/players/grimm/closed/obj/badge_stuff/beta"),
                this_object());
*/
  if (!present("poker machine"))
    move_object(clone_object("/players/grimm/closed/obj/poker"),
                this_object());
/*
  if (!present("fountain"))
    move_object(clone_object("/player/grimm/q/o/fountain"),
                this_object());
*/
  if (!present("box"))
    move_object(clone_object("/players/grimm/closed/obj/badge_stuff/vbox"),
                this_object());
  if (!present("cboard"))
    move_object(clone_object("/players/grimm/closed/obj/badge_stuff/board2"),
                this_object());
  short_desc = "Commander's Hideout";
  long_desc = "This is a hideout for Doppleganger's Guild Commanders only.\n";
  dest_dir = ({
           "/players/grimm/guild","east",
           "/players/grimm/closed/obj/badge_stuff/guild_pr", "north",
           "/room/church","church",
           "/room/shop","shop",
           "/players/grimm/guild","guild",
           "/room/adv_guild","adventures",
           "/room/pub2","pub",
  });
}

void init() {
  ::init();
  if ((!present("badge", this_player()) &&
       !this_player()->query_npc() &&
       (string)this_player()->query_real_name() != "rumplemintz" )
     || environment(this_player())->id("cloud")) {
    write("YOU ARE NOT A DOPPLEGANGER!\n");
    write("Only the chosen will be allowed to enter this room!\n");
    say(this_player()->query_name() + " tried to enter the room but gets " +
        "kicked out!\n");
    move_object(this_player(), "/players/grimm/guild");
    write("Join our guild before entering the guild's party room.\n");
    return;
  }
  if ((this_player()->query_guild_rank() < 20 &&
       !this_player()->query_npc() &&
       (string)this_player()->query_real_name() != "rumplemintz" )
     || environment(this_player())->id("cloud") ) {
    write("You are not a guild commander.\n");
    move_object(this_player(),"/players/grimm/closed/obj/badge_stuff/guild_pr");
    return;
  }
  add_action("list","list");
}

int list() {
  write("Current guild commanders/leaders are:\n");
  write("   Guild Master:      Grimm\n");
  write("   Guild XO:          Rumplemintz\n");
  write("   Guild Wizzies:     None\n");
  write("   Guild Senior:      Rump\n");
  write("   Guild Commanders:  None\n");
  return 1;
}
