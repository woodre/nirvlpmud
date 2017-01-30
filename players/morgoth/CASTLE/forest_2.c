inherit "room/room";

reset(arg){

if(arg) return;

  set_light(1);
  short_desc="Forest path";

  long_desc=
    " \n" +
    "A clearing in Morgoth's forest.\n" +
    "Ahead lies the entrance to Morgoth's castle.\n" +
    "In the distance four tower peaks are visible above\n" +
    "the damp, cold, stark castle walls.\n";

dest_dir=({
 "/players/morgoth/CASTLE/forest_1.c","west",
 "/players/morgoth/CASTLE/forest_3.c","south" });
}

