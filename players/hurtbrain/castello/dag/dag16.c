
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A plain" ;
    long_desc = "This is a large open plain. There are two way\n" +
    "from here: east you see the entrance and north you go further\n"+
    "in the realm.\n" ;
     dest_dir = ({
    "/players/hurtbrain/castello/dag/dag15" ,"north",
    "/players/hurtbrain/castello/dag/dag1" ,"east"
    }) ;
    set_light(1) ;
}
