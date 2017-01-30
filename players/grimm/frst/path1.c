inherit "room/room";
reset(arg) {
   if(arg)
      return;
short_desc="A Dark Pathway";
long_desc="This is a very dark pathway.  The surrounding area is completely\n"+
"blackened and is covered by large thorn bushes.  The noted directions are\n"+
"the only possible exits from this area.  There seems to be a\n"+
"town of some sort.\n";
dest_dir=({"players/grimm/street1","east",
           "players/grimm/frst/path2","north",
           });
set_light(0);
}
