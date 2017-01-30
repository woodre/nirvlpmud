inherit "players/nightshade/new_room";

reset(arg) {
   set_light(1);
   if(arg) return;
   short_desc = "Castle wall";
   long_desc = 
"The southern tower is behind you now as you make your way north\n"+
"towards the northern tower. The land on the other side of the wall\n"+
"is plush and green. A small lake lies rather close to the wall\n"+
"surrounded by trees.\n";
   dest_dir = 
({
"players/nightshade/room/castle/castle9", "north",
"players/nightshade/room/castle/castle7", "south",
});
}
