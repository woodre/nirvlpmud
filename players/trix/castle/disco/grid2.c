inherit "room/room";

reset(arg) {
    object guy,girl;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc = "You are in a huge disco lit only by the flashes of some psychedelic lamps , you\n" +
        "feel your legs moving without your will at the rythm of the wildest techno you\n" +
        "have ever heard , people around you dance with closed eyes in what you suppose\n" +
      "could be a drug trance.\n";
   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid6.c","southwest",
                  "/players/trix/castle/disco/grid3.c","east"});
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
