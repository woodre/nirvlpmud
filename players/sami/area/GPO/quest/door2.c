init() {
        ::init();
        add_action("open_door","open");
        add_action("close_door", "close");
        add_action("unlock_door", "unlock");
        add_action("cmd_north","north");
}

open_door(arg) {
        if(arg != "door") return;
        if(door_open)
                write("The door is already open dumbass.\n");
        else if(door_locked)
                write("The door is shut and locked.\n");
        else {
                write("The door creaks open.\n");
                set_gate(1);
                call_other("/players/oberon/amber/city/rooms/outside", "set_door", 1);
        }
        return 1;
}

close_door(arg) {
        if(arg != "door") return;
        if(!door_open)
                write("Try again, the doors closed dumbass.\n");
        else {
                write("You slam the door shut.\nYou hear a loud click as it closes.\n");
                set_door(3);
                call_other("/players/oberon/amber/city/rooms/outside", "set_door", 3);
        }
        return 1;
}

unlock_door(arg) {
        if(arg != "door") return;
        if(!door_locked)
                write("The door is already unlocked dumbass.\n");
        else {
                        write("You unlock the door.\n");
                        set_door(2);
                        call_other("/players/oberon/amber/city/rooms/outside", "set_door", 2);
        }
        return 1;
}

cmd_north() {
        if(!door_open) {
                write("The door is closed.\n");
                return 1;
        }
}

set_door(value) {
        if(!value) return;
        switch(value) {
                case 1: door_open=1; door_locked=0; break;
                case 2: door_open=0; door_locked=0; break;
                case 3: door_open=0; door_locked=1; break;
                default: break;
        }
        return 1;
}