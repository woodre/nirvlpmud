inherit "room/room";

reset(arg) {
    object cosa;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc = "You're walking among the tables of the restaurant, the clients eat and chat in\n" +
               "a relaxed elegance that seems to be the feature of the restaurant together with\n" +
               "the refined wines and foods.\n";
   short_desc = "EclYpsE's Restaurant";
    dest_dir = ({ "/players/trix/castle/disco/d5.c","north",
                  "/players/trix/castle/disco/d4.c","northwest",
                  "/players/trix/castle/disco/d14.c","southwest",
                  "/players/trix/castle/disco/d15.c","south"});
    for(cont=1;cont<=4;cont++)
     {  if(random(2))
             cosa=clone_object("/players/trix/castle/dismonst/gentleman.c");
        else cosa=clone_object("/players/trix/castle/dismonst/elewoman.c");
        move_object(cosa,this_object());
    }
}
