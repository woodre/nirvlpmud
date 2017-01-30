inherit "room/room";
reset(arg) {
if(arg)
   return;
short_desc="Old Musky Cavern";
long_desc="As you travel into the cavern you can feel a cool breeze.  You\n"+
          "can see the end of the cavern to the north and to\n"+
          "the south you notice some light.\n";
dest_dir=({"players/grimm/frst/forest42","north",
   "players/grimm/frst/forest40","south"});
set_light(1);
}
