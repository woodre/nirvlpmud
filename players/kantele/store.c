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
  set_short("store room");
  set_long(
"Kitiaras store room..\n");
  dest_dir = ({
    "players/kantele/workroom", "north"
  });
}

void
populate() {
  object money;
  if (!present("money", this_object())) {
    money = clone_object("obj/money");
    money->set_money(1);
    move_object(money, this_object());
  }
}
