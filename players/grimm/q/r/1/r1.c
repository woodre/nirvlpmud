inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="Entrance to Omar's Shop";
  long_desc="This is the entrance to Omar's Novelty Shop!\n"+
            "Omar is a mean little fellow that, if given the chance, will "+
            "rob you blind.\nHowever, he usually DOES have at least a FEW "+
            "good items for sale that should be\nsomewhat worth your while.\n";
  dest_dir=({
      "/players/grimm/q/r/1/r2", "east",
      "/players/grimm/q/r/1/r8", "south",
      });
}
