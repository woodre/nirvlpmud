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
  "\tThere appears to be an anomaly in the ether-muck here, from beyond\n"+
"  which you can see a familiar woodland environment. Since there is no\n"+
"  true 'up', assigning it as such is rather silly. But hey! It's somewhat\n"+
"  better than 'left', 'right', or 'eastwest' for that matter...\n\n");
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
    "players/mizan/etheriel/environs/bjork-graphic.c",
    "players/mizan/etheriel/beasties/mr-lemonguy.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
