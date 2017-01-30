
inherit "room/room";

reset(arg) {
        object obj;
   if(arg) return;
    short_desc = "A arena" ;
    long_desc = "You enter the arena. This is a dusty place.\n" +
    "You see some men fighting each other. The people up the\n" +
    "tiers is shouting and screaming. You see also some roman\n" +
    "tribuns looking at the show.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag11" ,"north",
    "/players/hurtbrain/castello/dag/dag13" ,"west",
    "/players/hurtbrain/castello/dag/dag15" ,"east"
    }) ;
        obj = clone_object("/players/hurtbrain/castello/dag/gladglad.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/gladhelm.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/gladtrid.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/gladbuck.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/gladnet.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/lion.c");
        move_object(obj,this_object());
    set_light(1) ;
}
