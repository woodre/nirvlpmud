inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "You reached the dead end of the corridor, the light is low and there is dust\n"+
               "everywhere, it doesn't seem a good place to keep children in.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/inhall5.c","west"});
}

