inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="Onion room 1";
        long_desc=
        "Onions forever...\n"+
        "A field full of ripe onions...\n"+
        "Onions tastes best with hamburgers...\n\n"; 
        dest_dir = ({"players/airwoman/fields/onion2", "west",
                     "players/airwoman/fields/cabbage2", "north"});
        }
}
