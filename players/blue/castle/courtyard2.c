inherit "room/room";

reset(arg) {

if(!arg) {
   set_light(1);
   short_desc = "A courtyard";
   long_desc =
"This is the north end of the courtyard.  Straight ahead a crumbled wooden\n"+
"gate lies on the ground exposing a passage into the inner castle.  You a"+
"lso\nnotice fresh footprints on the ground.  Some of them are not human.\n";
   dest_dir = ({
   "players/blue/castle/stable","north",
   "players/blue/castle/courtyard","south",
   "players/blue/castle/courtne","east",
   "players/blue/castle/courtnw","west"
   });
}
}
