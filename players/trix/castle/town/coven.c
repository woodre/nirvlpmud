inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  This is the entrance to Ungweliante's cove, a dark and suffocating place.  A\n"+
"very nasty warmth comes from a room east of here.\n";
  short_desc = "Ungweliante's cove entrance";
  dest_dir = ({ "/players/trix/castle/town/alley1.c","up",
                "/players/trix/castle/town/uncove.c","east"});
}
