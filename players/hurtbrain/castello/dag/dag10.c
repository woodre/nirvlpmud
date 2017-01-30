

inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A road" ;
    long_desc = "This is a road junction. You can go everywhere\n" +
    "from here. East you see many strange warriors.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag15" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag11" ,"west" ,
    "/players/hurtbrain/castello/dag/dag9" ,"east",
    "/players/hurtbrain/castello/dag/dag19" ,"north",
    "/players/hurtbrain/castello/dag/dag18" ,"northeast"
    } ) ;
    set_light(1) ;
}
