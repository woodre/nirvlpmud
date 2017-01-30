inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc =  "A road" ;
    long_desc =  "This is a road junction. You can go everywhere\n" +
    "from here. West you see some strange men.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag3" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag9" ,"west",
    "/players/hurtbrain/castello/dag/dag7" ,"east",
    "/players/hurtbrain/castello/dag/dag17" ,"north", 
    "/players/hurtbrain/castello/dag/dag18","northwest"
    } ) ;
    set_light(1) ;
}


