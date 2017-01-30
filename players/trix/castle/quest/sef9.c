inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
"  The tunnel leads the dirty water from north to south.  A hole in the\n"+
"western wall leads southwest.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see9","north",
                  "/players/trix/castle/quest/seg9","south",
                  "/players/trix/castle/quest/Eseg8","southwest"
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
