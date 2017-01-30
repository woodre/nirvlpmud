inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc = 
   "From up here on the castle wall you can see for miles around the country\n"+
   "side. Down below you is a small village built up around the castle.\n"+
   "and further to the north is the castle itself. Guard towers rise\n"+
   "even higher than the wall itself to the east and west.\n";
  dest_dir = ({
   "/players/nightshade/room/castle/castle1", "down",
   "/players/nightshade/room/castle/castle3", "east",
   "/players/nightshade/room/castle/castle27", "west",
   });
}
