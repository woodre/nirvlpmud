
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Brutus' room" ;
    long_desc = "The room of Giulius' son, Brutus. Here you can\n" +
    "see some Brutus' busts and a long table. Windows are painted\n" +
    "red and light through them gives you a strange feeling.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag27" ,"south",
    "/players/hurtbrain/castello/dag/dag28" ,"southwest",
    "/players/hurtbrain/castello/dag/dag26" ,"southeast",
    "/players/hurtbrain/castello/dag/dag32" ,"north"
    } ) ;
if(!present("brutus")) {
    obj = clone_object("/players/hurtbrain/castello/dag/brutus.c");
    move_object(obj,this_object());
    }
    set_light(1) ;
}
