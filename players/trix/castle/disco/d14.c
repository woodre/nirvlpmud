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
    dest_dir = ({ "/players/trix/castle/disco/d13.c","west",
                  "/players/trix/castle/disco/d10.c","northeast",
                  "/players/trix/castle/disco/d9.c","north"});
    for(cont=1;cont<=4;cont++)
     {  if(random(2))
             cosa=clone_object("/players/trix/castle/dismonst/gentleman.c");
        else cosa=clone_object("/players/trix/castle/dismonst/elewoman.c");
        move_object(cosa,this_object());
    }
}
