
inherit "room/room";

reset(arg) {
        int k;
        object obj;
   if(arg) return;
    short_desc = "Customs" ;
    long_desc = "This is a roman customs-house where everyone\n" +
    "have to pass to go to the Emperor. Some roman soldiers are\n" +
    "inspecting everyone who try to go on.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag20" ,"north",
    "/players/hurtbrain/castello/dag/dag21" ,"northwest",
    "/players/hurtbrain/castello/dag/dag8" ,"south"
    }) ;
    for (k=0 ; k<4+random(4) ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/dag/soldarm.c");
        move_object(obj,this_object());
         }
    set_light(1) ;
}
