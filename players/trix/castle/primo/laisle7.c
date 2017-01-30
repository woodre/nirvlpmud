inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in the left aisle of the cathedral.  To the east you see\n"+
"the portal you walked in to enter.  The aisle continues to the north.\n"+
"There's a room to the west and you wonder what could be in it.\n";
    short_desc = "The left aisle";
    dest_dir = ({ "/players/trix/castle/primo/laisle8.c","north",
                  "/players/trix/castle/primo/swtower17.c","west",                  "/players/trix/castle/primo/nave2.c","east"});

    abc = 0;
    if (!present("woman")) 
     {
      while(abc<5) 
       {
        abc += 1;
        woman=clone_object("players/trix/castle/primonst/woman.c");
        move_object(woman,this_object());
       }
     }

}
