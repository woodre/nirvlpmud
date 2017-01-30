inherit "room/room";
int westco,southco;
object bstatue,gstatue,borc,gorc;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A large room where three tunnels meet. The ceiling is high and covered with\n"+
              "fosforescent musk.\n";
    short_desc = "A high ceiling room";
    dest_dir = ({
                  "/players/trix/castle/quest/dod6","northeast",
                  "/players/trix/castle/quest/doe6","east",
                  "/players/trix/castle/quest/dof5","south"
                                                        });

    bstatue=clone_object("/players/trix/castle/quest/monst/bstatue");
    move_object(bstatue,this_object());
    gstatue=clone_object("/players/trix/castle/quest/monst/gstatue");
    move_object(gstatue,this_object());
}
init(){
 ::init();
   add_action("northeast","northeast");
   add_action("east","east");
}
northeast()
{ if(bstatue) { write("You try to go northeast, but suddenly the black statue trembles, falls into\n"+
                      "into and a huge black orc comes out of it looking at you menaceously.\n");
                destruct(bstatue);
                borc=clone_object("/players/trix/castle/quest/monst/borc");
                move_object(borc,this_object());
                return 1;
               }
  if(borc) { write("The black orc won't let you pass.\n"); return 1; }                 
}
east()
{ if(gstatue) { write("You try to go east, but suddenly the grey statue trembles, falls into pieces\n"+
                      "and a huge grey orc comes out of it looking at you menaceously.\n");
                destruct(gstatue);
                gorc=clone_object("/players/trix/castle/quest/monst/gorc");
                move_object(gorc,this_object());
                return 1;
               }
  if(gorc) { write("The grey orc won't let you pass.\n"); return 1; }                 
}
realm(){return "NT";}
