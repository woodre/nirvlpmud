inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle4","north",
    "/players/feldegast/island/jungle/jungle6","west",
    "/players/feldegast/island/jungle/jungle9","south"
  });
}

