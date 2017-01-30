inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Sparsely forrested land";
  long_desc = 
   "This is a sparsely forrested land, to the west are great plains, stretching as far as the eye can see.  To the east is a large temperate forest.\n"+
   "\n";
  dest_dir = ({"/players/zone/rooms/america/plains.c", "w",
               "/players/zone/rooms/america/forest.c", "e"});
  }
}
