inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle3","north",
    "/players/feldegast/island/jungle/jungle5","west",
    "/players/feldegast/island/jungle/jungle7","east"
  });
}

