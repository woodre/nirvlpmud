
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Egypt" ;
    long_desc = "You see something strange: the landscape changed\n"+
    "and now you can see some pyramids and the Sphinx in the\n" +
    "distance. Perhaps you arrived in Egypt?\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag13" ,"south" ,
    "/players/hurtbrain/castello/dag/dag11" ,"east"
    } ) ;
        obj = clone_object("/players/hurtbrain/castello/dag/cleo.c");
        move_object(obj,this_object());
        obj = clone_object("/players/hurtbrain/castello/dag/viper.c");
        move_object(obj,this_object());
    set_light(1) ;
}
