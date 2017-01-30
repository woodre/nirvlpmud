
inherit "/players/molasar/rowan/room/room";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("An alcove");
   set_long("You are in a small alcove in the side of the mountain.\n"+
            "It appears to be man-made, or at least made by artificial\n"+
            "means.  A small tunnel leads off from here.\n"+
            "The exit lies to the west.\n");
   add_exit("west","/players/molasar/rowan/mtn/path2");
   add_exit("southeast","/players/molasar/rowan/mtn/under1");
}

