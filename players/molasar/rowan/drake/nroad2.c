
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("You are on the northern road of Drakeshore");
   set_long("You are on the northern road of Drakeshore.\n"+
"This section of the town seems to have escaped the sacking almost\n"+ 
"completely. Your attention is immediately drawn to a Mansion which\n"+
"stands prominently at the end of the road. Its perfect condition lends\n"+ 
"a macabre feel to the place. Large cast iron gates have been cast open\n"+
"allowing entrance to the place. Next to the gates is a small bronze "+
"plaque.\n");
   add_item("plaque","Engraved in large letters:\n"+
            "       Drakeshore Manse, Home of the Governor of Drakeshore.");
   add_exit("north","/players/molasar/rowan/drake/mansion/path");
   add_exit("south","/players/molasar/rowan/drake/nroad1");
}

