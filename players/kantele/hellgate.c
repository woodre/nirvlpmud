#pragma strong_types

inherit "room/room";

int gate_is_open;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("Hellgate");
  set_long(
"You are at hellgate, the gate stands black and sinister to the north.\n"+
"This is the place where gods expel people they don't want on earth.\n");
  dest_dir = ({
    "players/kantele/hellgate_anteroom", "south"
  });
  items = ({
    "gate", "The gate looks completely dead"
  });
  gate_is_open = 0;
}

void init() {
  ::init();
  add_action("enter", "enter");
  add_action("open_gate", "open");
  add_action("close_gate", "close");
}

void populate() {
  object gatekeeper,robe;

  if (!gatekeeper && !present("gatekeeper")) {
    gatekeeper = clone_object("obj/monster");
    gatekeeper->set_name("gatekeeper");
    gatekeeper->set_level(17);
    gatekeeper->set_short("The grayrobed Gatekeeper is here");
    gatekeeper->set_long("He looks VERY tough");
    gatekeeper->set_wc(35); /* bonus 11 WC, decreased 7 AC */
    gatekeeper->set_ac(7);
    gatekeeper->set_hp(350 + random(100));
    move_object(gatekeeper, this_object());
    robe = clone_object("obj/armor");
    robe->set_name("robe");
    robe->set_short("A grey robe");
    robe->set_value(1000);
    robe->set_weight(2);
    robe->set_type("robe");
    robe->set_ac(1);
    move_object(robe, gatekeeper);
  }
}

status enter(string str) {
  if (!str || str != "gate")
    return 0;
  if (gate_is_open) {
    write("You get a tingling feeling as you enter the gate.\n");
    this_player()->move_player("into hell#players/kantele/hell1");
    return 1;
  }
  write("The gate is closed.\n");
  return 1;
}

status open_gate(string str) {
  if (!str || str !="gate")
    return 0;
  if (this_player()->query_level() > 20) {
    if (gate_is_open) {
      write("The gate is already open.\n");
      return 1;
    }
    write("You open the gate.\n");
    say(this_player()->query_name()+" opens the gate.\n");
    gate_is_open = 1;
    remove_item("gate");
    add_item("gate", "The gate is shimmering black sinister");
    add_exit("players/kantele/hell1", "enter");
    return 1;
  }
  write("The power to open the gate doesn't belong to you.\n");
  return 1;
}

status close_gate(string str) {
  if (!str || str !="gate")
    return 0;
  if (this_player()->query_level() > 20) {
    if (!gate_is_open) {
      write("The gate is already closed.\n");
      return 1;
    }
    write("You close the gate.\n");
    say(this_player()->query_name()+" closes the gate.\n");
    gate_is_open = 0;
    remove_item("gate");
    add_item("gate", "The gate looks completely dead");
    remove_exit("enter");
    return 1;
  }
  write("The power to close the gate doesn't belong to you.\n");
  return 1;
}
