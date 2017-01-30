inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle14","west",
    "/players/feldegast/island/jungle/jungle16","east",
    "/players/feldegast/island/jungle/jungle18","south"
  });
}

