id(str) { return str == "scanner"; }

reset() {}

long() { write("You have a scanner.\n"); }

short() { return "A scanner"; }

init() {
    add_action("use","use");
    add_action("scanner","scanner");
    add_action("drop_object","drop");
}

use(arg) {
    if (arg=="scanner") {
        scanner();
        return 1;
    } else {
        return 0;
    }
}

scanner(arg) {
    say(call_other(this_player(),"query_name") + " uses scanner.\n");
    write("You use scanner.\n");
    call_other(this_player(),"heal_self",100);
    write("The scanner malfunctions.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 2500; }

drop_object(str) {
    if (str == "all") {
        drop_object("scanner");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The scanner malfunctions.\n");
    say(call_other(this_player(), "query_name") + " mourns as their scanner malfunctions.\n");
    destruct(this_object());
    return 1;
}
