
inherit "/players/molasar/rowan/room/room.c";

realm() { return "NT"; }

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("Dungeon Cell");
   set_long("The cell is cold and damp. Water has leaked through the\n"+
   "the cracks in the stone making the walls slippery and allowing\n"+
   "fungus and molds to grow. A pair of shackles hang from the\n"+
   "western wall.\n");
   add_item("shackles","Theses shackles were made to be fastened to\n"+
   "the prisoners wrists and ankles, virtually imobilizing them.\n"+
   "Due to the leakage of water into the cell they have rusted and\n"+
   "become useless.");
   add_exit("east","/players/molasar/rowan/drake/mansion/dungeon");
}

