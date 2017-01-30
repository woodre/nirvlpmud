
inherit "/players/molasar/rowan/room/room.c";

realm() { return "NT"; }

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("Great Hall");
   set_long("The Great Hall of the Governor's Manse is really nothing\n"+
   "more than a large empty room. An ancient rug creates a path from\n"+
   "the foyer to the audience chamber to the north. The only other\n"+
   "adornments in the room are small tables set along the walls at\n"+
   "varying intervals.\n");
   add_item("rug","An exquisitely crafted rug of unknown design.\n"+
   "It appears to be tacked down to avoid its being moved by the large\n"+
   "number of shuffling feet which used to roam the mansion.");
   add_item("tables","Small wooden tables bare of any items.");
   add_exit("north","/players/molasar/rowan/drake/mansion/mt_chmbr");
   add_exit("south","/players/molasar/rowan/drake/mansion/foyer");
   add_exit("east","/players/molasar/rowan/drake/mansion/e_hall");
   add_exit("west","/players/molasar/rowan/drake/mansion/w_hall");
}

