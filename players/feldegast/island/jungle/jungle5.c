inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle2","north",
    "/players/feldegast/island/jungle/jungle1","west",
    "/players/feldegast/island/jungle/jungle6","east",
    "/players/feldegast/island/jungle/jungle8","south"
  });
}

