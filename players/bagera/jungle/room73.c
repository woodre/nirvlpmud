inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Deep jungle");
  long_desc=
    "You have ventured into the deep jungle. The light barely\n"+
    "gets through the trees here. It is dim and erie. You here\n"+
    "the different sounds of wild animals all around you. Then you.\n"+
    "spot a huge tiger stalking around, growling to himself,\n"+
    "as if looking for something. As he roars you can see\n"+
    "his long three inch teeth that he picks with his four\n"+
    "inch long claws. His eyes dart toward you and he crouches\n"+
    "down ready to pounce.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room72.c", "west"
   });
 }
