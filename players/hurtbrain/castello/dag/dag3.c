
inherit "room/room";


reset(arg) {
   if(arg) return;
    short_desc = "A plain" ;
    long_desc = "As you enter the room you hear distant shouts\n" +
    "coming from east. This is a dusty plain. There is nothing\n" +
    "interesting in here.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag8" ,"north"  ,
    "/players/hurtbrain/castello/dag/dag2" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag4" ,"east"
    }) ;
    set_light(1) ;
}
