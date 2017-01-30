inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "A warm passage";
   long_desc=
"Walking down this long passage around the castle, you begin to feel the"+
" air\nget warmer, then hot.  The bricks in the wall seem to radiate heat"+
" like an\noven.  Further west the passage opens into a room, and east leads"+
" to the entrance to the castle.\n";

dest_dir = ({
   "players/blue/castle/entry1","east",
   "players/blue/fire/level1","west"
   });
}
}
