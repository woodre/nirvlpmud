inherit "room/room";

reset(arg) {
    object guy,girl;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in a huge disco lit only be the flashes of some psychedelic\n"+
"lamps.  You feel your legs moving without your will to the rythm of\n"+
"the wildest techno you have ever heard.  People around you dance with\n"+
"closed eyes in what you suppose could be a drug induced trance.\n";

   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid3.c","west",
                  "/players/trix/castle/disco/grid10.c","southeast"});
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
