/*
 guild_equip.c
*/

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

object dagger, tuxedo, this_guy;
int set_max;
string str;

init() {
  ::init();

  add_action("equip_me",    "equip");
  add_action("make_mirror", "make");
  check_membership(this_player());
}

equip_me(str) {
  if (!present("nooneelse@vampire@fangs", this_player()) &&
      !this_player()->am_i_a_servant()) {
    check_membership(this_player());
    return 1;
  }
  if (this_player()->am_i_a_servant()) return;
  if (!str) return;
  if (str != "me") return;
  if (this_player()->query_spell_point() < 40) {
    write("You don't have enough spell points. You need 40 sp.\n");
    return 1;
  }

  if (present("guild dagger", this_player()))
    write("You already have a dagger.\n");
  else {
    if (this_player()->query_level() < 11 ||
        this_player()->query_level() > 20) {
      dagger=clone_object("players/nooneelse/black/guild_dagger");
      set_max=this_player()->query_level() + 1;
      dagger->set_class(set_max);
      if (this_player()->query_level() > 20) dagger->set_class(20);
      move_object(dagger, this_player());
      write("Ok.  Here's a dagger.  It's not great, it's just free.\n");
      say("The supply golem gives "+this_player()->query_name()+
          " a dark black dagger.\n");
    }
  }
  if (present("guild tuxedo", this_player()))
    write("You already have a tuxedo.\n");
  else {
    if (this_player()->query_level() < 13 ||
        this_player()->query_level() > 20) {
      tuxedo=clone_object("players/nooneelse/black/guild_tuxedo");
      set_max=(this_player()->query_level()) / 3;
      if (set_max > 4) set_max=4;
      if (set_max < 1) set_max=1;
      tuxedo->set_ac(set_max);
      move_object(tuxedo, this_player());
      write("Ok.  Here's a tuxedo.\n");
      say("The supply golem gives "+this_player()->query_name()+
          " a black tuxedo.\n");
    }
  }
  if (present("guild bag", this_player()))
    write("You already have a bag.\n");
  else {
     move_object(clone_object("players/eurale/Vamp/OBJ/guild_bag.c"),
                this_player());
    write("Ok.  Here's a bag.\n"); say("The supply golem gives "+
          this_player()->query_name()+ " a black bag.\n");
  }
  if (present("blood bottle", this_player()))
    write("You already have a blood bottle.\n");
  else {
    move_object(clone_object("players/nooneelse/black/guild_blood_bottle"),
                this_player());
    write("Ok.  Here's a blood bottle.\n"); say("The supply golem gives "+
          this_player()->query_name()+ " a blood bottle.\n");
  }

  this_player()->add_spell_point(- 40);
  write("You feel a little weaker.\n");
  return 1;
}

make_mirror(str) {
  if (present("magic mirror")) return;
  move_object(clone_object("players/eurale/Vamp/OBJ/magic_mirror.c"),
              this_object());
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc="the Vampire Guild's Equipment Supply Room";
  no_castle_flag=1;
  long_desc=
    "This is a well stocked equipment supply room.  It's shelves and bins\n"+
    "are full of weapons, armor and miscellaneous equipment.\n"+
    "You can get a free dagger, tuxedo or bag by saying 'equip me'.\n"+
    "You cannot sell or give these items away or drop them.\n"+
    "\n(If the magic mirror isn't here, type 'make mirror'. :)\n";
  items =
    ({
      "shelf", "It is full of daggers, tuxedos and bags.",
      "shelves", "They are full of daggers, tuxedos and bags.",
      "bin", "It is full of daggers, tuxedos and bags.",
      "bins", "They are full of daggers, tuxedos and bags.",
      "dagger", "It is a sharp dagger made of a black metal.",
      "daggers", "They are sharp daggers made of a black metal.",
      "tuxedo", "A black tuxedo.",
      "tuxedos", "They are black tuxedos of several sizes.",
      "bag", "A black bag.",
      "bags", "They are black bags.",
      "weapons", "They are sharp daggers made of a black metal.",
      "armor", "They are black tuxedos of several sizes.",
      "equipment", "They are black black bags.",
    });

  dest_dir=
    ({
      "players/nooneelse/black/guild_lower_hall", "east",
  "players/eurale/Vamp/RMS/wing_room.c","north",
  "players/eurale/Vamp/RMS/shop.c","south",
    });
  move_object(clone_object("players/eurale/Vamp/OBJ/magic_mirror.c"),
              this_object());
}

realm() { return "NT"; }
