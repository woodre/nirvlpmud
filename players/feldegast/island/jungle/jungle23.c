inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle24","east",
    "/players/feldegast/island/jungle/jungle26","south"
  });
}

