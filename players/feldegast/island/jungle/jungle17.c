inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle14","north",
    "/players/feldegast/island/jungle/jungle18","east",
    "/players/feldegast/island/jungle/jungle20","south"
  });
}

