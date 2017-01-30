inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc =
"The tower is right next to you. Another step and youll be in it.\n"+
"A rather thin looking guard stands in front of the tower, looking\n"+
"out over the King's land. Making sure nothing is awry.\n";
   dest_dir =
({
"players/nightshade/room/castle/castle4", "west",
"players/nightshade/room/castle/castle6", "east",
});
}
