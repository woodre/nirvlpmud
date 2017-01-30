inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = 
"  You have just entered the front garden on the Trixtown Municipal Infant\n"+
"House, a very peaceful and happy place where Trixtown's inhabitants bring\n"+
"their sons and daughters during their working day.  You see the entrance to\n"+
"the east and the road to the west.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/2str2n.c","west",
                 "/players/trix/castle/town/inhall1.c","east"});
}

