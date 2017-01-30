inherit "room/room";
int westco,southco;
object bstatue,gstatue,borc,gorc;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "Another ordinary room created by the meeting of three galleries dug in the cold\n"+
              "rock under Trixtown.\n";
    short_desc = "An ordinary room";
    dest_dir = ({
                  "/players/trix/castle/quest/dof4","north",
                  "/players/trix/castle/quest/dog3","west",
                  "/players/trix/castle/quest/doh4","south"
                                                        });
    bstatue=clone_object("/players/trix/castle/quest/monst/bstatue");
    move_object(bstatue,this_object());
    gstatue=clone_object("/players/trix/castle/quest/monst/gstatue");
    move_object(gstatue,this_object());
}
init(){
 ::init();
   add_action("south","south");
   add_action("west","west");
}
west()
{ if(bstatue) { write("You try to go west, but suddenly the black statue trembles, falls into pieces\n"+
                      "and a huge black orc comes out of it looking at you menaceously.\n");
                destruct(bstatue);
                borc=clone_object("/players/trix/castle/quest/monst/borc");
                move_object(borc,this_object());
                return 1;
               }
  if(borc) { write("The black orc won't let you pass.\n"); return 1; }                 
}
south()
{ if(gstatue) { write("You try to go south, but suddenly the grey statue trembles, falls into pieces\n"+
                      "and a huge grey orc comes out of it looking at you menaceously.\n");
                destruct(gstatue);
                gorc=clone_object("/players/trix/castle/quest/monst/gorc");
                move_object(gorc,this_object());
                return 1;
               }
  if(gorc) { write("The grey orc won't let you pass.\n"); return 1; }                 
}
realm(){return "NT";}
