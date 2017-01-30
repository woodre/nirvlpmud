

inherit "/players/molasar/rowan/room/room";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("A passage under the mountain");
   set_long("You are in a passage under the mountain.\n"+
            "A tunnel leads off to the west while a ladder goes\n"+
            "up through a hole in the ceiling.\n");
   add_item("ladder","A sturdy ladder goes up through a hole in the\n"+
                     "ceiling near the northern wall.");
   add_item("hole","A sturdy ladder goes up through a hole in the\n"+
                     "ceiling near the northern wall.");
   add_exit("west","/players/molasar/rowan/mtn/under3");
   add_exit("up","/players/molasar/rowan/mtn/under1");
}

