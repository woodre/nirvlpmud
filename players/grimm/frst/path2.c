inherit "room/room";
reset(arg) {
   if(arg)
      return;
short_desc="A Dark Pathway";
long_desc="This is a very dark pathway.  The surrounding area is completely\n"+
"blackened and is covered by large thorn bushes.  The noted directions are\n"+
"the only possible exits from this area.  There seems to be a\n"+
"town of some sort.\n";
dest_dir=({"players/grimm/frst/path3","southwest",
           "players/grimm/frst/path1","south",
           });
set_light(0);
}

init() {
  add_action("sw","southwest");
  add_action("sw","sw");
  add_action("south","south");
  add_action("south","s",1);
}
sw() {
 this_player()->move_player("southwest#/players/grimm/frst/path3");
 return 1;
}
south() {
  this_player()->move_player("south#/players/grimm/frst/path1");
  return 1;
}
