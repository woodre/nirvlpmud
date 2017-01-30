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
  set_short("A dusty store room");
  set_long(
"This is a small dusty store room, it looks like it has been\n" +
"a very long time since anyone used it.\n");
  dest_dir = ({
    "players/kantele/kitchen", "north"
  });
}

void
populate() {
  if (!present("spider", this_object()))
    move_object(clone_object("players/kantele/spider"), this_object());
}
