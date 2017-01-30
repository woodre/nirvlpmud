
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) 
     return;
   set_light(1);
   set_short("Docks of Drakeshore");
   set_long("Recent rainstorms have caused the water of the Silver Sea\n"+
   "to rise making the docs inaccessible.\n");
   add_exit("east","/players/molasar/rowan/drake/road4");
}

