#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("standing in the pool");
  set_long(
"You are standing in the pool, probably scaring the fishes to\n" +
"death, besides your feet are geting wet......\n");
  dest_dir = ({
    "players/kantele/garden_east", "exit"
  });
}
