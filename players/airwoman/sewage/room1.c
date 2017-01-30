inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="sewage room 1";
        long_desc=
        "You have reached the polluted waterway.\n"+
        "There is an oily film on top.  Seems like\n"+
        "there has been some illegal dumping of toxic waste \n"+ 
        "going on.  Looking down, you see the cause of the \n"+
        "pollution.  A sewage system seems to be dumping \n"+
        "toxic waste.  Why not go down there and take a look?\n";
        dest_dir = ({"players/airwoman/forest/room3", "west",
                     "players/airwoman/sewage/room2", "down"});
        }
}
