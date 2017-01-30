/*
 cellar1.c
*/

inherit "room/room";

object earwig, chitin;

init() {
  ::init();

  add_action("open",       "open");
  add_action("go_up",      "up");
  add_action("close_door", "close");
  add_action("sniff",      "sniff");
}

open(str) {
  if (!str || str != "door") return;
  go_up(str);
  return 1;
}

go_up(str) {
  call_other("players/nooneelse/red/pantry", "???", 0);
  if (find_object("players/nooneelse/red/pantry")->query_door()) {
    write("You walk up the stairs and through the door.\n\n");
    say(this_player()->query_name()+
        " goes up the stairs and through the door.\n");
    tell_room("players/nooneelse/red/pantry",this_player()->query_name()+
              " comes up the stairs and through the door.\n");
  }
  else {
    write(
      "The door opens for a second, then slams shut.  Good thing you were\n"+
      "fast enough to make it through!\n\n");
    say(this_player()->query_name()+
        " goes up the stairs and through the door,\n"+
        "which then slams shut.\n");
    tell_room("players/nooneelse/red/pantry",
              "A door in the shelves opens long enough for "+
              this_player()->query_name()+" to slip through, then closes.\n");
  }
  move_object(this_player(), "players/nooneelse/red/pantry");
  command("look", this_player());
  return 1;
}

close_door(str) {
  if (!str || str != "door") return;
  call_other("players/nooneelse/red/pantry", "???", 0);
  if (find_object("players/nooneelse/red/pantry")->query_door())
    write("You can't close the door.  It's stuck.\n");
  else
    write("Huh?  The door isn't open.\n");
  return 1;
}

sniff() {
  write("As you sniff, the dust tickles your nose.\n");
  command("sneeze", this_player());
  return 1;
}

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  no_castle_flag=1;
  short_desc = "cellar hall";
  long_desc =
    "This hallway is choked with dust and cobwebs.  The air is so musty\n"+
    "that you have problems breathing.  There are wooden stairs leading\n"+
    "up from here to a stone door.\n";
  items =
    ({
      "stairs", "The wood looks worn and dry, but they look sturdy.",
      "door", "It is a heavy stone door.",
      "dust", "It's very fine powdery dust.",
      "cobwebs", "The webs are fresh!  Is there a spider around here?\n",
      "webs", "The webs are fresh!  Is there a spider around here?\n",
    });
  dest_dir =
    ({
      "players/nooneelse/red/pantry", "up",
      "players/nooneelse/red/cellar10", "east",
      "players/nooneelse/red/cellar2", "west",
    });
  if (!find_living("nooneelseearwig")) {
    earwig=clone_object("obj/monster");
    earwig->set_name("earwig");
    earwig->set_alt_name("nooneelseearwig");
    earwig->set_level(17);
    earwig->set_hp(190);
    earwig->set_wc(15);
    earwig->set_ac(4);
    earwig->set_ep(100000);
    earwig->set_al(0);
    earwig->set_short("an earwig");
    earwig->set_long("It's an ugly, hungry, giant earwig.\n");
    earwig->set_whimpy(1);
    earwig->set_aggressive(1);
    chitin=clone_object("obj/armor");
    chitin->set_name("chitin");
    chitin->set_short("chitin armor");
    chitin->set_long("Armor pieced together from an insect's chitin.\n");
    chitin->set_value(220);
    chitin->set_weight(3);
    chitin->set_ac(3);
    chitin->set_type("armor");
    move_object(chitin, earwig);
    move_object(earwig, this_object());
  }
}
