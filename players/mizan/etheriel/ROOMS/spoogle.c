inherit "players/mizan/closed/RandomRoom.c";
#include "/players/bastion/closed/color.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  call_other("/players/mizan/etheriel/ROOMS/nuck.c","???");
  call_other("/players/mizan/closed/borg-cube.c", "???");
  if(!present("newbie_block", this_object()))
    move_object(clone_object("/players/vertebraker/obj/newbie_block"), this_object());
  set_light(1);
}

short() { return "Plane of Etheriel [many exits]"; }

init() {
  if(this_player()->query_level() < 3) {
    write("NEW PLAYERS: Type 'info' for some information on monsters...\n");
  }
  if(this_player()->query_level() > 19) {
    write("WIZARDS: Type 'credits' for the standard disclaimer credits list.\n");
  }
  add_action("wizinfo","credits");
  add_action("helpinfo","info");
  ::init();
}

wizinfo() {
  cat("/players/mizan/etheriel/CREDITS");
  return 1;
}

helpinfo() {
  if(this_player()->query_level() > 5) return 0;
  cat("/players/mizan/etheriel/NEWBIEINFO");
  return 1;
}
long() {
  int i;
  string lngfrm;
  write("\n" + BLUE +
"    You 'stand' (I do use that term loosely) in what seems to be an entrance\n"+
"  room, that breaks all laws of natural physics (and all that stuff) as you\n"+
"  know it. There is a VERY important sign for you read here, before you \n"+
"  proceed any further. It feels like you are in a dream, with no real form,\n"+
"  and there are swirling masses of colors and such as far as you can see...\n" + OFF);
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
    "players/mizan/etheriel/bullboard.c",
    "players/mizan/etheriel/enter_sign.c",
    "players/mizan/etheriel/environs/beatfixer-machine.c",
    "players/mizan/etheriel/beasties/happy-fridge.c",
/*
    "players/mizan/etheriel/environs/peeker-pipe.c",
    "players/mizan/n/rock",
 */
    "players/mizan/etheriel/environs/grey-button.c",
    "players/mizan/etheriel/dev.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
