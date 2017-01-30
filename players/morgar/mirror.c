int i;
string targetloc;

id(str) { return str == "mirror"; }

reset(arg) { if(arg) return; i = 0;
}

long() {
    write("A magic mirror is here.\n");
  if(targetloc)
    if (i == 1) {
        write("Looking into the mirror you see:\n");
        call_other(targetloc,"long");
    }
}

short() { return "A magic mirror"; }

query_value() { return 200; }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("use"); add_verb("use");
    add_action("use"); add_verb("enter");
    add_action("set"); add_verb("set");
#else
  add_action("use", "use");
  add_action("use", "enter");
  add_action("set", "set");
#endif
}

use(arg) {
    if (!id(arg)) {
        return 0;
    } else {
        if (i != 1) {
            write("Mirror has not had a destination set.\n");
            return 1;
        } else {
   if(targetloc) {
            write("You step through the mirror.\n");
            say(call_other(this_player(),"query_name") + " steps into a mirror.\n");
            move_object(this_player(), targetloc);
            say(call_other(this_player(),"query_name") + " steps out of a mirror.\n");
            call_other(this_player(),"look",0);
            return 1;
  }
        }
    }
}

set(arg) {
    if (!arg || arg != "mirror") {
        return 0;
    } else {
        if(call_other(this_player(),"query_level",0) <20) {
            write("Only a wizard may set a mirror!\n");
      return 1;
        } else {
            if (environment(this_object()) != this_player()) {
                return 0;
	    } else {
                write("You set the mirror's destination.\n");
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
