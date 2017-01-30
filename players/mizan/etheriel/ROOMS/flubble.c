#include "/players/bastion/closed/color.h"
inherit "players/mizan/closed/RandomRoom.c";

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
  write("\n" + BOLD + GREEN +
  
"\tCylindrical objects that resemble spent toilet paper rolls clutter\n"+
"  this part of the ether-muck. A strange, drubbing sound seems to be coming\n"+
"  from all directions. It resembles the sounds made by mating humpback whales\n"+
"  but you really are not too sure what mating humpback whales sound\n"+
"  like. There go your hormones again...\n" + OFF);
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

query_zokko() { return "SDFSDFSDFSDFsdf"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/environs/sofa.c",
    "players/mizan/etheriel/environs/grey-button.c",
  });
  if(1==random(5)) {
    move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
  ::extra_reset();
}
