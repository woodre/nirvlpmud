id(str) { return str == "medkit"; }

reset() {}

long() { write("You have a medkit.\n"); }

short() { return "A medkit"; }

init() {
    add_action("use"); add_verb("use");
    add_action("medkit"); add_verb("medkit");
    add_action("drop_object"); add_verb("drop");
}

use(arg) {
    if (arg=="medkit") {
        medkit();
        return 1;
    } else {
        return 0;
    }
}

medkit(arg) {
    say(call_other(this_player(),"query_name") + " uses medkit.\n");
    write("You use medkit.\n");
    call_other(this_player(),"heal_self",150);
    write("The medkit blows up.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 3750; }

drop_object(str) {
    if (str == "all") {
        drop_object("medkit");
        return 0;
    }
    if (!str || !id(str))
 {
        return 0;
 }
    write("The medkit falls apart.\n");
    say(call_other(this_player(), "query_name") + " watches gloomily as their medkit falls apart.\n");
    destruct(this_object());
    return 1;
}
