inherit "players/mizan/closed/RandomRoom.c";
#include "/players/bastion/closed/color.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
}

query_zokko() { return "MOOOOO!"; }

init() {
  ::init();
  add_action("up_and_out","up");
}

short() { return "Plane of Etheriel [many exits]"; }

up_and_out() {
  this_player()->move_player("up#room/wild1");
  return 1;
}
long() {
  int i;
  string lngfrm;
  write("\n" + BOLD + YELLOW +
  
"\tSomething... something is very bright in the area... and it is\n"+
"  starting to get on your nerves. Whatever it is, it pulsates with\n"+
"  an irregular, dopey beat. The thumping bass creeps into your head\n"+
"  and generally makes existence in this part of the ether-muck rather\n"+
"  unpleasant...\n" + OFF);
  lngfrm = "There are many obvious exits: up,";
  while(i < sizeof(dest_dir)) {
    lngfrm = lngfrm + " " + dest_dir[i];
    i += 1;
    if (i == sizeof(dest_dir) - 1)
      lngfrm = lngfrm + " and";
      else if (i < sizeof(dest_dir))
        lngfrm = lngfrm + ",";
    }
  lngfrm = lngfrm + ".";
  lngfrm = format(lngfrm, 70);
  write(lngfrm + "\n");
}

extra_reset() {
  object_names=({
/*
    "players/mizan/etheriel/heals/portable_cow.c",
    "players/mizan/etheriel/environs/troll.c",
 */
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/pogo",
    "obj/level_list"
  });
  ::extra_reset();
}
