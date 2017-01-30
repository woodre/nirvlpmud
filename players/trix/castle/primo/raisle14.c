inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are walking along the right aisle of the cathedral.  There're\n"+
"seats all around you.  There's a recess in the wall to the east.  A\n"+
"little parapet is placed longitiduinally to the aisle and you see a\n"+
"passage west of here.\n";
   short_desc = "The right aisle";
    dest_dir = ({ "/players/trix/castle/primo/eroom22.c","east",
                  "/players/trix/castle/primo/nave4.c","west",
                  "/players/trix/castle/primo/raisle13.c","south"});
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
