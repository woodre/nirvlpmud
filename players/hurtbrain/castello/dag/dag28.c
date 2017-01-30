
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "The palace" ;
    long_desc = "This is the entrance of Emperor's palace. You\n" +
    "can see a staircase leading north into the palace and some\n" +
    "romanesque pillars.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag25" ,"south" ,
    "/players/hurtbrain/castello/dag/dag31" ,"north",
    "/players/hurtbrain/castello/dag/dag30", "northeast"
    }) ;
    set_light(1) ;

}
