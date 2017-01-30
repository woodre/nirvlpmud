
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("A large circular room");
   set_long("You are in a large circular room.\n"+
            "The ceiling increases in height as it moves towards\n"+
            "the center of the room creating a dome-like atmosphere.\n"+
            "Light is provided by torches strung along the walls.\n");
   add_item("torch","The torches are fastened to the wall in iron brackets.");
   add_item("torches",
                    "The torches are fastened to the wall in iron brackets.");
   add_exit("south","/players/molasar/rowan/mtn/eunder2");
   add_exit("west","/players/molasar/rowan/mtn/bar_1");
   add_exit("east","/players/molasar/rowan/mtn/bar_2");
}

