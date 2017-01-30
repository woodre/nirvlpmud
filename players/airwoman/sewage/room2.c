inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="sewage room 2";
        long_desc=
        "There is a putrid smell in the air.\n"+
        "Whatever gave you the idea of coming here\n"+
        "here in the first place? It is very dark and musty.\n"+ 
        "You here some ribbitting coming from the east\n";
        dest_dir = ({"players/airwoman/sewage/room3", "east",
                     "players/airwoman/sewage/room1", "up"});
        }
}
