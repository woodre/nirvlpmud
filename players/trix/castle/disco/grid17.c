inherit "room/room";

reset(arg) {
    object guy,girl,dealer;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in a huge disco lit only by the flashes of some psychedelic\n"+
"lamps.  You feel your legs moving without your will to the rythm of\n"+
"the wildest techno you have ever heard.  People around you dance with\n"+
"closed eyes in what you suppose could be a drug induced trance.  North\n"+
"of here you see some stairs leading down.\n";
   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid12.c","north",
                  "/players/trix/castle/disco/grid16.c","west",
                  "/players/trix/castle/disco/grid18.c","east"});
    cont=0;
    while(cont<random(2))
    {   guy=clone_object("/players/trix/castle/dismonst/guy.c");
        move_object(guy,this_object());
        cont++;
    }
    cont=0;
    while(cont<1+random(2))
    {   girl=clone_object("/players/trix/castle/dismonst/girl.c");
        move_object(girl,this_object());
        cont++;
    }
}
