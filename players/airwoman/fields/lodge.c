inherit "room/room";
object guru;
reset(arg){  
        if(!present("guru")){
           guru = clone_object("players/airwoman/quest/guru");
           move_object(guru, this_object());
           }       
 
        if(!arg){
        set_light(1);
        short_desc="lake 2";
        long_desc=
        "The lodge is nice and simple...\n"+
        "made of all natural wood.  On the table, you see\n"+
        "el guru meditating on a cigar.\n";
        dest_dir = 
                   ({"players/airwoman/fields/prarie2", "exit"});
        }
}
