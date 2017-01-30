inherit "room/room";

reset(arg) {
   object obj;
   if(arg) return;
    short_desc = "Machine of the time" ;
    long_desc = "This is the entrance of Hurtbrain's castle. All you will\n" +
    "see here sould be a dream...or it could be not. Be careful!\n" +
    "East you see a healing shop, west you see a shop.\n" +
    "This room is full of lever and buttons. There is a sign.\n";
    dest_dir = ({ "/room/plane6" , "out" ,
    "/players/hurtbrain/castello/shop" , "west" ,
    "/players/hurtbrain/castello/bar" , "east",
/* 
    "/players/gorgan/closed/guild/guild_adv_room.c" , "undead"
*/
    }) ;

    obj = clone_object("/players/hurtbrain/castello/machine.c");
    move_object(obj,this_object());
/*
    obj = clone_object("/players/hurtbrain/castello/board.c");
    move_object(obj,this_object());
*/
    set_light(1) ;
    items = ({"sign",
        "This is a normal sign hunged to one of the levers you see.\n" +
        "You see something written on it. Perhaps you can read it"
        });

}

void init() {
        ::init();
        add_action("read","read");
        add_action("press","press");
}

read( str )   {

    if ((!str) || (str != "sign"))  {
        notify_fail("What do you want to read?\n");
        return 0;
    }
    
    write("You can enter three different ages:\n\n" +
    "1 Gangster's days.  <NEWBIE AREA (LEVEL 5 OR LESS)>\n" +
    "2 Middle Ages.  <not available>\n" +
    "3 Roman Empire.  \n" +
    "\nType press <number> to enter it.\n");
    return 1;
}

int press(string number)  {
    
        int res,num;
        object obs,room;
        mapping exits ;
        string *dirs ;
        string long ;
        object *contents ;
        int i ;
        string tmp ;

    if (!number || sscanf(number,"%d",num) != 1) {
        notify_fail("What do you want to press?\n");
        return 0;
    }
    
    say(this_player()->query_name() + " presses one of the many buttons in this room.\n" +
    "The button is labeled `" + num + "`.\n");
    if (num == 1)   {
        if(this_player()->query_level() > 5)  
                write ("The machine seems to work but after a minute stops.\n"+
                "You notice you are too big to be teleported away.\n");
        else  { 
                say("Suddenly "+this_player()->query_name()+ " disappears.\n"); 
        move_object(this_player(), "/players/hurtbrain/castello/gang/gang1");
                }
        return 1;
    }
    if (num == 2)  {
        /* say("Suddenly "+this_player()->query_name()+ " disappears.\n"); */
        /* move_object(this_player(), "/players/hurtbrain/workroom"); */
        write ("The machine don't work...\nTry again.\n");
        return 1;
    }
    if (num == 3)  {
        say("Suddenly "+this_player()->query_name()+ " disappears.\n");
        move_object(this_player(), "/players/hurtbrain/castello/dag/dag1");
    }

    write ("You feel sucked away from the machine.\n" +
    "You find yourself in a new place.\n");
    say("You see " + this_player()->query_name() + " materialize in front of you.\n");
    command("look",this_player());
    return 1;
}

