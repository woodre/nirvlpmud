inherit "room/room";
 
reset(arg) {
    object nun;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  This is the centre of the cathedral.  Your eyes are now accustomed\n"+
"to the low light of this holy place.  To your right and left you can\n"+
"see little old women kneeling and praying to God.  To the south you\n"+
"can barely glimpse the portal you walked into to enter, while to the\n"+
"north you see a yellow reverberation.\n";
   short_desc = "The center of a cathedral";
    dest_dir = ({ "/players/trix/castle/primo/nave5.c","north",
                  "/players/trix/castle/primo/nave3.c","south",
                  "/players/trix/castle/primo/laisle9.c","west",
                  "/players/trix/castle/primo/raisle14.c","east"});
    abc = 0;
    if (!present("nun")) 
     {
      while(abc<7) 
       {
        abc += 1;
        nun=clone_object("players/trix/castle/primonst/nun.c");
        move_object(nun,this_object());
       }
     }
}
