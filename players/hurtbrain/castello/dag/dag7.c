
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A house" ;
    long_desc = "This is the entrance of a beautiful house. Staircase\n" +
    "leading east have been covered with long red walking drapes.\n" +
    "You see something further east.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag4" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag8" ,"west",
    "/players/hurtbrain/castello/dag/dag6" ,"east"
   }) ;
    set_light(1) ;
}
