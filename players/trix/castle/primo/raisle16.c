inherit "room/room";

reset(arg) {
   object altarboy;
   int abc;
   
   abc = 0;
   if (!present("altarboy"))
      {
      while(abc<5)
      {
         abc += 1;
         altarboy=clone_object("players/trix/castle/primonst/altarboy.c");
         move_object(altarboy,this_object());
       }
   }
   
   if(arg) return;
   set_light(1);
   long_desc=
   "  You've reached the north end of the right aisle.  A weird mist of\n"+
   "incense permeates the air around you.  To the east there's a little\n"+
   "room.  An imposing stairway made of marble leads to the altar to the\n"+
   "west.  You notice a narrow passage to the northwest.\n";
   short_desc = "The right aisle";
   dest_dir = ({ "/players/trix/castle/primo/neroom21.c","east",
         "/players/trix/castle/primo/apse20.c","northwest",
         "/players/trix/castle/primo/altar6.c","west",
         "/players/trix/castle/primo/raisle15.c","south"});
}
