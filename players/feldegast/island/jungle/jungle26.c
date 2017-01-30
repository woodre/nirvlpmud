inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle23","north",
    "/players/feldegast/island/jungle/jungle27","east",
    "/players/feldegast/island/jungle/jungle28","south"
  });
}

