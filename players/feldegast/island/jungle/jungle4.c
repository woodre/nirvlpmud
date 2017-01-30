inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle3","west",
    "/players/feldegast/island/jungle/jungle13","east",
    "/players/feldegast/island/jungle/jungle7","south"
  });
}

