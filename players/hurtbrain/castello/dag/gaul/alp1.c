
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
   short_desc = "The Alps" ;
   long_desc = "Hey! It's very cold here! You have to find quickly a\n" +
   "way down to the valley or you could freeze yourself here.\n" +
   "You heard some noises in the distance. It seems like someone is calling you.\n" ;
   dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag9" ,"down" , 
    "/players/hurtbrain/castello/dag/gaul/alp2" ,"north" 
    } ) ;
    obj = clone_object("/players/hurtbrain/castello/dag/gaul/hannibal");
    move_object(obj,this_object());
    obj = clone_object("/players/hurtbrain/castello/dag/gaul/elef");
    move_object(obj,this_object());
    set_light(1) ;
}
