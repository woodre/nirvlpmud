#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A dirty sleeping room");
  set_long(
"A dirty sleeping room, a single dirty bed stands in one corner.\n");
  dest_dir = ({
    "players/kantele/mechanic_room", "west"
  });
  items = ({
    "bed", "the bed is dirty and smelling, and you should be ashamed \n" +
           "to mess around in it"
  });
}
