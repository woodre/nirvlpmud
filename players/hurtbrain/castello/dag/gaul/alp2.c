
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
"/players/hurtbrain/castello/dag/gaul/alp1" ,"south" , 
    "/players/hurtbrain/castello/dag/gaul/gaul6" ,"down" 
    } ) ;
    set_light(1) ;
}
