inherit "players/mizan/closed/RandomRoom.c";
#include "/players/bastion/closed/color.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
}

init() {
  ::init();
  add_action("up_and_out","up");
}

short() { return "Plane of Etheriel [many exits]"; }

long() {
  int i;
  string lngfrm;
  write("\n" + BOLD + BLUE +
"\tPow! Boom! Smack! You violently collide into a huge ball of matter\n"+
"  which covers you with a thick layer of what appears to puffy\n"+
"  dryer lint. You begin to sneeze uncontrollably, developing some\n"+
"  kind of allergic reaction. Fortunately, a passing Oofa drifts\n"+
"  through you, 'cleansing' you of the fuzzy gunk.\n" + OFF);
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

up_and_out() {
  this_player()->move_player("up#room/wild1");
  return 1;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/boofer.c",
    "players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/environs/peeker-pipe.c",
    "players/mizan/etheriel/environs/grey-button.c",
  });
  ::extra_reset();
}
