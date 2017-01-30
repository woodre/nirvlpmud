inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
}

short() { return "Plane of Etheriel [many exits]"; }

long() {
  int i;
  string lngfrm;
  write("\n"+
"\tPokey and slightly delirious, you can see a small hole in the\n"+
"  'fabric' of the ether-muck here. Pulsating and constantly shifting\n"+
"  in size, what appears beyond it is very familiar territory, judging\n"+
"  from the quick glances you were offered every few seconds.\n\n");
  lngfrm = "There are many obvious exits: out,";
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
  ::init();
  add_action("up","up");
}

up() {
  this_player()->move_player("up#room/wild1");
  return 1;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/peeker-pipe.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/symidryl.c"
  });
  ::extra_reset();
}
