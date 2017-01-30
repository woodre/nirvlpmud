inherit "players/illarion/junk/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  set_short("A generic room");
  set_long("Nothing to see here.\n");
  add_exit("west","/players/illarion/junk/hroom1");
  add_exit("south","/players/illarion/junk/hroom4");
}
