inherit "room/room";
object paul;
 
reset(arg){  
        if(!present("paul")){
           paul=clone_object("players/airwoman/MONSTER/paul");
           move_object(paul, this_object());
           }
        if(!arg){
        set_light(1);
        short_desc="forest room 4";
        long_desc=
        "Nice healthy structured trees grow here.\n"+
        "IF only lumber jacks would reforest rather than\n"+
        "chop trees down.  Chopping down trees cause climates\n"+ 
        "to change.\n"+
        "\n\n"+
        "       Save a bag...Save a tree!   \n";
        dest_dir = ({"players/airwoman/forest/room3", "south"});
        }
}
