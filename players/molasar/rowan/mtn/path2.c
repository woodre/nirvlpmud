
inherit "/players/molasar/rowan/room/room";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("A clearing at the top of the mountain");
   set_long("You are at a clearing on the top of the mountain.\n"+
            "A trail leads to the west, while you can make out\n"+
            "a small alcove in the rocks to the east.\n");
   add_exit("east","/players/molasar/rowan/mtn/alcove");
   add_exit("west","/players/molasar/rowan/mtn/path1");
}

