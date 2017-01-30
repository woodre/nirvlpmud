
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
    "/players/hurtbrain/castello/dag/gaul/gaul9" ,"west" , 
    "/players/hurtbrain/castello/dag/gaul/gaul7" ,"east" ,
    "/players/hurtbrain/castello/dag/gaul/gaul1" ,"southwest" , 
    "/players/hurtbrain/castello/dag/gaul/gaul14" ,"northeast" 
    } ) ;
    set_light(1) ;
}
