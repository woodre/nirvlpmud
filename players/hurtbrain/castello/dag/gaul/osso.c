id(str) { return str == "bone"; }

reset() {}

long() { write("This is a bone. Try to eat it. Perhaps it can heals you.\n"); }

short() { return "A bone"; }

init() {
    add_action("heal","eat");
}

heal(arg) {
        if (arg != "bone"){
                notify_fail("What do you want to eat?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " eats a bone.\n");
    write("You eat the bone. You feel much better!\n");
    call_other(this_player(),"heal_self",100);
    destruct(this_object());
    return 1;
}
get() { return 1; }

drop() { return 0; }
query_weight() { return 0; }

query_value() { return 5000; }
