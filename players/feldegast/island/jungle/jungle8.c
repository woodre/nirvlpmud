inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle5","north",
    "/players/feldegast/island/jungle/jungle10","south"
  });
}

