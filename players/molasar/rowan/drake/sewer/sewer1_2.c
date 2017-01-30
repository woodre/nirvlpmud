
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("Sewer under Drakeshore");
   set_long("You are in the sewer system under Drakeshore.\n");
   add_exit("south","/players/molasar/rowan/drake/sewer/sewer1_1");
   add_exit("west","/players/molasar/rowan/drake/sewer/sewer1_3");
}

