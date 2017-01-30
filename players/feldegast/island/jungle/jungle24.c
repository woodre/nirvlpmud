inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle10","north",
    "/players/feldegast/island/jungle/jungle23","west",
    "/players/feldegast/island/jungle/jungle25","east",
    "/players/feldegast/island/jungle/jungle27","south"
  });
}

