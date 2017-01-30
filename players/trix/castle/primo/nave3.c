inherit "room/room";
 
reset(arg) {
    object nun;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are walking along the nave of the cathedral.  There are great\n"+
"columns to your left and to your right.  To the north you see\n"+
"something shining far in the darkness.  To the south you can see\n"+
"a beam of light entering from a crack in the portal.\n";
   short_desc = "A long nave";
    dest_dir = ({ "/players/trix/castle/primo/nave4.c","north",
                  "/players/trix/castle/primo/nave2.c", "south"});
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
