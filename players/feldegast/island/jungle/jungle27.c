inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle24","north",
    "/players/feldegast/island/jungle/jungle26","west",
    "/players/feldegast/island/jungle/false_ruins","east",
    "/players/feldegast/island/jungle/jungle29","south"
  });
}

