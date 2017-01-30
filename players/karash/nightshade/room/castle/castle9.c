inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
set_light(1);
   short_desc = "Castle wall";
   long_desc = 
"The northern tower is closer now. You can see a guard up ahead.\n"+
"He is checking out the area by orders of the king.\n";
   dest_dir = 
({
"players/nightshade/room/castle/castle10", "north",
"players/nightshade/room/castle/castle8", "south",
});
}
