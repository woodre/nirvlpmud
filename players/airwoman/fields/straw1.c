inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="fields room 1";
        long_desc=
        "You look all around you.  You see vast fields for a far...\n"+
        "The sun seems to beat down on you hard...\n"+
        "You seem to smell a wiff of strawberries...\n"+ 
        "coming from the south...\n";
        dest_dir = ({"players/airwoman/forest/room1", "east",
                     "players/airwoman/fields/straw2", "south",
		     "players/airwoman/fields/lake1", "west",
                     "players/airwoman/fields/cotton1", "north"});
        }
}
