inherit "room/room";
 
reset(arg) {
    object woman;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in a little recess in the eastern wall of the cathedral.\n"+
"There's a small altar next to the wall and a statue of a saint stands\n"+
"on it.  People used to kneel and pray in front of it.\n";
   short_desc = "A little recess";
    dest_dir = ({ "/players/trix/castle/primo/raisle14.c", "west"});
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
