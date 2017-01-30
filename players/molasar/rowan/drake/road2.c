
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("The Main Road of Drakeshore");
   set_long("You are on the main road through Drakeshore.\n"+
   "The road continues on with the dreary sameness of a deserted path. The\n"+
   "only thing to break the monotony is a large hole next to the side of\n"+
   "the road.\n");
   add_item("hole",
   "This hole apparently leads down into the sewer system. The grating that\n"+ 
   "used to cover is long gone. An acrid stench overwhelms your senses.");
   add_exit("east","/players/molasar/rowan/drake/road1");
   add_exit("west","/players/molasar/rowan/drake/road3");
   add_exit("down","/players/molasar/rowan/drake/sewer/sewer1_1");
}

