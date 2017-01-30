inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
"  The water keeps flowing along the tunnel from west to east.  You notice\n"+
"a hole in the southern wall leads southwest.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see7","west",
                  "/players/trix/castle/quest/see9","east",
                  "/players/trix/castle/quest/sef7","southwest"
                                                        });
    abc = 0;
    if (!present("rat")) 
     {
      while(abc<random(4))
       {
        abc += 1;
        rat=clone_object("players/trix/castle/quest/monst/rat");
        move_object(rat,this_object());
       }
     }
}
realm(){return "NT";}
