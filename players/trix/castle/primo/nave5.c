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
   "  You've reached the end of the nave.  The portal is far to the\n"+
   "south.  Turning your head north, you notice a huge and wonderful\n"+
   "altar made of hold, inlaid with silver.  A high parapet stops your\n"+
   "way to the north, but you see open spaces to the east and to the\n"+
   "west.\n";
   short_desc = "A long nave";
   dest_dir = ({ "/players/trix/castle/primo/nave4.c","south",
         "/players/trix/castle/primo/laisle10.c","west",
         "/players/trix/castle/primo/raisle15.c","east"});
}
