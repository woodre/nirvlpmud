inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="fields room 3";
        long_desc=
        "WOW...blueberries forever...\n"+
        "Do you know blueberries are very very expensive...\n"+
        "NO wonder we never buy them in the store!\n\n\n"; 
        
        dest_dir = ({"players/airwoman/fields/straw4", "east",
                     "players/airwoman/fields/straw2", "north"});
        }
}
