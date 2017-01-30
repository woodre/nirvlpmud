
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(1);
   set_short("A ruined building");
   set_long("You are in a ruined building.\n"+
            "There is little left except for some piles of rubble.\n");
   add_item("rubble","You find nothing special.");
   add_exit("east","/players/molasar/rowan/drake/nroad1");
   call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
   call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
   call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
}

extra_reset() {
   if(!present("wand_monst")) {
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",2);
   }  
}
