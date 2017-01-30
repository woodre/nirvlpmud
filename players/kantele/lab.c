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
  set_short("Kanteles laboratory");
  set_long(
"You are in Kanteles laboratory, you can go south into her work \n" +
"her workroom, or you can eneter the hall to the east. The room \n" +
"Is covered with strange devices, an odd smell penetrates the air.\n");
  dest_dir = ({
    "players/kantele/upper_hall", "east",
    "players/kantele/office2", "south"
  });
}

void
populate() {
  if (!present("scroll", this_object()))
    move_object(clone_object("players/kantele/scroll"), this_object());
}
