inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="cotton room 3";
        long_desc=
        "In the mist of all this fluffy cotton u look west.\n"+
        "A water tower seems to be standing there.  Perhaps\n"+
        "for irrigations?  You know to water crops and stuff?\n\n";
        dest_dir = ({"players/airwoman/fields/tower1", "west",
                     "players/airwoman/fields/cotton2", "south"});
        }
}
