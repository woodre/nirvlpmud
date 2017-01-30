inherit "room/room";
object woodsy;
 
reset(arg){  
        if(!present("woodsy")){
           woodsy=clone_object("players/airwoman/MONSTER/woodsy");
           move_object(woodsy, this_object());
           }
        if(!arg){
        set_light(1);
        short_desc="forest room 2";
        long_desc=
        "It seems all to quiet in the wild front.\n"+
        "Not just the fire, but we the people have caused\n"+
        "pollution and chaos killing many endangered species.\n"+ 
        "Seems to me only the brave ones stay here in this dead "+
        "place \n"+
        "\n\n"+
        "Give a hoot!  Don't pollute!\n";
        dest_dir = ({"players/airwoman/forest/room1", "south",
                     "players/airwoman/forest/room3", "north"});
        }
}
