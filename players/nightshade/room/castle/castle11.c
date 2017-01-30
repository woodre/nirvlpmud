inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc = 
"This tower like the others is damp and dim. Several royal archers\n"+
"wait here ready rain hell down on any enemys attacking from the\n"+
"north or east.\n"+
"There are stairs leading up to the top portion of the tower.\n";
dest_dir =
({
"players/nightshade/room/castle/castle10", "south",
"players/nightshade/room/castle/castle12", "west",
"players/nightshade/room/castle/tower2", "up",
});
}
