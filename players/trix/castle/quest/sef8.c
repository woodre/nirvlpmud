inherit "room/room";
reset(arg) {
   object blob;
   if(arg) return;
   set_light(1);
   long_desc =
              "A large room dug in the rock, it doesn't seem to be part of the municipal sewer\n"+
              "a smell of acid permeates the air around you.\n";
    short_desc = "A room in the rock";
    dest_dir = ({
/*  took our ne exit to change quest  -Eurale
                  "/players/trix/castle/quest/see9","northeast",
*/
                  "/players/trix/castle/quest/seg7","southwest"
                                                        });
    blob=clone_object("/players/trix/castle/quest/monst/blob");
    move_object(blob,this_object());
}
realm(){return "NT";}
