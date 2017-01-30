inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="UCB 1";
        long_desc=
        "Ever wonder what the streets of Davis are like?\n"+
        "As you look around you see total tranquility.\n"+
        "Tis your typical college town...\n"+
        "The streets are clean and quiet.\n"+
       "...but what appears to be is not the reality...\n";
        dest_dir = ({"players/airwoman/davis/dorm1", "west"});
        }
}
