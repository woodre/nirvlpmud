inherit "room/room";
 
reset(arg) {
  if(!present("hairdresser"))
    move_object(clone_object("/players/trix/castle/town/monst/hairdresser"),this_object());
   if(arg) return;
   set_light(1);
   long_desc = 
"You're in the local hairdresser's shop.  All of the walls are painted in pink.\n"+
"you can see a soft yellow couch where clients wait for their turn. The colours\n"+
"are so shocking that you need sunglasses!\n";
  short_desc = "Trixtown hairdresser's";
  dest_dir = ({ "/players/trix/castle/town/1str2n.c","west"});
}
