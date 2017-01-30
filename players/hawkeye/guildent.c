inherit "room/room";
   string WHAT, ME;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Sacred Woods";
long_desc="You walk on the sacred ground of the Monks Guild.\n"+
           "This area is a small wooded glade, covered with\n"+
           "small, perfect trees.  The trail continues to the\n"+
           "west, but only the choosen may follow it.\n"+
   "If you have lost your robes, type REGISTER here.\n";

dest_dir=({
/* Removed by Snow 3/00
  "/players/hawkeye/closed/guild/guild_room.c", "west",
   "/room/crop", "east",
*/
  "/room/farmroad2","west",
});

   }
}

/*
init() {
    ::init();
 move_object(this_player(), "players/hawkeye/closed/guild/join");
}
*/

