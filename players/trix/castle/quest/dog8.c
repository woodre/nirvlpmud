inherit "room/room";
   object orc; 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "This is the cove of a huge orc , skeletons and bones are spreaded everywhere\n"+
              "on the floor, you shiver hoping that your destiny will be better than these\n"+
              "poor fellows' fate.\n";
    short_desc = "Grishnakh's cove";
    dest_dir = ({
                  "/players/trix/castle/quest/dog7","west"
                                                        });
    orc=clone_object("/players/trix/castle/quest/monst/gris");
    move_object(orc,this_object());
}
init(){
 ::init();
   add_action("west","west");
}
west()
{ if(orc) { write("Grishnakh says: Heh Heh Heh, you will have to kill me to get out of here alive.\n"); return 1; }
}
realm(){return "NT";}
