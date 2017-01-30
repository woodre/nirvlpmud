inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/snake_pit","north",
    "/players/feldegast/island/jungle/jungle10","west",
    "/players/feldegast/island/jungle/jungle12","east",
    "/players/feldegast/island/jungle/jungle25","south"
  });
}
