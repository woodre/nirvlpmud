inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle27","north",
    "/players/feldegast/island/jungle/jungle28","west",
    "/players/feldegast/island/jungle/jungle30","east",
  });
}

