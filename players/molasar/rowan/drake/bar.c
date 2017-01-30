
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(1);
   set_short("A ruined building");
   set_long("You are in a ruined building.\n"+
"Large beams lay broken and hanging from the roof. A soft whistling\n"+
"sound can be heard as the wind cuts through the holes. Piles of wood\n"+
"and debris cover the floor. You can make out some items which used to be\n"+
"barrels, flasks, and other similiar containers, all decayed and useless,\n"+
"their contents spilled onto the grounds coagulating into a sticky mess.\n");
   add_item("barrels","You find nothing special.");
   add_item("flasks","You find nothing special.");   
   add_exit("west","/players/molasar/rowan/drake/clearing");
   extra_reset();
}

extra_reset() {
   object beer;
   int i;
   if(!present("beer")) {
     i = 0;
     while(i < 5) {
       beer = clone_object("players/molasar/rowan/drake/obj/beer");
       move_object(beer, this_object());
       i++;
     }
   }
}
