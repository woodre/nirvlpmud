inherit "room/room";
 
reset(arg) {
    object altarboy;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc = "You walk in the northwestern part of the cathedral . there's a smell of incense\n" +
        "in the air , your way is barred to the south and to the west.\n";
   short_desc = "The left aisle";
    dest_dir = ({ "/players/trix/castle/primo/laisle11.c","north",
                  "/players/trix/castle/primo/nave5.c","east"});

    abc = 0;
    if (!present("altarboy")) 
     {
      while(abc<5) 
       {
        abc += 1;
        altarboy=clone_object("players/trix/castle/primonst/altarboy.c");
        move_object(altarboy,this_object());
       }
     }
}
