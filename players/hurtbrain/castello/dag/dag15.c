
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A plain" ;
    long_desc = "As you enter the room you hear distant shouts\n" +
    "coming from west. This is a dusty plain. There is nothing\n" +
    "interesting in here.\n" ;
     dest_dir = ({
    "/players/hurtbrain/castello/dag/dag10" ,"north",
    "/players/hurtbrain/castello/dag/dag14" ,"west",
    "/players/hurtbrain/castello/dag/dag16" ,"south"
    }) ;
    set_light(1) ;
}
