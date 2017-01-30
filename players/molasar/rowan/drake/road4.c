
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(1);
   set_short("The Main Road of Drakeshore");
   set_long("You are on the main road through Drakeshore.\n"+
   "This is the end of the road to the west. The docks of Drakeshore\n"+
   "lie to the west, the place where ships from all over the realms\n"+
   "made it a point to stop.\n");
   add_exit("east","/players/molasar/rowan/drake/road3");
   add_exit("west","/players/molasar/rowan/drake/dock");
   call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
}

extra_reset() {
   if(!present("wand_monst")) 
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
}
