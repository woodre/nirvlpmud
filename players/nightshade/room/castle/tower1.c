inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In tower";
   long_desc =
"This is just another room reserved for more archers. Two stand\n"+
"here, ready as well, for the worst.\n";
   dest_dir =
({
"players/nightshade/room/castle/castle6", "down",
});
}
