inherit "room/room";
object rick;
 
reset(arg){  
        if(!present("rick")){
           rick=clone_object("players/airwoman/MONSTER/rick");
           move_object(rick, this_object());
           }
        if(!arg){
        set_light(1);
        short_desc="forest room 3";
        long_desc=
        "The trees are much clearer and healthier here.\n"+
        "The fire did not touch this area however there is trash\n"+
        "everywhere from ignorant campers.  To the east you can\n"+ 
        "see a polluted waterway.\n ";
        dest_dir = ({"players/airwoman/forest/room2", "south",
                     "players/airwoman/forest/room4", "north",
                     "players/airwoman/sewage/room1", "east"});
        }
}
