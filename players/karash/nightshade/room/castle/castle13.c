inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc = 
"The short figure you saw earlier is a dwarven guard. With his battle axe\n"+
"bouncing up and down on his shoulder, he looks ready to fight. You notice\n"+
"he keeps looking down into a small forest that comes almost up to\n"+
"castle wall.\n";
dest_dir =
({
"players/nightshade/room/castle/castle14", "west",
"players/nightshade/room/castle/castle12", "east",
});
}
