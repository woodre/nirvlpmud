inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle15","west",
    "/players/feldegast/island/jungle/jungle19","south"
  });
}

