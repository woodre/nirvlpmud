id(str) { return str == "carrot"; }

init() { add_action("eat","eat"); }

long() { write("A delicious-looking carrot.\n"); }

short(){return "A carrot"; }

query_value() { return 200; }

get() {
    return 1;
}

query_weight() {
    return 1;
}

query_name() {
   return "carrot";
}

eat() {
    write("You eat the carrot, and are satiated somewhat.\n");
    call_other(this_player(), "heal_self", 40);
    destruct(this_object());
    return 1;
}

/*
get() {
    write("The acid burns you a little, but you take the globule.\n");
    call_other(this_player(), "heal_self", -15);
    return 1;
}
*/
