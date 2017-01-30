inherit "room/room";

reset(arg){

if(arg) return;

  set_light(1);
  short_desc="Village road";

  long_desc=
    " \n" +
    "The lane leads to a small village.\n";

dest_dir=({
 "/players/morgoth/CASTLE/blue_pub.c","west",
 "/players/morgoth/CASTLE/shop.c","east",
 "/players/morgoth/CASTLE/prize_room.c","south",
 "/players/morgoth/CASTLE/forest_3.c","north" });
}

