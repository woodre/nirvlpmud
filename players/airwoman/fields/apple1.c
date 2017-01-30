inherit "room/room";
object johnny;
reset(arg){  
        if(!present("johnny")){
            johnny = clone_object("players/airwoman/MONSTER/johnny");
            move_object(johnny, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="Apple Room 2 - JOHNNY";
        long_desc=
        "IT's JOHNNY APPLESEED and his Machintosh Apples...\n"+
        "Apple trees everywhere....\n\n";
       dest_dir = ({"players/airwoman/fields/straw2", "east"});
        }
}
