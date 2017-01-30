int i;
string targetloc;

id(str) { return str == "light"; }

reset() { }

long() {
    write("A bright green light is here.\n");
    if (i == 1) {
        write("Looking into the light you see:\n");
        call_other(targetloc,"long");
    }
}

short() { return "A bright green light"; }

query_value() { return 200; }

init() {
    add_action("use","use");
    add_action("use","enter");
    add_action("set","set");
}

use(arg) {
    if (!id(arg)) {
        return 0;
    } else {
        if (i != 1) {
            write("Light has not had a destination set.\n");
            return 1;
        } else {
            write("You step through the light.\n");
            say(call_other(this_player(),"query_name") + " steps into a light.\n");
            move_object(this_player(), targetloc);
            say(call_other(this_player(),"query_name") + " steps out of a light.\n");
            call_other(this_player(),"look",0);
            return 1;
        }
    }
}

set(arg) {
    if (!arg || arg != "light") {
        return 0;
    } else {
        if(call_other(this_player(),"query_level",0) <20) {
            write("Only a wizard may set a light!\n");
        } else {
            if (environment(this_object()) != this_player()) {
                return 0;
	    } else {
                write("You set the light's destination.\n");
                targetloc = environment(this_player());
                i=1;
	    }
        }
    }
    return 1;
}

roomset(arg) {
    targetloc = arg;
    i=1;
}

get() {
    return(call_other(this_player(),"query_level",0) >= 20);
}

query_weight() {
    return 0;
}
