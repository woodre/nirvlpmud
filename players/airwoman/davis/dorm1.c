inherit "room/room";
object luz;
reset(arg){  
        if(!present("luz")){
           luz=clone_object("players/airwoman/MONSTER/luz");
           move_object(luz,this_object());
           }    
        if(!arg){
        set_light(1);
        short_desc="UCB 2";
        long_desc=
        "ICK!  ROOM 101!!  Your worst nightmore.  (Actually \n"+
        "room 419 in 1992)  And YOU encounter Airwoman's \n"+
        "roommate.  Hopefully she's dead already cause\n"+
        "Airwoman killed her.  I think she tried the burning\n"+
        "bed act..\n\n"+
        "Ashes to ashes...Slime to slime....\n"; 
        dest_dir = ({"players/airwoman/davis/dtown", "east",
                     "players/airwoman/davis/dorm2", "west"});
        }
}
