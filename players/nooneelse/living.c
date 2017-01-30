int num;
string notes;
init() {
        add_action("kitchen", "kitchen");
        add_action("playroom", "playroom");
        add_action("bedroom", "bedroom");
        add_action("church", "church");
        add_action("look", "l");
        add_action("look", "look");
        add_action("note", "note");
        add_action("read", "read");
}
reset(arg) {
        set_light(1);
        num = 0;
        notes = allocate(10);
}
short() {
        return "The Living Room";
}
long() {
        write("This is the living room. There is a large L-shaped couch\n");
        write("against one of the walls that looks very comfortable, along\n");
        write("with a coffee table in the middle of the room.\n");
        write("Four exits:  kitchen  playroom  bedroom  church.\n");
        return 1;
}
note(st) {
        notes[num] = st + "\n";
        num = num + 1;        
        write("Ok, message saved :)\n");
        say(this_player()->query_name() + " writes a note.\n");
        return 1;
}
read(not) {
        int i;
        if(!not || not != "notes") return 0;
        write(num + " notes written.\n");
        if(num == 0) {
                write("Done.\n");
                return 1;
        } else {
                for(i = 0; i <= 10; i++) {
                        write(notes[i] + "\n");
                }
                write("Done.\n");
                return 1;
        }
}       
kitchen() {
        call_other(this_player(), "move_player", "kitchen#players/wizardchild/house/kitchen");
        return 1;
}
playroom() {
        call_other(this_player(), "move_player", "playroom#players/wizardchild/house/playroom");
        return 1;
}
bedroom() {
        call_other(this_player(), "move_player", "bedroom#players/wizardchild/house/bedroom");
        return 1;
}
church() {
        call_other(this_player(), "move_player", "church#room/church");
        return 1;
}
look(st) {
        if(!st) {
                return 0;
        }
        if(st == "at couch") {
                write("A nice comfortable couch. You look at it and feel\n");
                write("like lying down on it.\n");
                return 1;
        }
        if(st == "at coffee table" || st == "at table") {     
                write("Apparently, this coffee table has the guest book on it.\n");
                write("Maybe you should 'note <str>' to leave a comment about\n");
                write("this house.\n");
       return 1;
        } else {
                return 0;
        }
}
