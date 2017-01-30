
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(0);
   set_short("Sewer under Drakeshore");
   set_long("You are in the sewer system under Drakeshore.\n");
   add_exit("north","/players/molasar/rowan/drake/sewer/sewer1_4");
   add_exit("east","/players/molasar/rowan/drake/sewer/sewer1_2");
   extra_reset();
}

extra_reset() {
   object bear;
   int i;
   if(!present("bugbear")) {
     i = 0;
     while(i < 2) {
       bear = clone_object("players/molasar/rowan/monsters/wand/bugbear");
       move_object(bear, this_object());
       i++;
     }
   }
}

