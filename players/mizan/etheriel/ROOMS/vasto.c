string death_exits;
inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  death_exits=({
   "nowhere", "out", "lose", "faced", "dished", "screwed",
   "leave", "goner", "somewhere", "true", "deadnuts", "grave"
  });
  set_light(1);
}

short() { return "Plane of Etheriel [many, many exits]"; }

long() {
  int i;
  string lngfrm;
  write("\n"+
"\tDefiance of laws has historically landed mankind in trouble. Hmm.\n"+
"  What if man were to break free of those constraints and emerge in a\n"+
"  brave new world forged and based on pure anarchy and entropy? Okay,\n"+
"  enough of the philosophy and try to figure out what to do when you get\n"+
"  tossed into a room with near-infinite exits, and no apparent order\n"+
"  in sight...\n\n");
  lngfrm = "There are many, many obvious exits: nowhere, out, up, lose, faced, dished, screwed, leave, goner, somewhere, true, deadnuts, grave,";
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

init() {
  int i;
  ::init();
  add_action("up","up");
  if (!death_exits) {
    write("Something has gone wrong with the room. Please contact Mizan!\n");
  }
  i = 0;
  while(i < sizeof(death_exits)) {
    add_action("death_move", death_exits[i]);
    i += 1;
  }
}

up() {
  write("You bubble up to the surface.\n");
  this_player()->move_player("up#room/wild1");
  return 1;
}

death_move(str) {
  write("Zap! Ouch! Pow!\n\nYou feel like you die.\nYou feel like you had your hitpoints\n"+
	"restored to 1/3 normal. BUT everything is _okay_.\n\n");
  this_player()->move_player("X#players/mizan/etheriel/ROOMS/fake_dead");
  return 1;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/bjork-graphic.c",
         "players/mizan/etheriel/beasties/cactus.c",
    "players/mizan/etheriel/beasties/mr-lemonguy.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
