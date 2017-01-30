
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A long road" ;
    long_desc = "You find yourself on a long road. North and south\n" +
    "you can see customs-houses.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag17" ,"south" ,
    "/players/hurtbrain/castello/dag/dag23" ,"north",
    "/players/hurtbrain/castello/dag/dag24", "northwest"
    }) ;
    set_light(1) ;
}
