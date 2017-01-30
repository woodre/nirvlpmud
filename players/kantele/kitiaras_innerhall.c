#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("You are in a small hall");
  set_long(
"You are in a small hall, you can smell some sulphur to the\n"+
"east.\n");
  dest_dir = ({
    "players/kantele/kitiaras_crossing", "north",
    "players/kantele/kitiaras_lab", "east",
    "players/kantele/kitiaras_slepingroom", "west",
    "players/kantele/kitiaras_livingroom", "south"
  });
}

void
populate() {
  object beast;
  if (!present("beast", this_object())) {
    beast = clone_object("obj/monster");
    beast->set_name("displacer beast");
    beast->set_level(10);
    beast->set_wc(14);
    beast->set_ac(8);
    beast->set_hp(150);
    beast->set_short("Kitiaras pet displacer beast is here");
    beast->set_aggressive(1);
    beast->set_alias("beast");
    beast->add_money(450);
    move_object(beast, this_object());
  }
}

