inherit "room/room";
object smokie;
 
reset(arg){  
        if(!present("smokie")){
           smokie=clone_object("players/airwoman/MONSTER/smokie");
           move_object(smokie, this_object());
           }
        if(!arg){
        set_light(1);
        short_desc="room 3 north";
        long_desc=
        "The sun is shining brightly and the sky is cloudy white\n"+
        "not because it wants to rain, but due to a resent forest\n"+
        "fire.  The trees are blackened from falling ashes.\n"+
	"\n\n"+
        "Ashes to ashes, dust to dust...(or is that slime to "+
        "slime?)...\n";  
        dest_dir = ({"players/airwoman/CASTLE/rm2n", "south",
                     "players/airwoman/forest/room2", "north",
                     "players/airwoman/fields/straw1", "west"});
        }
}
