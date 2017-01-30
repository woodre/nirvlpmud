inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "A passage";
   long_desc = 
"This is an intersection.  To the north BLUE'S shop, and to the west is the\n"+
"castle entrance/\n";

dest_dir = ({
   "players/blue/my_shop","north",
   "players/blue/castle/entry1","west"
   });

   }
}
