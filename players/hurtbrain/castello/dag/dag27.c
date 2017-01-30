
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Erode's room" ;
    long_desc = "Abloody room where you see many corpse of \n" +
    "killed kids, everywhere. Who is this terrible man slaughtering\n" +
    "poor little innocents without reasons?\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag24" ,"south",
    "/players/hurtbrain/castello/dag/dag25" ,"southwest",
    "/players/hurtbrain/castello/dag/dag23" ,"southeast",
    "/players/hurtbrain/castello/dag/dag30" ,"north"
    } ) ;
if(!present("erode")) {
    obj = clone_object("/players/hurtbrain/castello/dag/erode.c");
    move_object(obj,this_object());
    }
    set_light(1) ;
}
