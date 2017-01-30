inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
              "You are following the flow of the wast waters through the sewer of Trixtown.\n"+
              "The tunnel goes from east to west, a hole leads northest.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/seg7","west",
                  "/players/trix/castle/quest/seg9","east",
                  "/players/trix/castle/quest/sef9","northeast"
                                                        });
    abc = 0;
    if (!present("rat")) 
     {
      while(abc<7) 
       {
        abc += 1;
        rat=clone_object("players/trix/castle/quest/monst/rat");
        move_object(rat,this_object());
       }
     }
}
realm(){return "NT";}
