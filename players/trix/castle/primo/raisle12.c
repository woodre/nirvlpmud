inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in the right aisle of the cathedral.  To the west you see\n"+
"the portal you walked into to enter.  The aisle continues to the\n"+
"north.  There's a room to the east.  Maybe you should see what's in\n"+
"it.\n";
   short_desc = "The right aisle";
    dest_dir = ({ "/players/trix/castle/primo/raisle13.c","north",
                  "/players/trix/castle/primo/seorgan23.c","east",
                  "/players/trix/castle/primo/nave2.c","west"});
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
