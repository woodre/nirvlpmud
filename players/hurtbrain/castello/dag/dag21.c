
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Nero's room" ;
    long_desc = "As you enter this room you feel hot. A great evil\n" +
    "is here! You see all the houses catched fire and people\n" +
    "running away.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag18" ,"south",
    "/players/hurtbrain/castello/dag/dag19" ,"southwest",
    "/players/hurtbrain/castello/dag/dag17" ,"southeast",
    "/players/hurtbrain/castello/dag/dag24" ,"north"
    } ) ;
if(!present("nero")) {
    obj = clone_object("/players/hurtbrain/castello/dag/nerone.c");
    move_object(obj,this_object());
    }
    set_light(1) ;
}
