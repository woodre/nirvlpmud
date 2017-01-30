
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "The Gaul" ;
    long_desc = "A path in the forest leads somewhere. You see\n" +
    "many strange tree that makes the forest not very safety.\n" +
    "Perhaps you'd better to change way.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/gaul/gaul53" ,"east" ,
    "/players/hurtbrain/castello/dag/gaul/gaul47" ,"southeast" ,
    "/players/hurtbrain/castello/dag/gaul/gaul59" ,"northeast" 
    } ) ;
    set_light(1) ;
}
