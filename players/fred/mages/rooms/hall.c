inherit "room/room";
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The Hall of Members";
  long_desc = 
    "A luminous hallway glowing with a radiance inherent in its walls\n"+
    "leads to the Chambers of the Grand Adept and the Black Circle Inn.\n"+
    "The Grand Adept's room is to the north and the Restaurant is to \n"+
    "the south.\n";
  dest_dir = ({"/players/fred/mages/rooms/advance","east",
               "/players/fred/mages/rooms/inn", "south",
               "/players/fred/mages/rooms/stat", "north"});
  }
}
