inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="cotton room 1";
        long_desc=
        "You notice a cotton plantation further east...\n"+
        "People are picking cotton.  That's weird..\n"+
        "I thought Eli Whitney had already invented the cotton "+
        "gin..\n"; 
        dest_dir = ({"players/airwoman/fields/cabbage1", "west",
                     "players/airwoman/fields/straw1", "south",
                     "players/airwoman/fields/cotton2", "east"});
        }
}
