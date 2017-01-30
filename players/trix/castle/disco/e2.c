inherit "room/room";

reset(arg) {
    object boy,babe;
    if(arg) return;
    set_light(1);
   long_desc = "A round recess in the western wall of the disco , a round couch fills the space\n" +
               "it seems cosy for two , *wink* *wink* *wink*.\n";
   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid15.c","west"});
   boy=clone_object("/players/trix/castle/dismonst/boy.c");
   move_object(boy,this_object());
   babe=clone_object("/players/trix/castle/dismonst/babe.c");
   move_object(babe,this_object());
}
