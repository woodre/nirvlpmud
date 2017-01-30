inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = 
"  You're on Trixtown 1st street.  You can see shops to the sides of this\n"+
"street.  To the south it meets the Main Road.  The street continues to the\n"+
"north.\n";
   short_desc = "Trixtown 1st street";
   dest_dir = ({ "/players/trix/castle/town/1str2n.c","north",
                 "/players/trix/castle/town/mainroad3.c","south",
                 "/players/trix/castle/town/barbers.c","west",
                 "/players/trix/castle/town/drugstore.c","east"});
}
