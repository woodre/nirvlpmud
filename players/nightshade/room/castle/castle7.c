inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc =
"The southeastern tower lies behind you now and up ahead you can\n"+
"see the northeastern tower. A couple of guards walk along the\n"+
"wall making sure everything is ok.\n";
   dest_dir =
({
"players/nightshade/room/castle/castle8", "north",
"players/nightshade/room/castle/castle6", "south",
});
}
