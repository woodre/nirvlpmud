inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
"  The water flows from north to south along the tunnel, whose eastern wall\n"+
"reveals a hole leading northeast.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see7","north",
                  "/players/trix/castle/quest/see8","northeast",
                  "/players/trix/castle/quest/seg7","south"
                                                        });
    abc = 0;
    if (!present("rat")) 
     {
      while(abc<2)
       {
        abc += 1;
        rat=clone_object("players/trix/castle/quest/monst/rat");
        move_object(rat,this_object());
       }
     }
}
realm(){return "NT";}
