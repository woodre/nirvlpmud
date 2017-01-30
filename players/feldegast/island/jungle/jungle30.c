inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/false_ruins","north",
    "/players/feldegast/island/jungle/jungle29","west"
  });
}

