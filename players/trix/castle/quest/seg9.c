inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
"  This is a corner where two tunnels meet and mix their waters, which then\n"+
"flow down through a hole in the floor.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sef9","north",
                  "/players/trix/castle/quest/Eseg8","west"
                                                        });
    abc = 0;
    if (!present("rat")) 
     {
      while(abc<random(4)) /* Was 7, now random(4) -Feldegast */
       {
        abc += 1;
        rat=clone_object("players/trix/castle/quest/monst/rat");
        move_object(rat,this_object());
       }
     }
}
realm(){return "NT";}
