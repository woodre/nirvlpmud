inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Valley";
       long_desc="The walls of the valley loom above you.  The dried creek bed\n"+
   "strectches before you, winding deeper into this ravine.  The grass\n"+
   "here is all dry and shrivled, and even seems to be burnt in some\n"+
   "places.  A trail leading out of this valley lies to your west.\n";

dest_dir=({ "players/pavlik/trail/room2.c", "west",
              "players/pavlik/trail/valley1.c", "east",
});

   }
}
