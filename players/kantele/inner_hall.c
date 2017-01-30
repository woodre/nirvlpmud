#pragma strong_types

inherit "room/room";

int prize;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("The inner hall");
  set_long(
"You are in the inner hall, the walls are lined with shields\n" +
"It looks like the shields are loot from some sort of campaign.\n");
  dest_dir = ({
    "players/kantele/stairway", "south",
    "players/kantele/hall", "north",
    "players/kantele/dining_room", "west",
    "players/kantele/living_room", "east"
  });
  items = ({
    "shields", "It looks like you could pry them off the wall"
  });
}

void
populate() {
  object james;
  if (!present("james", this_object())) {
    james = clone_object("obj/monster");
    james->set_name("james");
    james->set_alias("butler");
    james->set_short("James the butler is here");
    james->set_al(12);
    james->set_level(12);
    james->set_wc(16);
    james->set_ac(9);
    james->set_hp(180);
    james->add_money(550);
    move_object(james, this_object());
  }
  prize = 0;
}

void
init() {
  ::init();
  add_action("get_shield", "pry");
  add_action("exit_check", "south");
  add_action("exit_check", "east");
  add_action("exit_check", "west");
}

status
exit_check() {
  if (present("james", this_object())) {
    write("James bars your way !\n");
    write("James says: Can you please leave, Sir !\n");
    return 1;
  }
  return 0;
}

status
get_shield(string str) {
  object shield;
  if (!str)
    return 0;
  if (str != "shield" && str != "shield off wall" && str != "of shield") {
    /* Left in 'of shield' for historical */
    write("What do you want to pry?\n");
    return 1;
  }    
  if (!present("shield", this_player()) && prize < 5) {
    prize = prize +1;
    write("You pry off a shield.\n");
    shield = clone_object("obj/armor");
    shield->set_ac(1);
    shield->set_name("shield");
    shield->set_alias("small shield");
    shield->set_value(70);
    shield->set_short("A small metal shield");
    shield->set_weight(4);
    shield->set_type("shield");
    move_object(shield, this_object());
    return 1;
  } else {
    write("The shields are fastened too hard.\n");
    return 1;
  }
}
