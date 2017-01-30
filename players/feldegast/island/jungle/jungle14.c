inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle13","west",
    "/players/feldegast/island/jungle/jungle15","east",
    "/players/feldegast/island/jungle/jungle17","south"
  });
}

