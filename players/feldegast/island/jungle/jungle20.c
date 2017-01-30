inherit "players/feldegast/island/jungle/jungle13";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle17","north",
    "/players/feldegast/island/jungle/jungle21","east"
  });
}

