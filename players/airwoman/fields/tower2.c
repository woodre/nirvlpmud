inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="tower 2";
        long_desc=
        "You are in the middle of going up the water tower.\n"+
        "Looking up you see a shadow of a person.\n"+
        "Perhaps it's your imagination?\n\n";
        dest_dir = ({"players/airwoman/fields/tower3", "up",
                     "players/airwoman/fields/tower1", "down"});
        }
}
