inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="cabbage room 1";
        long_desc=
        "A cabbage farm...\n"+
        "Cabbages forever...All these cabbages surrounding\n"+
        "you.\n\n"; 
        
        dest_dir = ({"players/airwoman/fields/cabbage2", "west",
                     "players/airwoman/fields/cotton1", "east"});
        }
}
