id(str) { return str == "scalpel"; }

reset() {}

long() { write("You have a scalpel.\n"); }

short() { return "A scalpel"; }

init() {
    add_action("use","use");
    add_action("scalpel","scalpel");
    add_action("drop_object","drop");
}

use(arg) {
    if (arg=="scalpel") {
        scalpel();
        return 1;
    } else {
        return 0;
    }
}

scalpel(arg) {
    say(call_other(this_player(),"query_name") + " uses scalpel.\n");
    write("You use scalpel.\n");
    call_other(this_player(),"heal_self",25);
    write("The scalpel rusts and falls apart.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 625; }

drop_object(str) {
    if (str == "all") {
        drop_object("scalpel");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The scalpel rusts and falls apart.\n");
    say(call_other(this_player(), "query_name") + "looks dejected as their scalpel rusts and falls apart.\n");
    destruct(this_object());
    return 1;
}
