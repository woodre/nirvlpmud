#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("A tasteful living room");
  set_long(
"A tasteful living room, an exit leads west into the hall, you\n"+
"can also leave south into the bar.\n");
  dest_dir = ({
    "players/kantele/inner_hall", "west",
    "players/kantele/bar", "south"
  });
}

void
populate() {
  object demon;
  if (!present("demon", this_object())) {
    demon = clone_object("obj/monster");
    demon->set_level(15);
    demon->set_name("demon");
    demon->set_short("A household demon is here");
    demon->set_wc(20);
    demon->set_ac(12);
    demon->set_hp(250);
    demon->add_money(1000);
    demon->set_aggressive(1);
    demon->set_move_at_reset();
    move_object(demon, this_object());
  }
}
