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
   "  You've reached the north end of the left aisle.  A weird mist of\n"+
   "incense permeates the air around you.  To the west there's a little\n"+
   "room.  An imposing stairway made of marble leads to the altar to the\n"+
   "east.  You notice a narrow passage to the northeast.\n";
   short_desc = "The left aisle";
   dest_dir = ({ "/players/trix/castle/primo/nwroom19.c","west",
         "/players/trix/castle/primo/apse20.c","northeast",
         "/players/trix/castle/primo/altar6.c","east",
         "/players/trix/castle/primo/laisle10.c","south"});
}
