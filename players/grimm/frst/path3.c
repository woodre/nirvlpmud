inherit "room/room";
reset(arg) {
   if(arg)
      return;
short_desc="A Dark Pathway";
long_desc="This is a very dark pathway.  The surrounding area is completely\n"+
"blackened and is covered by large thorn bushes.  The noted directions are\n"+
"the only possible exits from this area.  There seems to be a\n"+
"town of some sort.\n";
dest_dir=({"players/grimm/frst/path4","north",
           "players/grimm/frst/path2","northeast",
           });
set_light(0);
}

init() {
  add_action("north","north");
  add_action("north","n",1);
  add_action("ne","northeast");
  add_action("ne","ne");
}
north() {
  this_player()->move_player("north#/players/grimm/frst/path4");
  return 1;
}
ne() {
  this_player()->move_player("northeast#/players/grimm/frst/path2");
  return 1;
}
