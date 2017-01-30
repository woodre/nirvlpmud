inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "You are at the beginning of a clean and well lit corridor, there are rooms on\n"+
               "both the sides of it, maybe you should go and visit them.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/ingarden.c","west",
                 "/players/trix/castle/town/inclass1.c","north",
                 "/players/trix/castle/town/inclass2.c","south",
                 "/players/trix/castle/town/inhall2.c","east"});
}

