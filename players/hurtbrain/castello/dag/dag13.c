
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A desert" ;
    long_desc = "Landscape is changing a bit. You find yourself\n" +
    "on a expanse of sand, a desert. West you heard distant shouts.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag12" ,"north"  ,
    "/players/hurtbrain/castello/dag/dag14" ,"east"
    }) ;
    set_light(1) ;
}
