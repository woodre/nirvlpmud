inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Top of a long winding staircase";
  long_desc = 
   "This is the landing of a long winding staircase leading to the base of the\n"+
   "sequioya tree.  The banister is made with care, and as you look about,\n"+
   "you notice that rope and wood walkways span between the larger specimens\n"+
   "of the tree.\n";
  dest_dir = ({"players/zone/rooms/town1.c", "north",
               "players/zone/rooms/town3.c", "northwest",
               "players/zone/rooms/base.c", "down"});
  }
}
