
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("Sewer under Drakeshore");
   set_long("You are in the sewer system under Drakeshore.\n"+
"The smell is so terrible it causes you to gag. After spending a moment\n"+
"to catch your breath you are able to get a good look at the tunnels.\n"+            
"It was evidently carved out of the rock underneath the city. For the\n"+
"most part the walls are still smooth, showing the work was done by expert\n"+
"delvers. A small coating of slime seems to cover exerything. A hole leads\n"+
"up into the main road of Drakeshore.\n");
   add_item("hole", "The hole leads up into the city of Drakeshore.");
   add_exit("north","/players/molasar/rowan/drake/sewer/sewer1_2");
   add_exit("up","/players/molasar/rowan/drake/road2");
}

