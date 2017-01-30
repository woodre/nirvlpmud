id(str) { return str == "can"; }
reset() {}

long() { write("A can of scotch guard.  Maybe you should spray it.\n"); }

short() { return "A can"; }

init() {
    add_action("use"); add_verb("use");
    add_action("can"); add_verb("spray");
    add_action("drop_object"); add_verb("drop");
}

use(arg) {
    if (arg=="can") {
        can();
        return 1;
    } else {
        return 0;
    }
}

can(arg) {
    say(call_other(this_player(), "query_name") + " sniffs scotch guard.\n");
        write("You spray the scotch guard, and start inhaling and exhaling repeatedly.\nYour mind no longer has control of your body movements. You are high!\n"
);
        write("The can is used up.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 200; }

drop_object(str) {
    if (str == "all") {
        drop_object("can");
        return 0;
    }
    if (!str || !id(str))
        return 0;
        write("The can of Scotch Guard disappears.\n");
        say(call_other(this_player(), "query_name") + " disentegrates a can of scotch guard.\n");
    destruct(this_object());
    return 1;
}
