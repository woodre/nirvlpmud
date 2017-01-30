
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A hallway" ;
    long_desc = "This is simply an hallway. South you many strange men.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag9" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag10" ,"southwest",
    "/players/hurtbrain/castello/dag/dag8" ,"southeast",
    "/players/hurtbrain/castello/dag/dag21" ,"north"
    }) ;
    set_light(1) ;
}
