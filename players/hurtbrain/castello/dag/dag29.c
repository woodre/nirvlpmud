
inherit "room/room";

reset(arg) {
        int k;
        object obj;
   if(arg) return;
    short_desc = "Emperor's guards" ;
    long_desc = "This is the room of Emperor's guards. This is not\n" +
    "a large room but seems to be enough for the centurions. They\n" +
    "are looking at you suspiciously\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag26" ,"south",
    "/players/hurtbrain/castello/dag/dag32" ,"northwest"
    }) ;
    for (k=0 ; k<2+random(1) ; ++k)  {
    obj = clone_object("/players/hurtbrain/castello/dag/centurion.c");
    move_object(obj,this_object());
    }
    set_light(1) ;
}
