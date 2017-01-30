
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A house" ;
    long_desc = "This is the entrance of a beautiful house. Staircase\n" +
    "leading north have been covered with long red walking drapes.\n" +
    "You see something further north.\n" ;
    dest_dir =
   ({
    "/players/hurtbrain/castello/dag/dag6" ,"north" ,
    "/players/hurtbrain/castello/dag/dag4", "west"
   }) ;
    set_light(1) ;
}
