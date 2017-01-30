
inherit "room/room";
object sshort;
reset(arg){  
        if(!present("shortcake")){
            sshort = clone_object("players/airwoman/MONSTER/sshort");
            move_object(sshort, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="fields room 1";
        long_desc=
        "hmmm... The smell of strawberries.....\n"+
        "A field of strawberries grows here......\n"+
        "OH wow it's Strawberry Shortcake..\n"+ 
        "She's probably 40 yrs old by now...\n"+
        "\n\n";
        dest_dir = ({"players/airwoman/fields/straw1", "north",
                     "players/airwoman/fields/apple1", "west",
                     "players/airwoman/fields/straw3", "south"});
        }
}
