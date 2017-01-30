inherit "room/room";
 
reset(arg) {
  if(!present("man"))
    move_object(clone_object("/players/trix/castle/town/monst/manatwork"),this_object());
   if(arg) return;
   set_light(1);
   long_desc = 
"  You're walking along Trixtown 2nd street which runs from south to north.\n"+
"The street seems to end here.  There's a building still under construction\n"+
"north of here.\n";
   short_desc = "Trixtown 2nd street";
   dest_dir = ({ "/players/trix/castle/town/2str2n.c","south"});
}
