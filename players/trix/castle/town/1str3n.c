inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = 
"  You have reached the northern end of 1st street.  You can see shops to the\n"+
"east and to your west.  The street goes south.\n";
   short_desc = "Trixtown 1st street";
   dest_dir = ({ "/players/trix/castle/town/1str2n.c","south",
                 "/players/trix/castle/town/sexshop.c","west",
                 "/players/trix/castle/town/armory.c","east"});
}
