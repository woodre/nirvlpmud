#pragma strong_type

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("Bottom of stairway");
  set_long(
"You are at the bottom of the stairway,  the stairway goes up\n" +
"and you can go further into the cellar to the west.\n");
  dest_dir = ({
    "players/kantele/stairway", "up",
    "players/kantele/cellar_west", "west",
    "players/kantele/cellar_east", "east"
  });
}

void
populate() {
  object haunt;
  if (!present("haunt", this_object())) {
    haunt = clone_object("obj/monster");
    haunt->set_name("haunt");
    haunt->set_level(12);
    haunt->set_wc(16);
    haunt->set_ac(9);
    haunt->set_hp(180);
    haunt->add_money(550);
    haunt->set_chance(20);
    haunt->set_spell_dam(40);
    haunt->set_spell_mess1("The haunt utters a wailing scream.");
    haunt->set_spell_mess2("The scream hurts you bad.");
    move_object(haunt, this_object());
  }
}

void
init() {
  ::init();
  add_action("exit_check", "east");
  add_action("exit_check", "west");
}

status
exit_check() {
  if (present("haunt", this_object())) {
    write("The haunt is in the way  !\n");
    return 1;
  }
  return 0;
}
