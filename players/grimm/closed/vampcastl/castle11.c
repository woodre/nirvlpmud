#include "/players/grimm/header"
inherit "room/room";
realm() { return "NT"; }
reset(arg) {
  if(arg) return;

  short_desc="Castle Hall";
  long_desc="The music gets louder as you continue to walk east.  You can't\n"+
            "make out what is in the room, but from here it seems to be a\n"+
            "large ballroom.\n";
  dest_dir=({DIR5(castle6),"west",
             DIR5(castle12),"east"});
  set_light(1);
}
