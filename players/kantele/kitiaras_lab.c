#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A small lab");
  set_long(
"You are in a small well lit laboratory, lots of strange things\n"+
"can bee seen in this room, you fee lost in the affair of the\n"+
"imortals.\n");
  dest_dir = ({
    "players/kantele/kitiaras_innerhall", "west",
    "players/kantele/kitiaras_magesroom", "north"
  });
}
