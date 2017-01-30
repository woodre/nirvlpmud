id(str) { return str == "hypo"; }

reset() {}

long() { write("You have a hypo.\n"); }

short() { return "A hypo"; }

init() {
    add_action("use"); add_verb("use");
    add_action("hypo"); add_verb("hypo");
    add_action("drop_object"); add_verb("drop");
}

use(arg) {
    if (arg=="hypo") {
        hypo();
        return 1;
    } else {
        return 0;
    }
}

hypo(arg) {
    say(call_other(this_player(),"query_name") + " uses hypo.\n");
    write("You use hypo.\n");
    call_other(this_player(),"heal_self",50);
    write("The hypo`s contents run out.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 1250; }

drop_object(str) {
    if (str == "all") {
        drop_object("hypo");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The hypo`s contents run out.\n");
    say(call_other(this_player(), "query_name") + " fumes as their hypo`s contents run out.\n");
    destruct(this_object());
    return 1;
}
