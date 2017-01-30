inherit "room/room";
 
reset(arg) {
   object seller;
  if(!present("seller"))
    move_object(clone_object("/players/trix/castle/town/monst/newseller"),this_object());

  if(arg) return;
  set_light(1);
  long_desc = 
"  This is the local newspaper shop.  You see magazines of all kinds everywhere\n" +
"around you heaped distractly.  The mess rules.\n";
  short_desc = "Trixtown news shop's";
  dest_dir = ({ "/players/trix/castle/town/2str1n.c","west"});
}
