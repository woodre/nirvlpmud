
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Giulius' room" ;
    long_desc = "This is the private room of the Emperor. You\n" +
    "see many statues and busts representing an elderly but\n" +
    "very powerful man\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag30" ,"south",
    "/players/hurtbrain/castello/dag/dag31" ,"southwest",
    "/players/hurtbrain/castello/dag/dag29" ,"southeast"
    } ) ;
if(!present("caesar")) {
    obj = clone_object("/players/hurtbrain/castello/dag/cesare.c");
    move_object(obj,this_object());
    }
    set_light(1) ;
}
