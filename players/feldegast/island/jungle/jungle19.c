inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle16","north",
    "/players/feldegast/island/jungle/jungle18","west",
    "/players/feldegast/island/path/path1","east",
    "/players/feldegast/island/jungle/jungle22","south"
  });
}

