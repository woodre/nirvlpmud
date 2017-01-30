
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "Near the palace" ;
    long_desc = "You are near Emperor's palace. North you feel\n" +
    "dangerous and south you feel evil.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag21" ,"south",
    "/players/hurtbrain/castello/dag/dag22" ,"southwest",
    "/players/hurtbrain/castello/dag/dag20" ,"southeast",
    "/players/hurtbrain/castello/dag/dag27" ,"north"
    } ) ;
    set_light(1) ;
}
