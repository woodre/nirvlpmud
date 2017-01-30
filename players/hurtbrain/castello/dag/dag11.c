
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A desert" ;
    long_desc = "This is a desert and you think it is neverended\n" +
    "You see something west. Perhaps it is an oasis?\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag14" ,"south" ,
    "/players/hurtbrain/castello/dag/dag12" ,"west",
    "/players/hurtbrain/castello/dag/dag10","east"
    }) ;
    set_light(1) ;
}
