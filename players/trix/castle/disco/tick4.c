inherit "room/room";
 
reset(arg) {
  if(!present("seller"))
    move_object(clone_object("/players/trix/castle/dismonst/seller.c"),this_object());
    if(arg) return;
    set_light(1);
   long_desc=
"  You're in the ticket seller's room.  It's a small tidy room with white walls\n"+
"and a black floor.  This room is completely different from the rest of the\n"+
"building.\n";
   short_desc = "A wardrobe";
    dest_dir = ({ "/players/trix/castle/disco/hall3.c","west"});
}
