inherit "room/room";
object hatch;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A circular room with smooth round walls, the light here is very bright, you can\n"+
              "see no shadows, there's a hatch in the center of the room.\n";
    short_desc = "A brightly light room";
    dest_dir = ({
                  "/players/trix/castle/quest/seb3","southwest",
                  "/players/trix/castle/quest/sea5","east"
                                                        });
    items = ({ "hole", "An octogonal hole engraved in the brass hatch" });
    hatch=clone_object("/players/trix/castle/quest/monst/hatch");
    move_object(hatch,this_object());

}
realm(){return "NT";}
