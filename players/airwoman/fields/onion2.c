inherit "room/room";
object john;
reset(arg){  
        if(!present("john")){
            john = clone_object("players/airwoman/quest/john");
            move_object(john, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="room onion 2 with a JOHN";
        long_desc=
        "Hey look it's ONION John!  WOWsers...\n"+
        "Havent read about him since I was in fifth grade\n"+
        "I think I'll make him really hard to kill! (Hint..hint) \n"; 
        dest_dir = ({"players/airwoman/fields/onion1", "east"});
        }
}
