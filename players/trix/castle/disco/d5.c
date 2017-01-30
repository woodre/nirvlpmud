inherit "room/room";
    object woman,man;
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc = "This is a private corner of the restaurant under the EclYpsE, a a couch and a\n"+
               "little table with champagne and raffinate foods are here, the low light makes\n"+
   "the atmosphere softer and puts you in a particular mood...\n";
    short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/d10.c","south"});
    woman=clone_object("/players/trix/castle/dismonst/woman.c");
    move_object(woman,this_object());
    man=clone_object("/players/trix/castle/dismonst/man.c");
    move_object(man,this_object());
    
}
