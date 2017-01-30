
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(1);
   set_short("Intersection of the Main Road of Drakeshore");
   set_long("You have reached a large intersection.\n"+
"Two additional roads run off to the north and south. Large poles have\n"+   
"been placed around the perimeter of the intersection at regular "+
"intervals.\n"+ 
"Off to the west you can make out a light fog which marks the Silver Sea.\n");
   add_item("poles",
   "These evidently served as some kind of lighting system. The poles\n"+
   "themselves rise up to seven feet in height and are capped with a metal\n"+
   "ring which contains a wick. Near the base of the pole you can see an\n"+
   "opening where oil or some other flammable liquid could be poured.");
   add_exit("north","/players/molasar/rowan/drake/nroad1");
   add_exit("south","/players/molasar/rowan/drake/sroad1");
   add_exit("east","/players/molasar/rowan/drake/road2");
   add_exit("west","/players/molasar/rowan/drake/road4");
   extra_reset();
}

extra_reset() {
   object clock;
   if(!present("clock")) {
     clock = clone_object("players/molasar/rowan/drake/obj/clock");
     move_object(clock, this_object());
   }
}


