inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are walking along the right aisle of the cathedral.  There're\n"+
"a lot of seats around you.  Wonderful frescoes adorn the eastern wall\n"+
"and great columns are to the west.  The aisle continues to the north\n"+
"and south.\n";
   short_desc = "The right aisle";
    dest_dir = ({ "/players/trix/castle/primo/raisle14.c","north",
                  "/players/trix/castle/primo/raisle12.c","south" });
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
