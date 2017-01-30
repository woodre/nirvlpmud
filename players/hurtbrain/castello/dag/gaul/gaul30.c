
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
    "/players/hurtbrain/castello/dag/gaul/gaul25" ,"southwest" , 
    "/players/hurtbrain/castello/dag/gaul/gaul36" ,"northwest" , 
    "/players/hurtbrain/castello/dag/gaul/gaul24" ,"southeast" ,
    "/players/hurtbrain/castello/dag/gaul/gaul35" ,"northeast" 
    } ) ;
    obj = clone_object("/players/hurtbrain/castello/dag/gaul/bard");
    move_object(obj,this_object());
    set_light(1) ;
}
