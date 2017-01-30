
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(1);
   set_short("The Marketplace of Drakeshore");
   set_long("Your are in what was once the marketplace of Drakeshore.\n"+
"Once the largest trading center in the realms it is now nothing but\n"+
"empty land. Except for the building to the east there is nothing to\n"+
"differentiate the marketplace from regular grasslands. Even though\n"+
"the place is now barren, there is a sense of history and exctasy here.\n"+
"Dealers from all over the realms would gather here to barter and hock\n"+
"their trades. No booths of vendors crowd the area anymore but you can\n"+
"imagine all the people and memories this place has seen.\n");
   add_exit("north","/players/molasar/rowan/drake/sroad1");
   add_exit("east","/players/molasar/rowan/drake/bar");
   call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",1);
}

extra_reset() {
   if(!present("wand_monst")) 
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster2",1);
}
