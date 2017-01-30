
inherit "room/room";

reset(arg) {
    object obj;
   if(arg) return;
    short_desc = "Uranium room" ;
    long_desc = "This room is completely white and there are some symbols on the walls:\n\n"+
"                    #######\n"+
"                 ###_______###\n"+
"               ##  / _____ \\  ##\n"+
"              #     / ___ \\     #\n"+
"             #       / _ \\       #\n"+
"            #         / \\         #\n"+
"            #  / / / /   \\ \\ \\ \\  #\n"+
"            #  \\ \\ \\ \\_ _/ / / /  #\n"+
"             #  \\ \\ \\_   _/ / /  #\n"+
"              #  \\ \\_     _/ /  #\n"+
"               ## \\_       _/ ##\n"+
"                 ###       ###\n"+
"                    #######\n\n"+
"There is an exit that goes to your car!\n";
   dest_dir =
   ({
    "/players/hurtbrain/quest/car","exit",
    "/players/hurtbrain/quest/cove_chief","west",
    } ) ;
    set_light(1) ;
    obj=clone_object("/players/hurtbrain/quest/uranium.c");
    move_object(obj,this_object());
}
realm(){return "NT";}
