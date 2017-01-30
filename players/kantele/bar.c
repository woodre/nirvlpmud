#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A small private barroom");
  set_long(
"You are in a small private bar, you can exit west behind the bar\n" +
"or you can enter the trophy room to the south, to the north you\n" +
"can see into the living room.\n");
  dest_dir = ({
    "players/kantele/living_room", "north",
    "players/kantele/trophy_room", "south",
    "players/kantele/behind_bar", "west"
  });
}
