inherit "room/room";

reset(arg) {
    object dancer;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc = "This is the huge stage at the bottom of the EclYpsE, you can see all the disco\n" +
        "dancing at your feet, a giant screen is south of here, showing acid images at\n" +
        "the tempo of the wild techno underground music. You feel alive.\n";
   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid22.c","west",
                  "/players/trix/castle/disco/grid24.c","east"});

   dancer=clone_object("/players/trix/castle/dismonst/dancer");
   move_object(dancer,this_object());
}
