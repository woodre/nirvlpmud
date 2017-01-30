inherit "room/room";
reset(arg) {
    if(arg) return;
  if(!present("woman"))
    move_object(clone_object("/players/trix/castle/dismonst/woman.c"),this_object());
  if(!present("man"))
    move_object(clone_object("/players/trix/castle/dismonst/man.c"),this_object());
    set_light(1);
   long_desc=
"  This is a private corner of the restaurant under the EclYpsE.  A couch and a\n"+
"little table with champagne and raffinate foods are here.  The low light makes\n"+
"the atmosphere softer and puts you in a particular mood...\n";
    short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/d6.c","south"});
    
}
