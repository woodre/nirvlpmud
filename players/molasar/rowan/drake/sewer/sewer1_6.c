
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(0);
   set_short("Sewer under Drakeshore");
   set_long("You are in the sewer system under Drakeshore.\n"+
"This 'throneroom' appears much like the room you just cam from. Debris\n"+
"covers the entire floor. Crude rugs have been laid down to hide much\n"+
"of the filth.\n");
   add_item("rugs",
   "These were most likely stolen from merchants or travellers who strayed\n"+
   "to close to the bugbear's lair. They have been stained and torn\n"+
   "beyond recognition, making them worthless.");
   add_item("debris","You find nothing special.");
   add_exit("west","/players/molasar/rowan/drake/sewer/sewer1_5");
   extra_reset();
}

extra_reset() {
   object bugbear, mace;
   if(!present("bugbear")) {
     bugbear = clone_object("obj/monster");
     bugbear->set_name("bugbear");
     bugbear->set_alias("king");
     bugbear->set_short("The Bugbear King");
     bugbear->set_long("Although he smells as bad as all bugbears\n"+
                       "you do not doubt he is a skilled fighter.\n");
     bugbear->set_level(14);
     bugbear->set_ac(5);
     bugbear->set_wc(18);
     bugbear->set_hp(200);
     bugbear->set_aggressive(1);
     mace = clone_object("players/molasar/rowan/drake/obj/weak_mace");
     move_object(mace, bugbear); 
     move_object(bugbear, this_object());
   }
}

