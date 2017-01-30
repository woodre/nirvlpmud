inherit "room/room";

reset(arg){

if(arg) return;

  set_light(1);
  short_desc="Forest path";

  long_desc=
    " \n" +
    "The path widens into a narrow lane.\n" +
    "A few small buildings appear in the south\n" +
    "To the east a shimmering dimension portal appears amidst the trees..\n";

dest_dir=({
 "/players/morgoth/CASTLE/forest_2","north",
 "/players/morgoth/CASTLE/vil_road_1","south",
 "/players/morgoth/CASTLE/pen_lane1","west",
 "/players/morgoth/CASTLE/platform","east" });
}

