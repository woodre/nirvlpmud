inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A master bedroom";
  long_desc=
"This is the seldom used sleeping place of Feldegast.  In the middle\n"+
"of the room is an antique four-poster bed.  A bay window lets light\n"+
"into the room.  A plush carpet covers the floor.  This room reeks\n"+
"of comfort and decadence.\n";
  items=({
    "bed","A comfortable bed with blue sheets",
    "window","You can see all of Nirvana from here",
    "carpet","It is a comfortable light blue"
  });
  dest_dir=({
    "/players/feldegast/closed/tower/tower2","east"
  });
}

