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
   "  You walk in the northwestern part of the cathedral.  There's a\n"+
   "smell of incense in the air.  Your way is barred to the south and to\n"+
   "the west.\n";
   short_desc = "The left aisle";
   dest_dir = ({ "/players/trix/castle/primo/laisle11.c","north",
         "/players/trix/castle/primo/nave5.c","east"});
}
