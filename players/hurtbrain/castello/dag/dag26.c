
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "The palace" ;
    long_desc = "This is the entrance of Emperor's palace. You\n" +
    "can see a staircase leading north into the palace and some\n" +
    "romanesque pillars.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag23" ,"south" ,
    "/players/hurtbrain/castello/dag/dag29" ,"north",
    "/players/hurtbrain/castello/dag/dag30", "northwest"
    }) ;
    set_light(1) ;

}
