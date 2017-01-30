
inherit "/players/molasar/rowan/room/room";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("A path up the mountain");
   set_long("You are on a path that leads up into the mountains.\n"+
            "Far off to the north you can make out some of the\n"+
            "buildings in the town of Rowan. A small trail leads east.\n");
   add_exit("east","/players/molasar/rowan/mtn/path2");
   add_exit("down","/players/molasar/rowan/mroad3");
}

