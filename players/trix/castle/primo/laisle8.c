inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are walking along the left aisle of the cathedral.  There're\n"+
"a lot of seats around you.  Wonderful frescoes adorn the western wall\n"+
"and there're great columns to the east.  The aisle continues to the\n"+
"north and south.\n";
   short_desc = "The left aisle";
    dest_dir = ({ "/players/trix/castle/primo/laisle9.c","north",
                  "/players/trix/castle/primo/laisle7.c","south" });
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
