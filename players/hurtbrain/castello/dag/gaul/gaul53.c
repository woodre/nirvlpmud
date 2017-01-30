
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
    "/players/hurtbrain/castello/dag/gaul/gaul52" ,"east" ,
    "/players/hurtbrain/castello/dag/gaul/gaul54" ,"west" , 
    "/players/hurtbrain/castello/dag/gaul/gaul46" ,"southeast" ,
    "/players/hurtbrain/castello/dag/gaul/gaul47" ,"south"
    } ) ;
    obj = clone_object("/players/hurtbrain/castello/dag/gaul/asterix");
    move_object(obj,this_object());
    set_light(1) ;
}
