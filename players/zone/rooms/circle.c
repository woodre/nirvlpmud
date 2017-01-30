inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A small depression.";
  long_desc = 
   "A dip in the land almost in a perfect circle.  There are flowers throughout\n"+
   "which are fragrant.  The peacefulness makes you wish to nap.\n";
  property = ({"nf"});
  dest_dir = ({"players/zone/rooms/tree.c", "north",
               "players/zone/rooms/guardian.c", "south",
/* The crappiness of these sub-areas offends me. -Feldegast 10-14-00
               "players/zone/rooms/europe.c", "europe",
               "players/zone/rooms/mountain.c", "asia"
*/
          });
  }
}
